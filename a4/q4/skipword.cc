
#include "skipword.h"
using namespace std;

SkipWord::SkipWord(TextProcessor *tp):Decorator(tp){}

string SkipWord::getWord(){
    string one = parent->getWord();
    return (parent->getWord());
   
}
