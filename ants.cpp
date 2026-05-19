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
    Ant ant;
    return ant;
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

    this->printDebug();
    
};

void Anthill::run(){
    // To complete
};

// Debugging only
void Anthill::printDebug() {
    for (size_t i = 0; i < this->rooms.size(); i++) {
    std::cout << "Index [" << i << "] : "
              << "Adress: " << this->rooms[i] 
              << " | Max Size: " << this->roomSizes[i]
              << " | Ants: ";
    
    if (i == 0) {
        for (short j = 0; j < this->antAmount; j++) {
            std::cout << j << " ";
        }
    } else {
        std::cout << "Aucune";
    }
    std::cout << std::endl;
    }
};