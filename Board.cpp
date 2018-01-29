//
//  Board.cpp
//  C++FinalProject
//
//  Created by Isabelle Chong on 1/27/18.
//  Copyright © 2018 Isabelle Chong. All rights reserved.
//

#include "Board.hpp"
bool Board::isEmpty(int r, int c){
    if (board[r][c]=="*")
        return true;
    return false;
}
void Board::addToBoard(int r, int c, std::string move)
{
    board[r][c] = move;
}
std::ostream &operator<<(std::ostream &os, Board &b)
{
    for (int i = 0; i<DIMENSION; i++)
        {
            for (int j  = 0; j<DIMENSION; j++)
                {
                    os<<b.board[i][j] << " ";
                }
            os<<"\n";
        }
    return os;
}


bool Board::checkRows()
{
    for (int i = 0; i<DIMENSION; i++)
        {
            if ((board[i][0]==board[i][1])&&(board[i][1]==board[i][2])&&(board[i][0]==board[i][2]))
                {
                    winningString = board[i][0];
                    return true;
                }
        }
    return false;
    
}
bool Board::checkCols()
{
    for (int i = 0; i<DIMENSION; i++)
        {
            if ((board[0][i]==board[1][i])&&(board[1][i]==board[2][i])&&(board[0][i]==board[2][i]))
                {
                    winningString = board[0][i];
                    return true;
                }
        }
    return false;
}
bool Board::checkDiagonals()
{
    if ((board[0][0]==board[1][1])&&(board[1][1]==board[2][2])&&(board[0][0]==board[2][2]))
        {
            winningString = board[0][0];
            return true;
        }
    
    if ((board[0][2]==board[1][1])&&(board[1][1]==board[2][0])&&(board[2][0]==board[0][2]))
        {
            winningString = board[0][0];
            return true;
        }
    return false;
}
bool Board::allSpotsFull()
{
    bool allFull = true;
    for (int i = 0; i<DIMENSION; i++)
    {
            for (int j = 0; j<DIMENSION; j++)
                {
                    if (board[i][j]=="*")
                        {
                            allFull = false;
                            break;
                        }
                }
    }
    return allFull;
}
bool Board::winner()
{
    if ((checkRows()==true||checkCols()==true||checkDiagonals()==true) && winningString!="*")
        {
            std::cout << winningString << " is the winner!\n";
            return true;
        }
    else if (allSpotsFull()==true)
        {
            std::cout << "It's a Tie!\n";
            return true;
        }
    else
        return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    bool won = false;
    Board tttb;
    int row1;
    int row2;
    int col1;
    int col2;
    while (won == false)
    {
        std::cout << "Let's play Tic Tac To!\n";
        std::cout << "Player 1's Turn\n";
        while (true)
        {
            std::cout << "Row?\n";
            std::cin >> row1;
            row1-=1;
            std::cout << "Column?\n";
            std::cin >> col1;
            col1-=1;
            if (tttb.isEmpty(row1, col1))
                break;
            else
                std::cout<<"That's already full! Try again.\n";
        }
        tttb.addToBoard(row1, col1, "X");
        std::cout << tttb;
        won = tttb.winner();
        if (won == true)
                break;
        std::cout << "Player 2's Turn\n";
        while (true)
        {
            std::cout << "Row?\n";
            std::cin >> row2;
            row2-=1;
            std::cout << "Column?\n";
            std::cin >> col2;
            col2-=1;
            if (tttb.isEmpty(row2, col2))
                break;
            else
                std::cout<<"That's already full! Try again.\n";
        }
        tttb.addToBoard(row2, col2, "O");
        std::cout << tttb;
        won = tttb.winner();
        if (won == true)
            break;
    }
    return 0;
}


    

