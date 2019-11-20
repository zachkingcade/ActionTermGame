#include<vector>
#include"Block.h"
#include"Actor.h"
#include<iostream>
#include "TermGame.h"

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
    // for (int x = 0; x < 50; x++){
    //     for(int y = 0; y < 50; y++){
    //         TermPrint::print(stage[x][y]->draw());
    //     }
    //     std::cout << std::endl;
    // }

    //create a temporary test actor layer
        std::vector <std::vector <Block*>>FGLayer{10};
        for (int x = 0; x < 10; x++){
            for(int y = 0; y < 10; y++){
                FGLayer[x].push_back(nullptr);
            }
        }
        FGLayer[5][5] = new Actor(25,25,"\u263A",2,8);

    //-------------------------testing---------------------------------
    int PX = 5;
    int PY = 5;
    while(true){
        TermGame::sleep(35);
        TermPrint::clear();
        for (int x = 0; x < 10; x++){
            for(int y = 0; y < 10; y++){
                if (FGLayer[x][y] == nullptr){
                    std::cout << "\\";
                } else {
                    TermPrint::print(FGLayer[x][y]->draw());
                }
            }
            std::cout << '\n';
        }
        char key;
        Block *aHolder;
        switch(TermGame::getch()){
            case 'w':
            aHolder = FGLayer[PX][PY];
            FGLayer[PX][PY] = nullptr;
            FGLayer[PX-1][PY] = aHolder;
            PX--;
            break;

            case 's':
            aHolder = FGLayer[PX][PY];
            FGLayer[PX][PY] = nullptr;
            FGLayer[PX+1][PY] = aHolder;
            PX++;
            break;

            case 'a':
            aHolder = FGLayer[PX][PY];
            FGLayer[PX][PY] = nullptr;
            FGLayer[PX][PY-1] = aHolder;
            PY--;
            break;

            case 'd':
            aHolder = FGLayer[PX][PY];
            FGLayer[PX][PY] = nullptr;
            FGLayer[PX][PY+1] = aHolder;
            PY++;
            break;
        }
    }
    

    
}