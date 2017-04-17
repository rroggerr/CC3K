#include <locale>      //Locale header
#include <iostream>    //IOStream header
#include "istring.h"   //Header file for Istring class
using namespace std;   //Standard namespace

//--------------------------------------------------------------------------------------------------------------------
// Istring class
//--------------------------------------------------------------------------------------------------------------------


iString::iString(){                        //Empty constructor
    chars=NULL;
    length=0;
    capacity=0;
};
iString::iString(const char *in){          //Constructor from string
    int len =0;
    while (in[len]!='\0') {                //count the length!
        len++;
    }
    len++;                                 //increment one more!!
    length = len;
    chars = new char[length];
    for (int i=0; i<=length; i++) {
        chars[i] = in[i];
    }                                      //copied!
    capacity = len+1;
}
iString::iString(const iString& in){
    if (!(&in.chars==&chars)) {
        length = in.length;
        capacity = in.capacity;
        chars = new char[capacity];
        for (int i=0; i<length; i++) {
            chars[i] = in.chars[i];
        }
    }                                      //done!
}
iString &iString::operator=(const iString& in){
    capacity=in.capacity;
    length=in.length;
    if (!(&in.chars==&chars)) {
        delete [] chars;
        chars = new char[capacity];
        for (int i=0; i<length; i++) {
            chars[i]=in.chars[i];
        }
    }
    return *this;
}
ostream &operator<<(ostream &out, const iString& is){
    for (int i=0; i<is.length; i++) {
        out << is.chars[i];
    }
    return out;
}

iString::~iString(){
    length=0;
    capacity=0;
    delete [] chars;
    chars = NULL;
}

iString &iString::operator+(const iString& is){
    iString *ret = new iString();
    ret->length = length + is.length;
    ret->capacity = capacity + is.capacity;
    char *tmp = new char[ret->capacity];
    for (int i=0; i<length; i++) {
        tmp[i]=chars[i];
    }
    for (int i=length; i<ret->length; i++) {
        tmp[i] = is.chars[i-length];
    }
    delete [] ret->chars;
    ret->chars=tmp;
    return *ret;
}

iString &operator*(const int a, const iString& is) {
    iString *newis = new iString();
    for (int i=0; i<a; i++) {
        *newis = *newis+is;
    }
    return *newis;
}

iString &iString::operator*(const int a) {
    iString *newis = new iString();
    for (int i=0; i<a; i++) {
        *newis = *newis+*this;
    }
    return *newis;
}

istream& operator>>(istream &in, iString& is){
    delete [] is.chars;
    int tmpcap = 5;                    //build temporary cap
    char *newchars = new char[tmpcap]; //buil temp char[] with cap 5
    char cbuff;                        //buffer
    int len =0;
    while (isspace(in.peek())) {
        cbuff = in.get();
    }
    while (!isspace(in.peek())) {
        cbuff = in.get();
        if(tmpcap==len){
            tmpcap*=2;
            char *tmpnewchar = new char[tmpcap];
            for (int i=0; i<len; i++) {
                tmpnewchar[i] = newchars[i];
            }                         //reallocated
            delete [] newchars;
            newchars = tmpnewchar;
        }
        newchars[len] = cbuff;
        len++;
    }
    is.chars = newchars;
    is.length = len;
    is.capacity = tmpcap;
    return in;
}


