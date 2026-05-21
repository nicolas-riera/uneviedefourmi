#include <vector>

struct AStarAlgo
{   
    Room* room_ptr; // 8 oct
    int g_score {0}; // 4 oct instead of short 2 oct that would lead to padding
    int f_score {0};  
    bool operator>(const AStarAlgo& second_node) const
    {
        return f_score > second_node.f_score;
    }
};


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
    friend class Anthill;
private:
    short size;
    std::vector<Ant*> ants;
    std::vector<Room*> prevs;
    std::vector<Room*> nexts;

public:
    Room(short size);
    ~Room();
    void addToNexts(Room* room);
    void addToPrevs(Room* room);
    void addAnt(Ant* ant);
    Ant extractAnt();
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