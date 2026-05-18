#include <vector>

class Ant
{
private:
    static short counter;
    short antId;

public:
    Ant();
    ~Ant();
};

class Room
{
private:
    short size;
    short antCount;
    Ant* ants;
    std::vector<Room*> adjacencies;

public:
    Room(short size);
    ~Room();
    void addAdjacency(Room* room);
    bool addAnt(Ant ant);
    Ant moveAnt();
};

class Anthill
{
private:
    short antAmount;
    std::vector<std::vector<short>> roomLinking;
    std::vector<Room> rooms;
    int stepCounter;

public:
    Anthill();
    ~Anthill();
    void initAnthill(std::vector<std::vector<short>> roomLinking, short antAmount);
    void run();
};