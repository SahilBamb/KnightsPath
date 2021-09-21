//Knights Path Solution for Sahil Bambulkar
//Project 1
//CS 280 Section 130
//Professor Jonathan Kapleau

public class Main {

    static boolean inGrid(int x, int y){
        if ((-1<x) && (x<8) && (-1<y) && (y<8)) {return true;}
        else {return false;}
    }

    static void drawBoard(int [][] board){

        for (int x=0;x<8;x++){
            for (int y=0;y<8;y++){
                System.out.print(board[x][y] + " ");
            }
            System.out.println();
        }

    }

    static boolean knightsPath(int x,int y,int [][] board){
        int curr = board[x][y];

        if (curr==64) {
            drawBoard(board);
            return true;
        }

        int moveX[] = {2,-1,2,-2,-2,1,-1,1};
        int moveY[] = {1,2,-1,1,-1,-2,-2,2};

        for(int i=0;i<8;i++) {
            int newX = x + moveX[i];
            int newY = y + moveY[i];
            if ((inGrid(newX, newY)) && (board[newX][newY] == 0)) {
                board[newX][newY] = curr + 1;
                if (knightsPath(newX, newY, board)) {
                    return true;
                } else {
                    board[newX][newY] = 0;
                }
            }
        }
            //if in grid and empty
            //set array to curr+1
            //if true, return true
            //else set array back to zero

        return false;

    }


    public static void main(String[] args) {

        int board[][] = new int[8][8];

        for (int x=0;x<8;x++){
            for (int y=0;y<8;y++){
                board[x][y]=0;
            }
        }

        knightsPath(7,7,board);




    }
}
