#ifndef __DATABASE_H__
#define __DATABASE_H__
#include <string>

struct Database{
    unsigned int users;
    Database() : users(0){}
    void addUser(std::string id);
    unsigned int getCount();
    static Database* singleton;
    static Database* getInstance();
};
#endif
