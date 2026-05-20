#include <iostream>
#include "ants.hpp"

int main(){

    // Anthill 0

    std::cout << std::endl << "---- Anthill 0 ----" << std::endl << std::endl;

    Anthill* anthill0 = new Anthill();

    // 1 is link with NEXT room(s) only
    std::vector<std::vector<short>> roomLinking0 = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    // -1 is used for rooms V and D
    std::vector<short> roomSizes0 = {-1, 1, 1, -1};

    short antAmount0 = {2};

    anthill0->initAnthill(roomLinking0, roomSizes0, antAmount0);

    anthill0->run();

    delete anthill0;

    // Anthill 1

    std::cout << std::endl << "---- Anthill 1 ----" << std::endl << std::endl;

    Anthill* anthill1 = new Anthill();

    std::vector<std::vector<short>> roomLinking1 = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    std::vector<short> roomSizes1 = {-1, 1, 1, -1};

    short antAmount1 = {5};

    anthill1->initAnthill(roomLinking1, roomSizes1, antAmount1);

    anthill1->run();

    delete anthill1;

    // Anthill 2

    std::cout << std::endl << "---- Anthill 2 ----" << std::endl << std::endl;

    Anthill* anthill2 = new Anthill();

    std::vector<std::vector<short>> roomLinking2 = {
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    std::vector<short> roomSizes2 = {-1, 1, 1, -1};

    short antAmount2 = {5};

    anthill2->initAnthill(roomLinking2, roomSizes2, antAmount2);

    anthill2->run();

    delete anthill2;

    // Anthill 3

    std::cout << std::endl << "---- Anthill 3 ----" << std::endl << std::endl;

    Anthill* anthill3 = new Anthill();

    std::vector<std::vector<short>> roomLinking3 = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0},
    };

    std::vector<short> roomSizes3 = {-1, 1, 1, 1, 1, -1};

    short antAmount3 = {5};

    anthill3->initAnthill(roomLinking3, roomSizes3, antAmount3);

    anthill3->run();

    delete anthill3;

    // Anthill 4

    std::cout << std::endl << "---- Anthill 4 ----" << std::endl << std::endl;

    Anthill* anthill4 = new Anthill();

    std::vector<std::vector<short>> roomLinking4 = {
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };

    std::vector<short> roomSizes4 = {-1, 2, 1, 1, 2, 1, 1, -1};

    short antAmount4 = {10};

    anthill4->initAnthill(roomLinking4, roomSizes4, antAmount4);

    anthill4->run();

    delete anthill4;

    // Anthill 5

    std::cout << std::endl << "---- Anthill 5 ----" << std::endl << std::endl;

    Anthill* anthill5 = new Anthill();

    std::vector<std::vector<short>> roomLinking5 = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    std::vector<short> roomSizes5 = {-1, 8, 4, 2, 4, 2, 4, 2, 5, 1, 1, 1, 1, 4, 2, -1};

    short antAmount5 = {50};

    anthill5->initAnthill(roomLinking5, roomSizes5, antAmount5);

    anthill5->run();

    delete anthill5;

    // Anthill '3D'

    std::cout << std::endl << "---- Anthill '3D' ----" << std::endl << std::endl;

    Anthill* anthill3d = new Anthill();

    std::vector<std::vector<short>> roomLinking3d = {
      {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0},
      {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    std::vector<short> roomSizes3d = {-1, 5, 6, 1, 3, 2, 4, 5, 4, 2, -1};

    short antAmount3d = {50};

    anthill3d->initAnthill(roomLinking3d, roomSizes3d, antAmount3d);

    anthill3d->run();

    delete anthill3d;

    // Anthill 'Salle d'at-ant'

    std::cout << std::endl << "---- Anthill 'Salle d'at-ant' ----" << std::endl << std::endl;

    Anthill* anthillAtAnt = new Anthill();

    std::vector<std::vector<short>> roomLinkingAtAnt = {
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    std::vector<short> roomSizesAtAnt = {-1, 50, 50, 50, 1, 1, 3, 3, 7, 5, 5, 3, 3, 10, 20, 1, 1, 30, 10, 5, 5, 30, -1};

    short antAmountAtAnt = {100};

    anthillAtAnt->initAnthill(roomLinkingAtAnt, roomSizesAtAnt, antAmountAtAnt);

    anthillAtAnt->run();

    delete anthillAtAnt;

    // Anthill 'de la muerte'

    std::cout << std::endl << "---- Anthill 'de la muerte' ----" << std::endl << std::endl;

    Anthill* anthillMuerte = new Anthill();

    std::vector<std::vector<short>> roomLinkingMuerte = {
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    std::vector<short> roomSizesMuerte = {-1, 4, 3, 2, 3, 4, 2, 2, 3, 5, 5, -1};

    short antAmountMuerte = {30};

    anthillMuerte->initAnthill(roomLinkingMuerte, roomSizesMuerte, antAmountMuerte);

    anthillMuerte->run();

    delete anthillMuerte;

    return 0;
}