#ifndef __SUBJECT_H__
#define __SUBJECT_H__
#include "observer.h"

const int maxObservers = 10;

class Subject {
  Observer *observers[maxObservers];
  int numObservers;  

 public:
  Subject();
  bool attach(Observer *o);
  void detach(Observer *o);
  void notifyObservers();
  virtual ~Subject();
};

#endif
