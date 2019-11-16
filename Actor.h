#include"Block.h"

class Actor : public Block{
protected:
    virtual void useItem() = 0;
    virtual void move() = 0;

    int health;
    std::string name;
};