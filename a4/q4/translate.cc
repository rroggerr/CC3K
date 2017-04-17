
#include "translate.h"
using namespace std;

Translate::Translate(TextProcessor *tp, char from, char to):Decorator(tp){
    this->from = from;
    this->to = to;
}

string Translate::getWord(){
    string in = parent->getWord();
    for (int i=0; i<in.length(); i++) {
        if (in[i]==from) {
            in[i] = to;
        }
    }
    return in;
}
