#include "player.h"
#include <iostream>
using namespace std;

Player Player::makePlayer(string in){
    if(in=="stdin"){
        si=true;
        configured=true;
        input=in;
    }
    else{
        si=false;
        configured=true;
        input=in;
    }
    return *this;
}

Player::Player(){
    si=false;
    configured=false;
    input="*;*";
}


void Player::set_player(string in){
    if(in=="stdin"){
        si=true;
        configured=true;
        input=in;
    }
    else{
        si=false;
        configured=true;
        input=in;
    }
}