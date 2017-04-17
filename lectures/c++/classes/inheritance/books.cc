#include <string>
#include "books.h"

using namespace std;

Book::Book(string title, string author, int numPages):
  title(title), author(author), numPages(numPages) {}

string Book::getTitle() const {return title;}
string Book::getAuthor() const {return author;}
int Book::getNumPages() const {return numPages;}

CSBook::CSBook(string title, string author, int numPages, string language): 
  Book(title, author, numPages), language(language) {}

string CSBook::getLanguage() const {return language;}

ComicBook::ComicBook(string title, string author, int numPages, string hero):
  Book(title, author, numPages), hero(hero) {}

string ComicBook::getHero() const {return hero;}
