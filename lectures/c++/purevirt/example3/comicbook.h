#ifndef __COMICBOOK_H__
#define __COMICBOOK_H__
#include <string>
#include "abstractbook.h"

class ComicBook: public AbstractBook {
  std::string hero;
 public:
  ComicBook(std::string title, std::string author, int numPages, std::string hero);
  ComicBook(const ComicBook &cb);

  ComicBook &operator=(const ComicBook &rhs);

  bool isItHeavy();
  std::string getHero();

  bool favourite();
};

#endif
