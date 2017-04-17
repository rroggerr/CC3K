
#ifndef __doublevowels_h__
#define __doublevowels_h__

#include <iostream>
#include <string>
#include "decorator.h"

class DoubleVowels : public Decorator {
public:
    DoubleVowels(TextProcessor *tp);
    std::string getWord();
};

#endif
