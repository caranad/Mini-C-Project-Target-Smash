#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
using namespace std;

class Board
{
    private:
        char board[ROWS][COLS];
        int row, col;
    public:
        Board()
        {
            srand(time(NULL));
            row = rand() % 10;
            col = rand() % 10;
            
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    board[i][j] = 'X';
                }
            }
            
            board[row][col] = 'O';
        }
        
        char getItem(int i, int j)
        {
            return board[i][j];
        }
        
        int getRowAnswer()
        {
            return row;
        }
        
        int getColAnswer()
        {
            return col;
        }
        
        void printBoard()
        {
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    cout << board[i][j];
                }
                cout << endl;
            }
        }
};

class Player
{
    private:
        int numShots;
    public:
        Player(int s)
        {
            numShots = s;
        }
        
        bool fire(int x, int y, Board b)
        {
            if (b.getItem(x, y) == 'O')
            {
                return true;
            }
            else 
            {
                numShots--;
                return false;
            }
        }
        
        int getShots()
        {
            return numShots;
        }
};

int main()
{
   Board b;
   Player p(5);
   
   while (p.getShots() != 0)
   {
       int x, y;
       cin >> x;
       cin >> y;
       
       if (p.fire(x, y, b))
       {
           cout << "Got him!" << endl;
           break;
       }
       else 
       {
           cout << "Missed!" << endl;
           cout << "Only " << p.getShots() << " chances left! " << endl;
       }
   }
   
   cout << "The thingy was at: " << b.getRowAnswer() << "," << b.getColAnswer() << endl;
   
   return 0;
}

