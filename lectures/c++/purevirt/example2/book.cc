#include <iostream>
#include <string>
#include "book.h"

using namespace std;

Book::Book(string title, string author, int numPages):
  title(title), author(author), numPages(numPages) {}

Book::Book(const Book &b): title(b.title), author(b.author), numPages(b.numPages) {
  cout << "Running the Book's copy ctor... " << endl;
}

Book& Book::operator=(const Book &rhs) {
  cout << "Book assignment operator running ..." << endl;

  if (this == &rhs) return *this;
  title = rhs.title;
  author = rhs.author;
  numPages = rhs.numPages;
  return *this;
}

int Book::getNumPages() { return numPages; }
string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
bool Book::isItHeavy() { return numPages > 200; }

// My favourite books are short books.
bool Book::favourite() { return numPages < 100; }
