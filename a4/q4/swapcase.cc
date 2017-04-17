
#include "swapcase.h"
#include <iostream>
using namespace std;

SwapCase::SwapCase(TextProcessor *tp): Decorator(tp){}

string SwapCase::getWord(){
    string in = parent->getWord();
    for (int i=0; i<in.length(); i++) {
        if (isupper(in[i])) {
            in[i] = tolower(in[i]);
        }
        else if (islower(in[i])) {
            in[i] = toupper(in[i]);
        }
    }
    return in;
}
