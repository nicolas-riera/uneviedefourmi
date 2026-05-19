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

void Room::addToNexts(Room* room){
    this->nexts.push_back(room);
};

void Room::addToPrevs(Room* room){
    this->prevs.push_back(room);
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

Room::~Room(){};

Anthill::Anthill(){};

Anthill::~Anthill(){};

void Anthill::initAnthill(std::vector<std::vector<short>> roomLinking, std::vector<short> roomSizes, short antAmount){

    this->antAmount = antAmount;

    this->roomLinking = roomLinking;
    this->roomSizes = roomSizes;

    // Room creation
    for (size_t i = 0; i < roomSizes.size(); i++)
    {
        if (i == 0) {
            // V room
            Room* V = new Room(roomSizes[i]);
            // Ants creation
            for (size_t j = 0; j < antAmount; j++)
            {
                Ant* ant = new Ant();
                V->addAnt(ant);
            }
            this->rooms.push_back(V);
        } else if (i == roomSizes.size()-1) {
            // D room
            Room* D = new Room(roomSizes[i]);
            this->rooms.push_back(D);
        } else {
            // rooms
            Room* room = new Room(roomSizes[i]);
            this->rooms.push_back(room);
        }
    }

    // Room adjacencies
    for (size_t i = 0; i < this->rooms.size(); i++)
    {
        for (size_t j = 0; j < this->roomLinking[i].size(); j++)
        {
            if (this->roomLinking[i][j] == 1)
            {
                this->rooms[i]->addToNexts(this->rooms[j]);
                
                this->rooms[j]->addToPrevs(this->rooms[i]);
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

        std::cout << " | Prevs: ";
        if (this->rooms[i]->prevs.empty()) {
            std::cout << "None";
        } else {
            for (size_t p = 0; p < this->rooms[i]->prevs.size(); p++) {
                for (size_t k = 0; k < this->rooms.size(); k++) {
                    if (this->rooms[i]->prevs[p] == this->rooms[k]) {
                        if (k == 0) std::cout << "V ";
                        else if (k == this->rooms.size() - 1) std::cout << "D ";
                        else std::cout << "S" << k << " ";
                        break;
                    }
                }
            }
        }

        std::cout << " | Nexts: ";
        if (this->rooms[i]->nexts.empty()) {
            std::cout << "None";
        } else {
            for (size_t n = 0; n < this->rooms[i]->nexts.size(); n++) {
                for (size_t k = 0; k < this->rooms.size(); k++) {
                    if (this->rooms[i]->nexts[n] == this->rooms[k]) {
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