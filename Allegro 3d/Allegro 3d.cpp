// Allegro 3d.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "GameMain.hpp"
#include "PlayerHandler.h"
#include <iostream>


int main()
{

    GameMain gameVars;
    GameMain::VirtualState playerHandler(new PlayerHandler());
    gameVars.mainState._virtualStates.push_back(std::move(playerHandler));
    gameVars.mainState.HandleState();


}
