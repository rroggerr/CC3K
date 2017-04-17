#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <string>

struct Student{
  const unsigned int idNo;
  std::string name;
  double* grades;
  int numGrades;
  Student(unsigned int id, std::string n, double gs[], int ng)
    : idNo(id), name(n), grades(new double[ng]), numGrades(ng)
  {
    for(int i=0; i < numGrades; ++i){
      grades[i] = gs[i];
    }
  }
  Student(const Student& os) 
    : idNo(os.idNo+1), name(os.name), grades(new double[os.numGrades]), numGrades(os.numGrades)
  {
    for(int i=0; i < numGrades; ++i){
      grades[i] = os.grades[i];
    }
  }
};
#endif
