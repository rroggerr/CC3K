#include "csbook.h"
#include <string>
#include "BookVisitor.h"

using namespace std;

CSBook::CSBook(string title, string author, int numPages, string language):
  Book(title, author, numPages), language(language) {}

bool CSBook::isItHeavy() { return getNumPages() > 400; }
string CSBook::getLanguage() { return language; }

// My favourite CS books are C++ books
bool CSBook::favourite() { return language == "C++"; }

void CSBook::accept(BookVisitor &v) { return v.visit(*this); }

