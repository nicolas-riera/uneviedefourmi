#include <iostream>
#include "ants.hpp"

short Ant::counter = 0;

Ant::Ant(){
    this->antId = counter;
    counter++;
};

Ant::~Ant(){};

Room::Room(short size){
    this->size = size;
    std::vector<Ant*> newAnts;
    this->ants = newAnts;
};

void Room::addToAdjacencies(Room* room){
    this->adjacencies.push_back(room);
};

void Room::addAnt(Ant* ant){
    this->ants.push_back(ant);
};

Ant Room::extractAnt(){
    // To complete
    //check if room is empty for safety
    if (ants.empty())
    {
        throw std::out_of_range("Error : empty room");
    }
    //find last element of vector 
    Ant* extractedAnt {ants.back()};
    //delete last element
    ants.pop_back();
    //return the value of the extracted ant
    return *extractedAnt;
};

Room::~Room(){
    for (Ant* ant : this->ants) {
        delete ant;
    }
};

Anthill::Anthill(){};

Anthill::~Anthill(){
    for (Room* room : this->rooms) {
        delete room; 
    }
};

void Anthill::initAnthill(std::vector<std::vector<short>> roomLinking, std::vector<short> roomSizes, short antAmount){

    this->antAmount = antAmount;

    this->roomLinking = roomLinking;
    this->roomSizes = roomSizes;

    this->rooms.reserve(roomSizes.size());

    // Room creation
    for (size_t i = 0; i < roomSizes.size(); i++)
    {
        Room* room;
        if (i == 0) {
            // V room
            room = new Room(roomSizes[i]);
            // Ants creation
            room->ants.reserve(antAmount);
            for (size_t j = 0; j < antAmount; j++)
            {
                Ant* ant = new Ant();
                room->addAnt(ant);
            }
        } else if (i == roomSizes.size()-1) {
            // D room
            room = new Room(roomSizes[i]);
        } else {
            // regular rooms
            room = new Room(roomSizes[i]);
        }
        this->rooms.push_back(room);
    }

    // Room adjacencies
    for (size_t i = 0; i < this->rooms.size(); i++)
    {
        for (size_t j = 0; j < this->roomLinking[i].size(); j++)
        {
            if (this->roomLinking[i][j] == 1)
            {
                this->rooms[i]->addToAdjacencies(this->rooms[j]);
                
                this->rooms[j]->addToAdjacencies(this->rooms[i]);
            }
        }
    }
    
    this->printDebug();
    
};

void Anthill::run(){
    // To complete
};

// Debugging only
void Anthill::printDebug() {
    for (size_t i = 0; i < this->rooms.size(); i++) {
        
        std::string roomName;
        if (i == 0) roomName = "V";
        else if (i == this->rooms.size() - 1) roomName = "D";
        else roomName = "S" + std::to_string(i);

        std::cout << "Index [" << i << "] (" << roomName << ") : "
                  << "Max Size: " << this->roomSizes[i]
                  << " | Ants: ";
        
        if (i == 0) {
            for (short j = 0; j < this->antAmount; j++) {
                std::cout << j << " ";
            }
        } else {
            std::cout << "None";
        }

        std::cout << " | Adjacencies: ";
        if (this->rooms[i]->adjacencies.empty()) {
            std::cout << "None";
        } else {
            for (size_t n = 0; n < this->rooms[i]->adjacencies.size(); n++) {
                for (size_t k = 0; k < this->rooms.size(); k++) {
                    if (this->rooms[i]->adjacencies[n] == this->rooms[k]) {
                        if (k == 0) std::cout << "V ";
                        else if (k == this->rooms.size() - 1) std::cout << "D ";
                        else std::cout << "S" << k << " ";
                        break;
                    }
                }
            }
        }

        std::cout << std::endl;
    }
}