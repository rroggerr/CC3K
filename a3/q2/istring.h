#ifndef __ISTRING_H__   //Include guard
#define __ISTRING_H__   //
#include <iostream>     //Includes IOStream
//--------------------------------------------------------------------------------------------------------------------
// Header for the Istring class
//--------------------------------------------------------------------------------------------------------------------
struct iString{
    char * chars;
    unsigned int length;
    unsigned int capacity;
    iString();
    iString(const char *);
    iString(const iString&);
    iString &operator=(const iString&);
    ~iString();
    iString &operator+(const iString&);
    iString &operator*(const int);
};

// Add other declarations here:
std::ostream &operator<<(std::ostream&, const iString&);
std::istream &operator>>(std::istream&, iString&);
iString &operator*(const int, const iString&);
#endif

