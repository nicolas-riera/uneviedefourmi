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

void Anthill::initAnthill(std::vector<std::vector<short>> roomLinking, short antAmount){
    // To complete
};

void Anthill::run(){
    // To complete
};