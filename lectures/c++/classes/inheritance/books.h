#ifndef __BOOKS_H__
#define __BOOKS_H__
#include <string>

class Book {
  std::string title, author;
  int numPages;
 public:
  Book(std::string title, std::string author, int numPages);
  std::string getTitle() const;
  std::string getAuthor() const;
  int getNumPages() const;
};

class CSBook: public Book {
  std::string language;
 public:
  CSBook(std::string title, std::string author, int numPages, std::string language);
  std::string getLanguage() const;
};

class ComicBook: public Book {
  std::string hero;
 public:
  ComicBook(std::string title, std::string author, int numPages, std::string hero);
  std::string getHero() const;
};

#endif
