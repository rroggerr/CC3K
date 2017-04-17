#ifndef __CATALOGUE_H__
#define __CATALOGUE_H__
#include <map>
#include <string>

#include "BookVisitor.h"
class Book;
class CSBook;
class ComicBook;

class CatalogueVisitor: public BookVisitor {
  std::map<std::string, int> theCatalogue;

 public:
  std::map<std::string, int> getResult();

  virtual void visit(Book &b);
  virtual void visit(ComicBook &cb);
  virtual void visit(CSBook &csb);
};

#endif
