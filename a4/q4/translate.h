//
//  translate.h - Header file for Translate class
//

#ifndef __translate_h__
#define __translate_h__

#include <iostream>
#include <string>
#include "decorator.h"

class Translate : public Decorator {
    char from;
    char to;
public:
    Translate(TextProcessor *tp, char, char);
    std::string getWord();
};

#endif
