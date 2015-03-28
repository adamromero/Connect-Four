#include "GameState.h"

bool GameState::loadGame(){
   const int WINDOW_HEIGHT = 626;
   const int WINDOW_WIDTH = 517;
   window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Connect Four", sf::Style::Close);

   if(!textBoard.loadFromFile("images/board.png") ||
         !textRed.loadFromFile("images/red.gif") || !textBlack.loadFromFile("images/black.gif")){
      return false;
   }

   if(!font.loadFromFile("images/SigmarOne.ttf")){
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
   const int BOARD_TOP = 150;
   int LEFT_CORNER = 4;
   for(int idx = 0; idx < NUM_COLS; idx++){
      setBoundCoordinates(block[idx], LEFT_CORNER, BOARD_TOP, blockSize.x, blockSize.y);
      LEFT_CORNER += blockSize.x;
   }
}

void GameState::initializeGame(){
   board.setTexture(textBoard);
   board.move(0,100);
   red.setTexture(textRed);
   black.setTexture(textBlack);
   message.setString(PLAYER_ONE_TURN);
   message.setFont(font);
   message.setCharacterSize(40);
   message.setColor(sf::Color::Red);
   message.move(80, 10);
   setClickBounds();
}

int GameState::horizontalAdjust(int columnIdx){
   const int ADJUST = 8;
   return block[columnIdx].left + ADJUST;
}

bool GameState::takeTurn(){
   static int playerMarker = 0;

   for(int col = 0; col < NUM_COLS; col++){
      if(block[col].contains(event.mouseButton.x, event.mouseButton.y)){
         const int row = manager.rowPosition(col);
         if(row <= NUM_ROWS){
            const int player = (playerMarker % 2) + 1;
            // Place player marker
            const int x = horizontalAdjust(col);
            const int y = manager.verticalAdjust(col);
            markers[playerMarker] = (player == PLAYER_ONE)? red : black;
            markers[playerMarker].move(x, y);
            // Place player value in array
            manager.setArrayValue(row, col, player);
            // Place next player's turn message
            message.setString((player == PLAYER_ONE)? PLAYER_TWO_TURN : PLAYER_ONE_TURN);
            playerMarker++;
            return true;
         }
      }
   }
   return false;
}

bool GameState::gameOver(int turnCount){
   const std::string PLAYER_ONE_WINS = "Player 1 wins!";
   const std::string PLAYER_TWO_WINS = "Player 2 wins!";
   const int winner = ((turnCount - 1) % 2) + 1;

   if(manager.checkForWin()){
      message.setString((winner == PLAYER_ONE)? PLAYER_ONE_WINS : PLAYER_TWO_WINS);
      return true;
   } else if(turnCount == TOTAL_SPACES){
      message.move(120, 10);
      message.setString("Tie!");
      return true;
   }
   return false;
}

void GameState::run(){
   int turnCount = 0;
   bool done = false;
   initializeGame();

   while(window.isOpen()){
      while(window.pollEvent(event)){
         if(event.type == sf::Event::Closed){
            window.close();
         } else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !done){
            if(takeTurn()){
               turnCount++;
            }
            done = gameOver(turnCount);
         }
      }

      window.clear(sf::Color::White);
      window.draw(board);
      for(int pieceIdx = 0; pieceIdx < TOTAL_SPACES; pieceIdx++){
         window.draw(markers[pieceIdx]);
      }
      window.draw(message);
      window.display();
   }
}

