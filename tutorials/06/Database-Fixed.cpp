#include "Database-Fixed.h"
#include <iostream>
using namespace std;

Database* Database::singleton = NULL;

Database* Database::getInstance(){
    if(singleton) return singleton;
    singleton = new Database;
    return singleton;
}

void Database::addUser(string id){ users += 1;}

unsigned int Database::getCount(){ return users;}

int main(){
    Database * db1 = Database::getInstance();
    Database * db2 = Database::getInstance();
    for(int i=0; i < 10; ++i){
        db1->addUser("foo");    
    }
    cout << "db1 count:" << db1->getCount() << endl;
    cout << "db2 count:" << db2->getCount() << endl;
    for(int i=0; i < 10; ++i){
        db2->addUser("foo");    
    }
    cout << "db1 count:" << db1->getCount() << endl;
    cout << "db2 count:" << db2->getCount() << endl;
}
