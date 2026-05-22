#include <vector>

class Ant
{
private:
    static short counter;
    short antId;

public:
    Ant();
    ~Ant();
    short getAntId();
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
    std::string getName();
    void addToAdjacencies(Room* room);
    void addAnt(Ant* ant);
    Ant* extractAnt();
    void dfs(std::vector<Room*> &visited, std::vector<Room*> &path, Room* &target);
    Room* findPath(Room* target);
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