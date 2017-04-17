//
//   swapcase.h - Header file for SwapCase class
// 
//

#ifndef __swapcase_h__
#define __swapcase_h__

#include <iostream>
#include <string>
#include "decorator.h"

class SwapCase : public Decorator {
public:
    SwapCase(TextProcessor *tp);
    std::string getWord();
};

#endif
