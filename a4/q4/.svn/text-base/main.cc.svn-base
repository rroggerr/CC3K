#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "textprocess.h"
#include "echo.h"

int main () {
  string s;

  while(1) {
    getline(cin,s);
    if (cin.fail()) break;
    istringstream iss(s);
    string fname;
    iss >> fname;
    istream *in = (fname == "stdin") ? &cin : new ifstream(fname.c_str());

    TextProcessor *tp = new Echo;
    string dec;
    while (iss >> dec) {
      if (dec == "swapcase") {
        // tp = ...
      }
      else if (dec == "doublevowels") {
        // tp = ..
      }
      else if (dec == "skipword") {
        // tp = ...
      }
      else if (dec == "translate") {
        char from, to;
        iss >> from >> to;
        // tp = ...
      }
   } 

   tp->setSource(in);

   string word;

   while (word = tp->getWord(), !tp->fail()) {
     cout << word << endl;
   }

   if (in != &cin) delete in;

   delete tp;
  }
}
