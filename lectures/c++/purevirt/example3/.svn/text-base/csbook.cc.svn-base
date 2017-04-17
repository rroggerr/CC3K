#include <iostream>
#include "csbook.h"
#include <string>

using namespace std;

CSBook::CSBook(string title, string author, int numPages, string language):
  AbstractBook(title, author, numPages), language(language) {}

bool CSBook::isItHeavy() { return getNumPages() > 400; }
string CSBook::getLanguage() { return language; }

// My favourite CS books are C++ books
bool CSBook::favourite() { return language == "C++"; }

CSBook::CSBook(const CSBook &other): AbstractBook(other), language(other.language) {
  cout << "Running CSBook's copy ctor..." << endl;
}

CSBook &CSBook::operator=(const CSBook &rhs) {
  cout << "CSBook assignment operator running ... " << endl;

  if (this == &rhs) return *this;
  AbstractBook::operator=(rhs);
  language = rhs.language;
  return *this;
}
