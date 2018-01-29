//
//  Board.hpp
//  C++FinalProject
//
//  Created by Isabelle Chong on 1/27/18.
//  Copyright © 2018 Isabelle Chong. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdbool.h>
#include <sstream>
#define DIMENSION 3

class Board{
    std::string winningString;
    std::string board[DIMENSION][DIMENSION];
public:
    Board(){
        for (int i = 0; i<DIMENSION; i++)
        {
            for (int j = 0; j<DIMENSION; j++)
            {
                board[i][j] = "*";
            }
        }
    }
    bool isEmpty(int r, int c);
    void addToBoard(int r, int c, std::string move);
    friend std::ostream &operator<<(std::ostream &os, Board &b);
    bool checkRows();
    bool checkCols();
    bool checkDiagonals();
    bool allSpotsFull();
    bool winner();
    
};

#endif /* Board_hpp */
