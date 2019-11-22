#prama once
#include"block.h"

class Player : public Block{
    //uses the Block's constructor, all varibles restated here
    Player(int X = 0, int Y = 0,std::string symbol = " ",unsigned short colorBG= 0, unsigned short colorS= 0, int health) :
    Block(X,Y,symbol,colorBG,colorS,health){};

    void update(){};

    void move(int offsetX, int offsetY){
        X += offsetX;
        Y += offsetY;
    };
}