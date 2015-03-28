#include "GameState.h"

int main(int argc, char *argv[]){
	GameState game;
	if(game.loadGame()){
		game.run();
	}
	return EXIT_SUCCESS;
}
