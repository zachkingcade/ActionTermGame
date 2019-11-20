#include"Block.h"

class Actor : public Block{
public:
    Actor(int X = 0, int Y = 0,std::string symbol = " ",unsigned short colorBG= 0, unsigned short colorS= 0,int health = 0, std::string name = "nameless", bool actorHere = false):Block(X,Y,symbol,colorBG,colorS){
        this->health = health;
        this->name = name;
        this->actorHere = actorHere;
    }
    //virtual void useItem() = 0;
    //virtual void move() = 0;

    bool actorHere;
    int health;
    std::string name;
};