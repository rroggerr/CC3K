#include "csbook.h"
#include <string>

using namespace std;

CSBook::CSBook(string title, string author, int numPages, string language):
  Book(title, author, numPages), language(language) {}

bool CSBook::isItHeavy() { return getNumPages() > 400; }
string CSBook::getLanguage() { return language; }

