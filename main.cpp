#include<vector>
#include"Block.h"
#include"Actor.h"
#include<iostream>
#include "TermGame.h"


int main(){
    //create a 2d vector of block pointers, we do pointers here so we use
    //dynamic memory and not minimum
    std::vector <std::vector <Block*>>BGLayer{50};
    //create our test 100 by 100 character stage and change their c and y 
    //coordinates accordingly
    for (int x = 0; x < 50; x++){
        for(int y = 0; y < 50; y++){
            BGLayer[x].push_back(new Block);
            BGLayer[x][y]->X = x;
            BGLayer[x][y]->Y = y;
        }
    }

    //for testing Im going to set them all to green except ones that are
    //matching which should create a line and ones where either x
    for (int x = 0; x < 50; x++){
        for(int y = 0; y < 50; y++){
            if (x == 0 || y == 0 || x == y ){
                BGLayer[x][y]->colorBG = 5;
            } else {
                BGLayer[x][y]->colorBG = 4;
            }
        }
    }
    // for (int x = 0; x < 50; x++){
    //     for(int y = 0; y < 50; y++){
    //         TermPrint::print(stage[x][y]->draw());
    //     }
    //     std::cout << std::endl;
    // }

    //create a temporary test actor layer
    std::vector <std::vector <Actor*>>actorLayer{50};
    for (int x = 0; x < 50; x++){
        for(int y = 0; y < 50; y++){
            actorLayer[x].push_back(new Actor);
            actorLayer[x][y]->X = x;
            actorLayer[x][y]->Y = y;
        }
    }
    //set up our player
    actorLayer[25][25]->symbol = "\u263A";
    actorLayer[25][25]->colorS = 8;
    actorLayer[25][25]->colorBG = 2;
    actorLayer[25][25]->actorHere = true;
    TermPrint::print(actorLayer[25][25]->draw());

    
}