#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include "MarkerManager.h"

const std::string PLAYER_ONE_TURN = "Player 1's turn";
const std::string PLAYER_TWO_TURN = "Player 2's turn";
const int PLAYER_ONE = 1;

class GameState {
	private:
		sf::RenderWindow window;
		sf::Texture textBoard, textRed, textBlack;
		sf::Sprite board, red, black, markers[TOTAL_SPACES];
		sf::Text title, message;
		sf::Font font;
		sf::IntRect block[NUM_COLS];
        sf::Event event;
        MarkerManager manager;
		void setBoundCoordinates(sf::IntRect &block, int left, int top, int width, int height);
		void setClickBounds();
        int horizontalAdjust(int columnIdx);
        bool takeTurn();
        bool gameOver(int turnCount);
		void initializeGame();
	public:
		bool loadGame();
		void run();
};

#endif
