#include "catalogue.h"
#include "book.h"
#include "csbook.h"
#include "comicbook.h"
using namespace std;

map<string, int> CatalogueVisitor::getResult() { return theCatalogue; }

void CatalogueVisitor::visit(Book &b) {
  theCatalogue[b.getAuthor()]++;
}

void CatalogueVisitor::visit(ComicBook &cb) {
  theCatalogue[cb.getHero()]++;
}

void CatalogueVisitor::visit(CSBook &csb) {
  theCatalogue[csb.getLanguage()]++;
}

