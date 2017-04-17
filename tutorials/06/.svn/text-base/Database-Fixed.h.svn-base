#ifndef __DATABASE_H__
#define __DATABASE_H__
#include <string>
class Database{
  static Database* singleton;
  unsigned int users;
  Database() : users(0){}
 public:
  static Database* getInstance();
  void addUser(std::string id);
  unsigned int getCount();
};
#endif
