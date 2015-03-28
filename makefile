all: GameState.o MarkerManager.o Main.o
	g++ GameState.o MarkerManager.o Main.o -lsfml-graphics -lsfml-system -lsfml-window -o connect

GameState.o: GameState.cpp GameState.h 
	g++ GameState.cpp -c

MarkerManager.o: MarkerManager.cpp MarkerManager.h
	g++ MarkerManager.cpp -c

Main.o: Main.cpp GameState.h
	g++ Main.cpp -c
	
debug:
	g++ GameState.cpp MarkerManager.cpp Main.cpp -g -lsfml-graphics -lsfml-system -lsfml-window
	
clean:
	rm -rf *o connect
