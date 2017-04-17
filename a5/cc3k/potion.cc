//
//  potion.cc
//  CC3K
//
//

#include "potion.h"
using namespace std;

Potion::Potion(char c):Item('P') {
    if (c == '0') {
        stat = 'H';
        amount = 10;
        type = "RH";
    } else if (c == '1') {
        stat = 'A';
        amount = 5;
        type = "BA";
    } else if (c == '2') {
        stat = 'D';
        amount = 5;
        type = "BD";
    } else if (c == '3') {
        stat = 'H';
        amount = -10;
        type = "PH";
    } else if (c == '4') {
        stat = 'A';
        amount = -5;
        type = "WA";
    } else if (c == '5') {
        stat = 'D';
        amount = -5;
        type = "WD";
    }
}

char Potion::getStat() {
    return stat;
}

string Potion::getType() {
	return type;
}

Potion::~Potion(){}
