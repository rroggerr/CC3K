#ifndef __BOOK_H__
#define __BOOK_H__
#include <string>

class Book {
  std::string title, author;
  int numPages;
 public:
  Book(std::string title, std::string author, int numPages);
  std::string getTitle();
  std::string getAuthor();
  int getNumPages();
  bool isItHeavy();
};

#endif
