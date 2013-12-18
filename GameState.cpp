#include "GameState.h"
#include <SFML/Window/Event.hpp>

bool GameState::loadGame(){
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Connect Four");
	
	if(!textBoard.loadFromFile("images/board.png") || 
		!textRed.loadFromFile("images/red.gif") || !textBlack.loadFromFile("images/black.gif")){
			return false;
	}
	
	if(!font.loadFromFile("images/3rd Man.ttf")){
		return false;
	}
	
	return true;
}

void GameState::setBoundCoordinates(sf::IntRect &block, int left, int top, int width, int height){
	block.left = left;
	block.top = top;
	block.width = width;
	block.height = height;
}

void GameState::setClickBounds(){
	const sf::Vector2i blockSize(72, 520);
	const int BOARD_TOP = 56;
	int LEFT_CORNER = 4;
	for(int idx = 0; idx < NUM_COLS; idx){
		LEFT_CORNER += blockSize.x;
		setBoundCoordinates(block[idx], LEFT_CORNER, BOARD_TOP, blockSize.x, blockSize.y);
	}
}


void GameState::initializeGame(){
	board.setTexture(textBoard);
	board.move(0,100);
	red.setTexture(textRed);
	black.setTexture(textBlack);
	message.setFont(font);
	message.setString("Connect Four");
	message.setCharacterSize(40);
	message.setColor(sf::Color::Red);
	message.move(175, 10);
	
}

bool GameState::clickIsInBounds(int idx){
	return (block[idx].contains(event.mouseButton.x, event.mouseButton.y));
}

void GameState::takeTurn(){
	for(int idx = 0; idx < NUM_COLS; idx++){
		if(clickIsInBounds(idx)){
			
		}
	}

}

void GameState::run(){
	initializeGame();
	sf::Event event;
	while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            } else if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            	takeTurn();
            }            
        }
        window.clear(sf::Color::White);
        window.draw(board);
        //window.draw(red);
       // window.draw(black);
        window.draw(message);
        window.display();    
    }
}

