
#include <iostream>
#include "doublevowels.h"
using namespace std;

DoubleVowels::DoubleVowels(TextProcessor *tp):Decorator(tp){}

string DoubleVowels::getWord(){
    string in = parent->getWord();
    for (int i=0; i<in.length(); i++) {
        if (in[i] == 'A') {
            in.insert(i, 1, 'A');
            i++;
        }
        else if (in[i] == 'E') {
            in.insert(i, 1, 'E');
            i++;
        }
        else if (in[i] == 'I') {
            in.insert(i, 1, 'I');
            i++;
        }
        else if (in[i] == 'O') {
            in.insert(i, 1, 'O');
            i++;
        }
        else if (in[i] == 'U') {
            in.insert(i, 1, 'U');
            i++;
        }
        else if (in[i] == 'a') {
            in.insert(i, 1, 'a');
            i++;
        }
        else if (in[i] == 'e') {
            in.insert(i, 1, 'e');
            i++;
        }
        else if (in[i] == 'i') {
            in.insert(i, 1, 'i');
            i++;
        }
        else if (in[i] == 'o') {
            in.insert(i, 1, 'o');
            i++;
        }
        else if (in[i] == 'u') {
            in.insert(i, 1, 'u');
            i++;
        }
    }
    return in;
}
