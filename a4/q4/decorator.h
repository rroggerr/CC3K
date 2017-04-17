//
//  decorator.h - header file for Decorator class
//  a4q4
//
//

#ifndef __decorator_h__
#define __decorator_h__

#include <iostream>
#include "echo.h"
class Decorator : public TextProcessor{
    
protected:
    TextProcessor *parent;
public:
    Decorator(TextProcessor *tp);
    void setSource(std::istream *inp);
    std::string getWord();
    bool fail() const;
    ~Decorator();
    
};

#endif /* defined(__decorator_h__) */

