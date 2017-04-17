 //
//   Decorator.c - Subclass Decorator
//   A4Q4
//
//

#include "decorator.h"
using namespace std;

Decorator::Decorator(TextProcessor *tp):parent(tp){}

void Decorator::setSource(istream *inp){
    parent->setSource(inp);
}

string Decorator::getWord(){
    return parent->getWord();       //calls getWord() on parent
}

bool Decorator::fail() const{        //fail flag
    return parent->fail();
}

Decorator::~Decorator(){
    delete parent;                 //deletes pointer parent
}
