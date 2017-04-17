#ifndef __BOOK_H__
#define __BOOK_H__
#include <string>

class Book {
  std::string title, author;
  int numPages;
 protected:
  int getNumPages();
 public:
  Book(std::string title, std::string author, int numPages);
  Book(const Book &b);

  std::string getTitle();
  std::string getAuthor();
  virtual bool isItHeavy();

  virtual bool favourite();
};

#endif
