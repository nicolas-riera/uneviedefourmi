#include "ants.hpp"

short Ant::counter = 0;

Ant::Ant(){
    this->antId = counter;
    counter++;
};

Ant::~Ant(){};

Room::Room(short size){
    this->size = size;
    this->antCount = 0;
    this->ants = new Ant[size];
};

void Room::addAdjacency(Room* room){
    this->adjacencies.push_back(room);
};

bool Room::addAnt(Ant ant){
    if (this->antCount < this->size){
        this->ants[this->antCount] = ant;
        this->antCount++;
        return true;
    }
    return false;
};

Ant Room::moveAnt(){
    // To complete
    Ant ant;
    return ant;
};

Room::~Room(){
    delete[] ants;
};

Anthill::Anthill(){};

Anthill::~Anthill(){};

void Anthill::initAnthill(std::vector<std::vector<short>> roomLinking, short antAmount){
    // To complete
};

void Anthill::run(){
    // To complete
};