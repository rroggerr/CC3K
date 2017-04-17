#ifndef __CSBOOK_H__
#define __CSBOOK_H__
#include <string>
#include "abstractbook.h"

class CSBook: public AbstractBook {
  std::string language;
 public:
  CSBook(std::string title, std::string author, int numPages, std::string language);

  bool isItHeavy();
  std::string getLanguage();

  bool favourite();

  CSBook(const CSBook &other);

  CSBook &operator=(const CSBook &rhs);
};

#endif
