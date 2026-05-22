#include "ants.hpp"

short Ant::counter = 0;

Ant::Ant(){
    this->antId = counter;
    counter++;
};

Ant::~Ant(){};

short Ant::getAntId(){
    return this->antId;
};

Room::Room(short size, std::string name): size(size), name(name){};

std::string Room::getName(){
    return this->name;
};

void Room::addToAdjacencies(Room* room){
    this->adjacencies.push_back(room);
};

void Room::addAnt(std::unique_ptr<Ant> ant){
    this->ants.push_back(std::move(ant));
};

std::unique_ptr<Ant> Room::extractAnt(){
    // To complete
    //check if room is empty for safety
    if (ants.empty())
    {
        throw std::out_of_range("Error : empty room");
    }
    //find last element of vector 
    std::unique_ptr<Ant> extractedAnt {std::move(ants.back())};
    //delete last element
    ants.pop_back();
    //return the value of the extracted ant
    return extractedAnt;
};

Room* Room::findPath(Room* target){
    std::vector<Room*> visited;
    visited.push_back(this);
    std::vector<std::vector<Room*>> paths;
    std::vector<Room*> firstPath;
    int pathIndex = 0;
    paths.push_back(firstPath);
    this->dfs(visited, paths, pathIndex, target);
    return paths[0][0];
};

void Room::dfs(std::vector<Room*> &visited, std::vector<std::vector<Room*>> &paths, int &pathIndex, const Room* target){
    bool roomsLeft = false;
    for (Room* adjacency: this->adjacencies){
        std::cout << "Room: " << this->name << " loop " << " Adjacency->name: " << adjacency->name << "\n";
        if (adjacency == target){
            roomsLeft = true;
            std::cout << "Path found!" << std::endl;
            paths[pathIndex].push_back(adjacency);
            std::cout << "Path: ";
            for (Room* step: paths[pathIndex]){
                std::cout << step->getName() << " ";
            }
            std::cout << "\n";
            ++pathIndex;
            std::vector<Room*> otherPath;
            paths.push_back(otherPath);
        } else if (std::find(visited.begin(),visited.end(), adjacency) != visited.end()) {
                std::cout << adjacency->name << " already visited." << "\n";
        } else {
            roomsLeft = true;
            visited.push_back(adjacency);
            paths[pathIndex].push_back(adjacency);
            std::cout << adjacency->name << "\n";
            adjacency->dfs(visited, paths, pathIndex, target);
        }  
    }
    if (!roomsLeft){
        auto it = std::find(paths[pathIndex].begin(),paths[pathIndex].end(), this);
        if(it != paths[pathIndex].end()){
            paths[pathIndex].erase(it);
        }
    }
};

Room::~Room(){};

Anthill::Anthill(){};

Anthill::~Anthill(){};

void Anthill::initAnthill(std::vector<std::vector<short>> roomLinking, std::vector<short> roomSizes, short antAmount){

    this->antAmount = antAmount;

    this->roomLinking = roomLinking;
    this->roomSizes = roomSizes;

    this->rooms.reserve(roomSizes.size());

    // Room creation
    for (size_t i = 0; i < roomSizes.size(); i++)
    {
        std::unique_ptr<Room> room;
        if (i == 0) {
            // V room
            room = std::make_unique<Room>(roomSizes[i],"V");
            // Ants creation
            room->ants.reserve(antAmount);
            for (size_t j = 0; j < antAmount; j++){
                room->addAnt(std::make_unique<Ant>());
            }
        } else if (i == roomSizes.size()-1) {
            // D room
            room = std::make_unique<Room>(roomSizes[i],"D");
        } else {
            // regular rooms
            room = std::make_unique<Room>(roomSizes[i],"S"+std::to_string(i));
        }
        this->rooms.push_back(std::move(room));
    }

    // Room adjacencies
    for (size_t i = 0; i < this->rooms.size(); i++)
    {
        for (size_t j = 0; j < this->roomLinking[i].size(); j++)
        {
            if (this->roomLinking[i][j] == 1)
            {
                this->rooms[i]->addToAdjacencies(this->rooms[j].get());
                
                this->rooms[j]->addToAdjacencies(this->rooms[i].get());
            }
        }
    }
    
    //this->printDebug();
    
};

void Anthill::run(){

    for(auto it = this->rooms.rbegin(); it != this->rooms.rend() ; ++it){
        Room* room = it->get();
        if (!room->ants.empty()){
            Room* nextRoom = room->findPath(rooms.back().get());
            std::cout << "Next room is: " << nextRoom->getName() << "\n";
            for (auto antIt = room->ants.rbegin(); antIt != room->ants.rend(); ++antIt){
                Ant* lastAnt = antIt->get();
                if (lastAnt){
                    std::cout << lastAnt->getAntId() << "\n";
                    // Room* nextRoom = lastAnt->findPath();
                    // if(nextRoom) {
                    //      Ant* travellingAnt = room->extractAnt();
                    //      targetRoom->addToAnts(travellingAnt);
                    // }
                }
            }
        }
    }
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
                    if (this->rooms[i]->adjacencies[n] == this->rooms[k].get()) {
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