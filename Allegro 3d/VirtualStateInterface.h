#pragma once
//pure virutal?? A pointer to a pure virtual might be a little harder to work with.
//movement semantics with unique pointers would be odd too...
#include "SFML/Graphics.hpp"
class VirtualStateInterface
{
	// other members can be defined, the state of those members 
	// will probably be used in handle state by implementer of 
	// this interface...
public:
	//both are undefined.
	//first one is for state handling
	//second for event handling 
	virtual void HandleState() {};
	virtual void HandleEvent(sf::Event) {};
};

