

#ifndef __block_h__
#define __block_h__

#include <iostream>

// 

class Block{
    bool alive;       //if you can still control it
    int x, y;         //bottom left coordinates
    int direction;    //directions for each defined for each block [0,1,2,3]
    char blockid;     //MIGHT NOT NEED THIS:
    char **theBlock;
public:
    Block();          //make sure to call this when implementing the real blocks
    Block(char blockid);
    ~Block();         //call this as well
    void notifydisplay();
    void notifyboard();
    void left();
    void right();
    void down();
    void drop();
    virtual void rotateCW();
    virtual void rotateACW();    //each block rotates differently
    
};
#endif

//i dont know how to do the block class