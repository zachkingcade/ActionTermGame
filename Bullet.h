

class Bullet : public Block{
public:
    //uses the Block's constructor, all varibles restated here
    //health is automatically defaulted
    Player(int X = 0, int Y = 0,std::string symbol = " ",unsigned short colorBG = 0, unsigned short colorS = 0, char direction) :
    Block(X,Y,symbol,colorBG,colorS,0){
        this->direction = direction;
    };

    move(){

    }

    //varibles
    char direction;
}