#pragma once
#include <SFML/Graphics.hpp>
#include "VirtualStateInterface.h"
#include <memory>
#include <iostream>
/*
	treat like main...
*/

class GameMain
{
public:
	std::string getName();

	/*
		BELOW IS STATE HANLDER ----- ABOVE IS MEMBER INITIALIZATION.
		TREAT BELLOW LIKE MAIN ...
	*/
	typedef std::unique_ptr<VirtualStateInterface> VirtualState;

	 class mainGameState :public VirtualStateInterface {
		 //<--- GameMain class wraps and handles meta data for states
		 friend class GameMain;
	private:
		const char* _winName = "Digital Devil\0";
		sf::RenderWindow window{ {800,800}, _winName };
		sf::Event event;

		bool _mainLoop = true;

	public:
		std::vector<VirtualState> _virtualStates;//<-- manipulate this instance via helper functions ...

		void HandleState() override {
			sf::Image image;
			image.loadFromFile("icon.png");

			window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

			
			while (_mainLoop) {
				while (window.pollEvent(event))
				{
					for (VirtualState& statePtr : _virtualStates) {
						//pass in event state to ptr probably...
						statePtr.get()->HandleEvent(event);

					}
					if (event.type == event.Closed) {
						window.close();
						exit(0);
						//normal exit 
					}


				}
				//handle the other states here 

				
			}
		}
	};
	friend class mainGameState;
	mainGameState mainState;

	
private:



};

