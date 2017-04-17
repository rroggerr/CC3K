#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int maxStudents = 100;
struct ClassGrades{
  string names[maxStudents];
  double grades[maxStudents];
  string className;
  int numStudents;
};

ostream& operator<<(ostream& out, const ClassGrades& cg){
    out << cg.className << ": " << cg.numStudents << " students" << endl;
    for(int i=0; i < cg.numStudents; ++i){
      out << left << setw(30) << cg.names[i] << setw(5) << cg.grades[i] << endl;  
    }

  // Always remember to return ostream. Why?
  return out; 
}

int main(){
    ClassGrades cs246;
    cs246.className = "Object-Oriented Software Development";
    cs246.names[0]="John Smith";
    cs246.names[1]="Max Power";
    cs246.names[2]="Frank Total";
    cs246.numStudents = 3;
    cs246.grades[0] = 95.6;
    cs246.grades[1] = 46.0;
    cs246.grades[2] = 80.95;
    cout << cs246;
    
    

}
