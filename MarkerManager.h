#ifndef MARKER_H
#define MARKER_H

const int NUM_COLS = 7;
const int NUM_ROWS = 6;
const int EMPTY = 0;
const int TOTAL_SPACES = NUM_ROWS * NUM_COLS;

struct Column {
    int markerCount;    
};

class MarkerManager {
    private:
        Column columns[NUM_COLS];
        int position[NUM_ROWS];    
        int boardArray[TOTAL_SPACES];
        bool checkForFour(int a, int b, int c, int d);
        bool checkVertical();
        bool checkHorizontal();
        bool checkDiagonal();
    public:
        MarkerManager();
        int rowPosition(int colIdx);
        int verticalAdjust(int colIdx);
        void setArrayValue(int row, int col, int player);
        bool checkForWin();
};

#endif
