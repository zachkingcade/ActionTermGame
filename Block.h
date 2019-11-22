#pragma once
#include<string>
#include<iostream>

class Block{
public:
    Block(int X = 0, int Y = 0,std::string symbol = " ",unsigned short colorBG= 0, unsigned short colorS= 0, int health = 0){
        this->X = X;
        this->Y = Y;
        this->symbol = symbol;
        this->colorBG = colorBG;
        this->colorS = colorS;
        this->health =  health;
    }

    virtual void update(){};

    virtual void move(){};

    virtual std::string draw(){
        std::string image = "";
        image += '&';
        image += std::to_string(colorS) += std::to_string(colorBG);
        image += symbol;
        return image;
    };

    //coordinates
    int X;
    int Y;
    //unicode character to represent this block
    std::string symbol;
    //background color to color this block
    unsigned short colorBG;
    //Color to color the character its self
    unsigned short colorS;
    //health of block or inherited class
    int health;
};