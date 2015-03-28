#include "MarkerManager.h"
#include <iostream>

MarkerManager::MarkerManager(){
    position[0] = 520;    
    position[1] = 450;    
    position[2] = 381;    
    position[3] = 309;    
    position[4] = 239;    
    position[5] = 165;    
    
    for(int idx = 0; idx < NUM_ROWS * NUM_COLS; idx++){
        boardArray[idx] = EMPTY;
        if(idx < NUM_COLS){
            columns[idx].markerCount = 0;   
        }
    }
}

int MarkerManager::rowPosition(int colIdx){
   columns[colIdx].markerCount++; 
   return (columns[colIdx].markerCount);
}

int MarkerManager::verticalAdjust(int colIdx){
    for(int idx = 0; idx < NUM_ROWS; idx++){
        if(idx + 1 == columns[colIdx].markerCount){
            return position[idx];  
        }
    }
    return 0; 
}

void MarkerManager::setArrayValue(int row, int col, int player){
    boardArray[(row - 1) * NUM_COLS + col] = player;        
}

bool MarkerManager::checkForFour(int a, int b, int c, int d){
    return (boardArray[a] != EMPTY && boardArray[a] == boardArray[b] && boardArray[b] == boardArray[c] 
        && boardArray[c] == boardArray[d]);    
}

bool MarkerManager::checkVertical(){
    const int HEIGHT = 7;
    for(int row = 0; row < NUM_ROWS - 3; row++){
        for(int col = 0; col < NUM_COLS; col++){
           const int idx = row * NUM_COLS + col;
           if(checkForFour(idx, idx + HEIGHT, idx + (HEIGHT * 2), idx + (HEIGHT * 3))){
                return true;   
           } 
        }
    }   
    return false;
}

bool MarkerManager::checkHorizontal(){
    const int WIDTH = 1;
    for(int row = 0; row < NUM_ROWS; row++){
        for(int col = 0; col < NUM_COLS - 3; col++){
            const int idx = row * NUM_COLS + col; 
            if(checkForFour(idx, idx + WIDTH, idx + (WIDTH * 2), idx + (WIDTH * 3))){
                return true; 
            }
        }
    } 
    return false;
}

bool MarkerManager::checkDiagonal(){
    const int LHS = 8, RHS = 6;
    for(int row = 0; row < NUM_ROWS - 3; row++){
        for(int col = 0; col < NUM_COLS; col++){
            const int idx = row * NUM_COLS + col;
            if(col <= 3 && checkForFour(idx, idx + LHS, idx + (LHS * 2), idx + (LHS * 3)) || col >= 3 && 
                checkForFour(idx, idx + RHS, idx + (RHS * 2), idx + (RHS * 3))){
                    return true;     
            }    
        }     
    }    
    return false;
}

bool MarkerManager::checkForWin(){
    return (checkVertical() || checkHorizontal() || checkDiagonal());    
}

