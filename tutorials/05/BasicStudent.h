#ifndef __BASICSTUDENT_H__
#define __BASICSTUDENT_H__
#include <string>

struct Student{
  const unsigned int idNo;
  std::string name;
  double grade;
  Student(unsigned int id, std::string n, double g) : idNo(id), name(n), grade(g){};
};
#endif
