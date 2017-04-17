#ifndef __BOOK_H__
#define __BOOK_H__
#include "abstractbook.h"
#include <string>

class Book: public AbstractBook {
 public:
  Book(std::string title, std::string author, int numPages);
  Book(const Book &b);

  Book& operator=(const Book &rhs);

  ~Book();
};

#endif
