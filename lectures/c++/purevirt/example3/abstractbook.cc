#include <iostream>
#include <string>
#include "abstractbook.h"

using namespace std;

AbstractBook::AbstractBook(string title, string author, int numPages):
  title(title), author(author), numPages(numPages) {}

AbstractBook::AbstractBook(const AbstractBook &b): title(b.title), author(b.author), numPages(b.numPages) {
  cout << "Running the AbstractBook's copy ctor... " << endl;
}

AbstractBook& AbstractBook::operator=(const AbstractBook &rhs) {
  cout << "AbstractBook assignment operator running ..." << endl;

  if (this == &rhs) return *this;
  title = rhs.title;
  author = rhs.author;
  numPages = rhs.numPages;
  return *this;
}

int AbstractBook::getNumPages() { return numPages; }
string AbstractBook::getTitle() { return title; }
string AbstractBook::getAuthor() { return author; }
bool AbstractBook::isItHeavy() { return numPages > 200; }

// My favourite books are short books.
bool AbstractBook::favourite() { return numPages < 100; }

AbstractBook::~AbstractBook() {}
