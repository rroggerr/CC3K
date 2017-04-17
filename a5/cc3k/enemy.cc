//
//  enemy.cc
//  CC3K
//
//

#include "enemy.h"
#include <cstdlib>

bool Enemy::hostile = false;

Enemy::Enemy(char c):Character(c){
    if (c == 'V') {
        maxhp = 50;
        atk = 25;
        def = 25;
    } else if (c == 'W') {
        maxhp = 120;
        atk = 30;
        def = 5;
    } else if (c == 'T') {
        maxhp = 120;
        atk = 25;
        def = 15;
    } else if (c == 'N') {
        maxhp = 70;
        atk = 5;
        def = 10;
    } else if (c == 'M') {
        maxhp = 30;
        atk = 70;
        def = 5;
        hostile = false;
    } else if (c == 'D') {
        maxhp = 150;
        atk = 20;
        def = 20;
        hostile = false;
    } else if (c == 'X') {
        maxhp = 50;
        atk = 35;
        def = 20;
    }
    hp = maxhp;
    icon = c;
    moved = false;
    //goldptr = NULL;
}

bool Enemy::isMoved() {
    return moved;
}

void Enemy::setHostile() {
    hostile=true;
}

bool Enemy::isHostile() {
    return hostile;
}

void Enemy::setMoved(bool moved){
    this->moved = moved;
}

int Enemy::getDef() {
    return def;
}

int Enemy::getAtk() {
    return atk;
}

void Enemy::setGold(Gold *gp) {
    mygold = gp;
}


void Enemy::setGoldAvailable(){
    mygold->setAvailable();
}

Gold *Enemy::getGold(){
    return mygold;
}

Enemy::~Enemy() {
}

int myceil(float num) {
    int inum = (int)num;
    if (num == (float)inum) {
        return inum;
    }
    return inum + 1;
}

int Enemy::attackMe(int pcdef){
    int miss = rand()%2;
    if (miss ==1) {
        return 0;
    }
    else {
        return myceil(100/(100+static_cast<double>(pcdef)) * atk);
    }    
}
