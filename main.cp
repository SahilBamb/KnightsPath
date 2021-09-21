//Knights Path Solution for Sahil Bambulkar
//Project 1
//CS 280 Section 130
//Professor Jonathan Kapleau

#include <iostream>
#include <cstdlib>
#include <iomanip>

using std::cout;
using std::endl;

using namespace std;


 void drawBoard(int board[8][8]) {
    for (int x=0;x<8;x++) {
        for (int y=0;y<8;y++){
            cout << std::setw (2) << board[x][y] << " ";
        }
        cout << "\n";
    }
}

bool withinGrid(int x, int y){
    if ((-1<x) && (x<8) && (-1<y) && (y<8)) {return true;}
    else {return false;}
 }

bool knightPath(int board[8][8], int x, int y) {

    int pos = board[x][y];

    if (pos == 64) {
        drawBoard(board);
        return true;
    }

    int xChange[8] = {2, -1, 2, -2, -2, 1, -1, 1};
    int yChange[8] = {1, 2, -1, 1, -1, -2, -2, 2};


    for (int i = 0; i < 8; i++) {
        if ((withinGrid(x + xChange[i], y + yChange[i])) && (board[x + xChange[i]][y + yChange[i]] == 0)) {
            board[x + xChange[i]][y + yChange[i]] = pos + 1;
            if (knightPath( board, x + xChange[i], y + yChange[i])) { return true; }
            else {board[x + xChange[i]][y + yChange[i]] = 0;}
        }
    }

    return false;
}


int main(int argc, char *argv[]) {

    int n = argc == 2 ? atoi(argv[1]) : 8;

    int startX = 7;
    int startY = 7;

    //cout << "Chess board size will be " << n << " x " << n << endl;
    //cout << "Starting location will be row: " << startX << " and col: " << startY << endl;

    int board[8][8];
    for (int x=0;x<n;x++) {
        for (int y=0;y<n;y++){
            board[x][y]=0;
        }
    }

    knightPath(board,startX,startY);

    return 0;
}
