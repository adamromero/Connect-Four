#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

const int WINDOW_HEIGHT = 626;
const int WINDOW_WIDTH = 517;
const int NUM_COLS = 7;


class GameState {
	private:
		sf::RenderWindow window;
		// Game visuals ie. board, black/red markers
		sf::Texture textBoard, textRed, textBlack;
		sf::Sprite board, red, black;
		// In-game title and message
		sf::Text title, message;
		sf::Font font;
		// Click boundries
		sf::IntRect block[NUM_COLS];
		void setBoundCoordinates(sf::IntRect &block, int left, int top, int width, int height);
		void setClickBounds();
		void initializeGame();
	public:
		bool loadGame();
		void run();

};

#endif
