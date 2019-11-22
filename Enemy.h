#pragma once
#include"Block.h"
#include<ctime>

class Enemy : public Block{
public:
    //uses the Block's constructor, all varibles restated here
    //as well as setting the rand functions seed to system time
    Enemy(int X = 0, int Y = 0,std::string symbol = " ",unsigned short colorBG= 0, unsigned short colorS= 0, int health = 0) :
    Block(X,Y,symbol,colorBG,colorS,health){
        srand(std::time(nullptr));
    };

    void move(){
        int random = std::rand() % 5;
        //here: 0 = up/down, 1 = left/right, 2-4 = do nothing;
        if (random == 0){
            // up or down
            random = std::rand() % 2;
            if (random == 0){ Y++;} else {Y--;}
            } else {
            //left or right
            random = std::rand() % 2;
            if (random == 0){X++;} else {X--;}
            }
        }
    };
