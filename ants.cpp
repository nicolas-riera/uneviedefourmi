#include "ants.hpp"

short Ant::counter = 0;

Ant::Ant(){
    this->antId = counter;
    counter++;
};

Ant::~Ant(){};

Room::Room(short size, std::string name){
    this->size = size;
    this->name = name;
    std::vector<Ant*> newAnts;
    this->ants = newAnts;
};

void Room::addToAdjacencies(Room* room){
    this->adjacencies.push_back(room);
};

void Room::addAnt(Ant* ant){
    this->ants.push_back(ant);
};

Ant* Room::extractAnt(){
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
    return extractedAnt;
};

Room::~Room(){
    for (Ant* ant : this->ants) {
        delete ant;
    }
};

bool Room::DFSPath(Room* destination, std::unordered_set<Room*>& visited, Room* startRoom, Room*& nextRoom, std::unordered_map<Room*, int>& virtualAntCount) {
    
    // Exit condition
    if (this == destination) {
        return true;
    }

    visited.insert(this);

    Room* bestNeighbor = nullptr;
    int shortestPathLength = 1000000; // Insanely high number so the first path is the shortest one

    for (Room* neighbor : this->adjacencies) {
        if (visited.find(neighbor) == visited.end()) {
            if (neighbor != destination && neighbor != startRoom && neighbor->size != -1) {
                if (virtualAntCount[neighbor] >= neighbor->size) {
                    continue;
                }
            }

            // We start a new search branch from the neighbor to find the shortest past
            Room* dummyNext = nullptr; // Dummy to not override the actual nextRoom
            std::unordered_set<Room*> branchVisited = visited;
            
            if (neighbor->DFSPath(destination, branchVisited, startRoom, dummyNext, virtualAntCount)) {
                int currentLength = static_cast<int>(branchVisited.size());
                if (currentLength < shortestPathLength) {
                    shortestPathLength = currentLength;
                    bestNeighbor = neighbor;
                }
            }
        }
    }

    // bestNeibor become the nextRoom to move for the ant
    if (bestNeighbor != nullptr) {
        if (this == startRoom) {
            nextRoom = bestNeighbor;
        }
        return true;
    }

    // No path found (all adjacencies room are full), the ant won't move
    return false;
}

Anthill::Anthill() : stepCounter(0) {}

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
            room = new Room(roomSizes[i], "V");
            // Ants creation
            room->ants.reserve(antAmount);
            for (size_t j = 0; j < antAmount; j++)
            {
                Ant* ant = new Ant();
                room->addAnt(ant);
            }
        } else if (i == roomSizes.size()-1) {
            // D room
            room = new Room(roomSizes[i], "D");
        } else {
            // regular rooms
            room = new Room(roomSizes[i], "S" + std::to_string(i));
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
            }
        }
    }
    
    // this->printDebug();
    
};

// Main Resolver
void Anthill::run() {
    Room* end = this->rooms[this->rooms.size() - 1];
    bool globalActivity = true;

    while (globalActivity) {
        globalActivity = false;
        
        std::vector<std::pair<Room*, Room*>> movesToExecute;
        std::unordered_map<Room*, int> virtualAntCount;
        
        // Create a virtual ant count in rooms to properly check if rooms are empty
        for (Room* room : this->rooms) {
            virtualAntCount[room] = static_cast<int>(room->ants.size());
        }

        // Go through all rooms
        for (int i = static_cast<int>(this->rooms.size()) - 2; i >= 0; i--) {
            Room* currentRoom = this->rooms[i];
            
            if (currentRoom->ants.empty()) {
                continue;
            }

            size_t initialAntsInRoom = currentRoom->ants.size();

            // Check the movability of all ants
            for (size_t k = 0; k < initialAntsInRoom; k++) {
                std::unordered_set<Room*> visited;
                Room* nextStep = nullptr;

                if (currentRoom->DFSPath(end, visited, currentRoom, nextStep, virtualAntCount)) {
                    if (nextStep) {
                        // Add the move to the move list and adjust the virtual ant count
                        movesToExecute.push_back({currentRoom, nextStep});
                        virtualAntCount[currentRoom]--;
                        virtualAntCount[nextStep]++;
                        globalActivity = true;
                    }
                } else {
                    break;
                }
            }
        }

        // Make the actual moves when all the planning is done
        if (!movesToExecute.empty()) {
            this->stepCounter++;
            std::cout << "--- Step " << this->stepCounter << " ---" << std::endl;
            
            for (auto& move : movesToExecute) {
                Room* src = move.first;
                Room* dst = move.second;
                
                // Extract the ant from the source room and move it to the next room
                Ant* travellingAnt = src->extractAnt();
                dst->addAnt(travellingAnt);
                
                std::cout << "Ant #" << travellingAnt->getId() << " : " 
                          << src->name << " -> " << dst->name << std::endl;
            }
        }
    }
};
