#include "subject.h"

Subject::Subject(): numObservers(0) {}
Subject::~Subject() {}

bool Subject::attach(Observer *o) {
  if (numObservers < maxObservers) {
    observers[numObservers++] = o;
    return true;
  }
  else return false;
}

void Subject::detach(Observer *o) {
  int i;
  for (i = 0; i < numObservers && observers[i] != o; ++i);

  if (i < numObservers && observers[i] == o) {
    for (int j = i; j < numObservers - 1; ++j) {
      observers[j] = observers[j+1];
    }
  }
  if (numObservers > 0) --numObservers;
}

void Subject::notifyObservers() {
  for (int i = 0; i < numObservers; ++i) {
    observers[i]->notify();
  }
}
