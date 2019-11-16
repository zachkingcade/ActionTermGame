#include<vector>
#include"Block.h"
#include<iostream>
#include "TermGame.h"


int main(){
    //create a 2d vector of block pointers, we do pointers here so we use
    //dynamic memory and not minimum
    std::vector <std::vector <Block*>>stage{50};
    //create our test 100 by 100 character stage and change their c and y 
    //coordinates accordingly
    for (int x = 0; x < 50; x++){
        for(int y = 0; y < 50; y++){
            stage[x].push_back(new Block);
            stage[x][y]->X = x;
            stage[x][y]->Y = y;
        }
    }

    //for testing Im going to set them all to green except ones that are
    //matching which should create a line and ones where either x
    for (int x = 0; x < 50; x++){
        for(int y = 0; y < 50; y++){
            if (x == 0 || y == 0 || x == y ){
                stage[x][y]->colorBG = 5;
            } else {
                stage[x][y]->colorBG = 4;
            }
        }
    }
    for (int x = 0; x < 50; x++){
        for(int y = 0; y < 50; y++){
            TermPrint::print(stage[x][y]->draw());
        }
        std::cout << std::endl;
    }

    
}