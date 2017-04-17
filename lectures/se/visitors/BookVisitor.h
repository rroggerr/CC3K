#ifndef __BOOKVISITOR_H__
#define __BOOKVISITOR_H__

class Book;
class CSBook;
class ComicBook;

class BookVisitor {
  public:
    virtual void visit(Book &b) = 0;
    virtual void visit(CSBook &csb) = 0;
    virtual void visit(ComicBook &cb) = 0;
    virtual ~BookVisitor();
};

#endif
