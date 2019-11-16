#include<string>

class Block{
protected:
    virtual void update() = 0;
    virtual std::string draw() = 0;

    //coordinates
    int X;
    int Y;
    //unicode character to represent this block
    std::string symbol;
    //background color to color this block
    std::string colorBG;
    //Color to color the character its self
    std::string colorS;
};