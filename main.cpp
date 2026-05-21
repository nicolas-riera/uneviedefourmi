#include <iostream>
#include <limits>
#include "ants.hpp"

void WaitNext() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(){

    // Anthill 0

    std::cout << std::endl << "---- Anthill 0 ----" << std::endl << std::endl;

    Anthill* anthill0 = new Anthill();

    // 1 is link with NEXT room(s) only
    std::vector<std::vector<short>> roomLinking0 = {
        {0, 1, 1, 0}, // V : S1 -> S2
        {0, 0, 0, 1}, // S1: V -> D
        {0, 0, 0, 1}, // S2: V -> D
        {0, 0, 0, 0} // D: S1 -> S2
    };

    // -1 is used for rooms V and D
    std::vector<short> roomSizes0 = {-1, 1, 1, -1}; // V, S1, S2, D

    short antAmount0 = {2};

    anthill0->initAnthill(roomLinking0, roomSizes0, antAmount0);

    anthill0->run();

    WaitNext();

    delete anthill0;

    // Anthill 1

    std::cout << std::endl << "---- Anthill 1 ----" << std::endl << std::endl;

    Anthill* anthill1 = new Anthill();

    std::vector<std::vector<short>> roomLinking1 = {
        {0, 1, 0, 0}, // V :  S1
        {0, 0, 1, 0}, // S1 : V -> S2
        {0, 0, 0, 1}, // S2 : S1 -> D
        {0, 0, 0, 0} // D : S2
    };

    std::vector<short> roomSizes1 = {-1, 1, 1, -1}; // V, S1, S2, D

    short antAmount1 = {5};

    anthill1->initAnthill(roomLinking1, roomSizes1, antAmount1);

    anthill1->run();

    WaitNext();

    delete anthill1;

    // Anthill 2

    std::cout << std::endl << "---- Anthill 2 ----" << std::endl << std::endl;

    Anthill* anthill2 = new Anthill();

    std::vector<std::vector<short>> roomLinking2 = {
        {0, 1, 0, 1}, // V : S1 -> D
        {0, 0, 1, 0}, // S1 : V -> S2
        {0, 0, 0, 1}, // S2 : S1 -> D
        {0, 0, 0, 0} // D : S2 -> V
    };

    std::vector<short> roomSizes2 = {-1, 1, 1, -1}; // V, S1, S2, D

    short antAmount2 = {5};

    anthill2->initAnthill(roomLinking2, roomSizes2, antAmount2);

    anthill2->run();

    WaitNext();

    delete anthill2;

    // Anthill 3

    std::cout << std::endl << "---- Anthill 3 ----" << std::endl << std::endl;

    Anthill* anthill3 = new Anthill();

    std::vector<std::vector<short>> roomLinking3 = {
        {0, 1, 0, 0, 0, 0}, // V : S1
        {0, 0, 1, 0, 1, 0}, // S1 : V -> S2 -> S4
        {0, 0, 0, 1, 0, 0}, // S2 : S1 -> S3
        {0, 0, 0, 0, 0, 0}, // S3 : S2
        {0, 0, 0, 0, 0, 1}, // S4 : S1 -> D
        {0, 0, 0, 0, 0, 0}, // D : S4
    };

    std::vector<short> roomSizes3 = {-1, 1, 1, 1, 1, -1}; // V, S1, S2, S3, S4, D

    short antAmount3 = {5};

    anthill3->initAnthill(roomLinking3, roomSizes3, antAmount3);

    anthill3->run();

    WaitNext();

    delete anthill3;

    // Anthill 4

    std::cout << std::endl << "---- Anthill 4 ----" << std::endl << std::endl;

    Anthill* anthill4 = new Anthill();

    std::vector<std::vector<short>> roomLinking4 = {
        {0, 1, 0, 0, 0, 0, 0, 0}, // V : S1
        {0, 0, 1, 1, 0, 0, 0, 0}, // S1 : V -> S2 -> S3
        {0, 0, 0, 0, 1, 0, 0, 0}, // S2 : S1 -> S4
        {0, 0, 0, 0, 1, 0, 0, 0}, // S3 : S1 -> S4
        {0, 0, 0, 0, 0, 1, 1, 0}, // S4 : S2 -> S3 -> S5 -> S6
        {0, 0, 0, 0, 0, 0, 0, 1}, // S5 : S4 -> D
        {0, 0, 0, 0, 0, 0, 0, 1}, // S6 : S4 -> D
        {0, 0, 0, 0, 0, 0, 0, 0}, // D : S5 -> S6
    };

    // V, S1, S2, S3, S4, S5, S6, D
    std::vector<short> roomSizes4 = {-1, 2, 1, 1, 2, 1, 1, -1}; 

    short antAmount4 = {10};

    anthill4->initAnthill(roomLinking4, roomSizes4, antAmount4);

    anthill4->run();

    WaitNext();

    delete anthill4;

    // Anthill 5

    std::cout << std::endl << "---- Anthill 5 ----" << std::endl << std::endl;

    Anthill* anthill5 = new Anthill();

    std::vector<std::vector<short>> roomLinking5 = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // V : S1
        {0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S1 : V -> S2 -> S6
        {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S2 : S1 -> S3 -> S5
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S3 : S2 -> S4
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // S4 : S3 -> S5 -> D
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S5 : S2 -> S4
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // S6 : S1 -> S7 -> S8
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0}, // S7 : S6 -> S9 -> S10
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0}, // S8 : S6 -> S11 -> S12
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // S9 : S7 -> S14
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // S10 : S7 -> S14
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // S11 : S8 -> S13
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // S12 : S8 -> S13
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // S13 : S11 -> S12 -> D
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // S14 : S9 -> S10 -> D
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} // D : S4 -> S13 -> S14
    };

    // V, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S13, S14, D
    std::vector<short> roomSizes5 = {-1, 8, 4, 2, 4, 2, 4, 2, 5, 1, 1, 1, 1, 4, 2, -1}; 

    short antAmount5 = {50};

    anthill5->initAnthill(roomLinking5, roomSizes5, antAmount5);

    anthill5->run();

    WaitNext();

    delete anthill5;

    // Anthill '3D'

    std::cout << std::endl << "---- Anthill '3D' ----" << std::endl << std::endl;

    Anthill* anthill3d = new Anthill();

    std::vector<std::vector<short>> roomLinking3d = {
      {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // V : S1 -> S2
      {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0}, // S1 : V -> S6 -> S8
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // S2 : V -> S7
      {0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0}, // S3 : S4 -> S5 -> S8 -> S9
      {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}, // S4 : S3 -> S5 -> D
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S5 : S3 -> S4 -> S6
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // S6 : S1 -> S5 -> S7
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // S7 : S2 -> S6 -> S9
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S8 : S1-> S3
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // S9 : S3 -> S7
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} // D : S4 -> S9
    };

    // V, S1, S2, S3, S4, S5, S6, S7, S8, S9, D
    std::vector<short> roomSizes3d = {-1, 5, 6, 1, 3, 2, 4, 5, 4, 2, -1};

    short antAmount3d = {50};

    anthill3d->initAnthill(roomLinking3d, roomSizes3d, antAmount3d);

    anthill3d->run();

    WaitNext();

    delete anthill3d;

    // Anthill 'Salle d'at-ant'

    std::cout << std::endl << "---- Anthill 'Salle d'at-ant' ----" << std::endl << std::endl;

    Anthill* anthillAtAnt = new Anthill();

    std::vector<std::vector<short>> roomLinkingAtAnt = {
        {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // V : S1 -> S6 -> S11 -> S16
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S1 : V -> S2
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S2 : S1 -> S3
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S3 : S2 -> S4
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S4 : S3 -> S5
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // S5 : S4 -> D
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S6 : V -> S7
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S7 : S6 -> S8
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S8 : S7 -> S9
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S9 : S8 -> S10
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // S10 : S9 -> D
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S11 : V -> S12
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // S12 : S11 -> S13
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // S13 : S12 -> S14
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // S14 : S13 -> S15
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // S15 : S14 -> D
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // S16 : V -> S17
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // S17 : S16 -> S18
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // S18 : S17 -> S19
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // S19 : S18 -> S20
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // S20 : S19 -> D
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // S21 : S3 -> S8 -> S13 -> S18
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} // D : S5 -> S10 -> S15 -> S20
    };

    // V, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S13, S14, S15, S16, S17, S18, S19, S20, S21, D
    std::vector<short> roomSizesAtAnt = {-1, 50, 50, 50, 1, 1, 3, 3, 7, 5, 5, 3, 3, 10, 20, 1, 1, 30, 10, 5, 5, 30, -1};

    short antAmountAtAnt = {100};

    anthillAtAnt->initAnthill(roomLinkingAtAnt, roomSizesAtAnt, antAmountAtAnt);

    anthillAtAnt->run();

    WaitNext();

    delete anthillAtAnt;

    // Anthill 'de la muerte'

    std::cout << std::endl << "---- Anthill 'de la muerte' ----" << std::endl << std::endl;

    Anthill* anthillMuerte = new Anthill();

    std::vector<std::vector<short>> roomLinkingMuerte = {
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, // V : S1 -> S2 -> S3 -> S4 -> S5 -> S6 -> S7 -> S8
        {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, // S1 : V -> S2 -> S3 -> S4 -> S5 -> S6 -> S7 -> S8 -> S9
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0}, // S2 : V -> S1 -> S3 -> S4 -> S5 -> S6 -> S7 -> S8 -> S9
        {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0}, // S3 : V -> S1 -> S2 -> S4 -> S5 -> S6 -> S7 -> S8 -> S9
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0}, // S4 : V -> S1 -> S2 -> S3 -> S5 -> S6 -> S7 -> S8 -> S9
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0}, // S5 : V -> S1 -> S2 -> S3 -> S4 -> S6 -> S7 -> S8 -> S9
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0}, // S6 : V -> S1 -> S2 -> S3 -> S4 -> S5 -> S7 -> S8 -> S9
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0}, // S7 : V -> S1 -> S2 -> S3 -> S4 -> S5 -> S6 -> S8 -> S9
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // S8 : V -> S1 -> S2 -> S3 -> S4 -> S5 -> S6 -> S7 -> S9
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // S9 : S1 -> S2 -> S3 -> S4 -> S5 -> S6 -> S7 -> S8 -> S9
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, // S10 : S9 -> D
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} // D : S10
    };

    // V, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, D
    std::vector<short> roomSizesMuerte = {-1, 4, 3, 2, 3, 4, 2, 2, 3, 5, 5, -1};

    short antAmountMuerte = {30};

    anthillMuerte->initAnthill(roomLinkingMuerte, roomSizesMuerte, antAmountMuerte);

    anthillMuerte->run();

    WaitNext();

    delete anthillMuerte;

    return 0;
}