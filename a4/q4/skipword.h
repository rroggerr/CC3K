//

#ifndef __skipword_h__
#define __skipword_h__

#include <iostream>
#include <string>
#include "decorator.h"

class SkipWord : public Decorator {
public:
    SkipWord(TextProcessor *tp);
    std::string getWord();
};

#endif
