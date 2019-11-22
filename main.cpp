#include<vector>
#include<iostream>
#include "TermGame.h"
#include"Block.h"
#include"Enemy.h"

using std::vector;


int main(){
    //create a 2d vector of block pointers, we do pointers here so we use
    //dynamic memory and not minimum
    std::vector <std::vector <Block*>>BGLayer{10};
    //create our test 100 by 100 character stage and change their c and y 
    //coordinates accordingly
    for (int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            BGLayer[x].push_back(new Block);
            BGLayer[x][y]->X = x;
            BGLayer[x][y]->Y = y;
        }
    }

    //for testing Im going to set them all to green except ones that are
    //matching which should create a line and ones where either x
    for (int x = 0; x < 10; x++){
        for(int y = 0; y < 10; y++){
            if (x == 0 || y == 0 || x == y ){
                BGLayer[x][y]->colorBG = 5;
            } else {
                BGLayer[x][y]->colorBG = 4;
            }
        }
    }
        std::vector <std::vector <Block*>>FGLayer{10};
        for (int x = 0; x < 10; x++){
            for(int y = 0; y < 10; y++){
                FGLayer[x].push_back(nullptr);
            }
        }
        FGLayer[5][5] = new Enemy(5,5,"\u263A",2,8,10);

    //-------------------------testing---------------------------------
    while(true){
        TermGame::sleep(1000);
        TermPrint::clear();
        for (int x = 0; x < 10; x++){
            for(int y = 0; y < 10; y++){
                if (FGLayer[x][y] == nullptr){
                    TermPrint::print(BGLayer[x][y]->draw());
                } else {
                    TermPrint::print(FGLayer[x][y]->draw());
                }
            }
            std::cout << '\n';
        }
        for (int x = 0; x < 10; x++){
            for(int y = 0; y < 10; y++){
                if (FGLayer[x][y] != nullptr){
                    Block* holder = FGLayer[x][y];
                    FGLayer[x][y] = nullptr;
                    holder->move();
                    FGLayer[holder->X][holder->Y] = holder;
                }
            }
        }
    }
}