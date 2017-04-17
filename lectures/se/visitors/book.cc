#include <string>
#include "BookVisitor.h"
#include "book.h"

using namespace std;

Book::Book(string title, string author, int numPages):
  title(title), author(author), numPages(numPages) {}

int Book::getNumPages() { return numPages; }
string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
bool Book::isItHeavy() { return numPages > 200; }

// My favourite books are short books.
bool Book::favourite() { return numPages < 100; }

void Book::accept(BookVisitor &v) { v.visit(*this); }
