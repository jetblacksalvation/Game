#pragma once
#include "VirtualStateInterface.h"
class PlayerHandler :
    public VirtualStateInterface
{
public:
    /*
        maybe player world will be Paralax? 
        idk lots of sprites, want old school dungeon
        crawler...
    */
    virtual void HandleEvent(sf::Event event) 
    {
        std::cout << "operation\n";
        if (event.key.code == sf::Keyboard::W) {
            y--;

        }
        else if (event.key.code == sf::Keyboard::S) {
            y++;
        }
        if (event.key.code == sf::Keyboard::A) {
            x--;

        }
        else if (event.key.code == sf::Keyboard::D) {
            x++;
        }
    };

private:
    int x =0, y =0;

};