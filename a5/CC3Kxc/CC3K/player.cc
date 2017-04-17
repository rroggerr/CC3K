//
//  player.cc
//  CC3K
//
//

#include "player.h"
using namespace std;

Player::Player(char c) {
    race = c;
    if (c == 'h') {
        maxhp = 140;
        atk = 20;
        def = 20;
    } else if (c == 'e') {
        maxhp = 140;
        atk = 30;
        def = 10;
    } else if (c == 'd') {
        maxhp = 100;
        atk = 20;
        def = 30;
    } else if (c == 'o') {
        maxhp = 180;
        atk = 30;
        def = 25;
    }
    aBuff = 0;
    dBuff = 0;
    hp = maxhp;
    gold = 0;
    icon = '@';
}

void Player::addGold (int i) {
    if (race == 'o') {
        if (i != 1) {
            i /= 2;
        }
    }
    if (race == 'd') {
        i *= 2;
    }
    gold += i;
}

void Player::usePotion(char c, int i) {
    if (race == 'e') {
        i = abs(i);
    }
    if (c == 'H') {
        hp += i;
        if (hp > maxhp) {
            hp = maxhp;
        } else if (hp < 1) {              //TODO might have to fix this
            hp = 1;
        }
    } else if (c == 'A') {
        aBuff += i;
    } else if (c == 'D') {
        dBuff += i;
    }
}

void Player::seenPotion(string potionstat){
    if (potionstat=="RH") {
        potions[0] = true;
    }
    else if (potionstat=="BA"){
        potions[1]=true;
    }
    else if (potionstat=="BD"){
        potions[2]=true;
    }
    else if (potionstat=="PH"){
        potions[3]=true;
    }
    else if (potionstat=="WA"){
        potions[4]=true;
    }
    else if (potionstat == "WD") {
        potions[5] =true;
    }
}

bool Player::isSeenPotion(string potionstat){
    if (potionstat=="RH") {
        return potions[0];
    }
    else if (potionstat=="BA"){
        return potions[1];
    }
    else if (potionstat=="BD"){
        return potions[2];
    }
    else if (potionstat=="PH"){
        return potions[3];
    }
    else if (potionstat=="WA"){
        return potions[4];
    }
    else if (potionstat == "WD") {
        return potions[5];
    }
    else {
        return false;
    }
}

int Player::getGold(){
    return gold;
}

char Player::getRace(){
    return race;
}

void Player::clearPotion(){
    aBuff =0;
    dBuff =0;
}

int Player::getAtk() {
    if ((atk + aBuff) < 0) {
        return 0;
    }
    else {
        return atk + aBuff;
    }
}

int Player::getDef() {
    if ((def+ dBuff) < 0) {
        return 0;
    }
    else {
        return def + dBuff;
    }
}

int Player::getCurrentHP() {
    return hp;
}
