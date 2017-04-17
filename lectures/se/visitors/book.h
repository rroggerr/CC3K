#ifndef __BOOK_H__
#define __BOOK_H__
#include <string>

class BookVisitor;

class Book {
  std::string title, author;
  int numPages;
 protected:
  int getNumPages();
 public:
  Book(std::string title, std::string author, int numPages);
  std::string getTitle();
  std::string getAuthor();
  virtual bool isItHeavy();

  virtual bool favourite();

  virtual void accept(BookVisitor &v);

};

#endif
