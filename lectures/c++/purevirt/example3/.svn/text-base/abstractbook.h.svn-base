#ifndef __ABSTRACTBOOK_H__
#define __ABSTRACTBOOK_H__
#include <string>

class AbstractBook {
  std::string title, author;
  int numPages;
 protected:
  int getNumPages();
  AbstractBook& operator=(const AbstractBook &rhs);  // Assignment now protected

 public:
  AbstractBook(std::string title, std::string author, int numPages);
  AbstractBook(const AbstractBook &b);

  std::string getTitle();
  std::string getAuthor();
  virtual bool isItHeavy();

  virtual bool favourite();

  virtual ~AbstractBook() = 0;  // Pure virtual destructor????
};

#endif
