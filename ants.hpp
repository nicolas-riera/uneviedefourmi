#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Ant
{
private:
    static short counter;
    short antId;

public:
    Ant();
    ~Ant();
    short getId() const { return antId; }
};

class Room
{
    friend class Anthill;
private:
    short size;
    std::string name;
    std::vector<Ant*> ants;
    std::vector<Room*> adjacencies;

public:
    Room(short size, std::string name);
    ~Room();
    void addToAdjacencies(Room* room);
    void addAnt(Ant* ant);
    Ant* extractAnt();
    bool DFSPath(Room* destination, std::unordered_set<Room*>& visited, Room* startRoom, Room*& nextRoom, std::unordered_map<Room*, int>& virtualAntCount);
};

class Anthill
{
private:
    short antAmount;
    std::vector<short> roomSizes;
    std::vector<std::vector<short>> roomLinking;
    std::vector<Room*> rooms;
    int stepCounter;

public:
    Anthill();
    ~Anthill();
    void initAnthill(std::vector<std::vector<short>> roomLinking, std::vector<short> roomSizes, short antAmount);
    void run();
    void printDebug();
};