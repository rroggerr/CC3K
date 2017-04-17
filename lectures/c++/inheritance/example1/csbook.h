#ifndef __CSBOOK_H__
#define __CSBOOK_H__
#include <string>
#include "book.h"

class CSBook: public Book {
  std::string language;
 public:
  CSBook(std::string title, std::string author, int numPages, std::string language);
  std::string getLanguage();
};

#endif
