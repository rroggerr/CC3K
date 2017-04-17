#include <iostream>
#include <string>
using namespace std;

class Observer{
  public:
    virtual void notify()=0;
    virtual ~Observer(){};
};

const int max_obs= 10;
class Subject {
  Observer* obs[max_obs];
  int obs_count;
 public:
  Subject() : obs_count(0){}
  bool attach(Observer* o){
    if(obs_count != max_obs){
      obs[obs_count++] = o;
      return true;
    } // if
    return false;
  }
  
  void detach(Observer* o){
    for(int i=0; i < obs_count; ++i){
      if(obs[i] == o){
        for(int j=i; j < obs_count -1; ++j)
          obs[j]=obs[j+1];
          obs[obs_count--]=0;   
      } // if
    } // for
  }
  
  void notifyAll(){
    for(int i=0; i < obs_count; ++i)
      obs[i]->notify();
  }
  virtual ~Subject(){}  
};

// MasterControlSystem
class MCS : public Subject{
  string programInstalled;
  string installingUser;
 public:
  MCS(){}

  void getState(string& name, string& prog){
    name = installingUser;
    prog = programInstalled;
  }
  void installProgram(string name, string prog){
    programInstalled = prog;
    installingUser = name;
    notifyAll();
  }
};

class Admin : public Observer{
  MCS* subject;
  string name;
 public:
  Admin(MCS* mcs, string myname):subject(mcs),name(myname){
    subject->attach(this);
  } 
  
  void notify(){
    string iu, ip;
    subject->getState(iu, ip);
    if(iu == "TRON"){
      cout << "TRON fights for the users! Allow " << ip << " to be installed.\n";
    } else if ( iu == "EL" && name=="ASH"){
      cout << "ASH has removed EL's install permissions. Deny installation." << endl;
    } else {
      cout << name << " allows installation of " << ip << " by " << iu << "\n";
    }
  }
  
  ~Admin(){
    subject->detach(this);
  }
};
int main(){
  MCS mcs;
  Admin ash (&mcs, "ASH");
  Admin gvc (&mcs, "GVC");
  Admin clu (&mcs, "CLU");
  mcs.installProgram("TRON", "LightCycle");  
  mcs.installProgram("BML", "alpine");
  mcs.installProgram("EL", "Quadris");
}
