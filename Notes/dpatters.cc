/* 

 Design patterns
 Publish - Subscribe model
 Example: Spreadsheet cells 
    subjects : spreadsheet cells
    observers : graphs (based on data in cells)
 ** Subjects need not know ovserver details
 
 
 Control flow:
    1. Observers are attached to subject Subject::attach(Observer *)
    2. Subject's state is updated 
    3. Subject notifies each observer Subject::notifyObservers()
    4. Each Observer queries the state of the subject and responds accordingly
                        ConcreteSubject::getState()
 
*/

#include <iostream>
using namespace std;

class Subject { //Generates Data   -- virtual
    
public:
    attach(Observer*);
    detach(Observer*);
    notifyObservers();
}

class ConcreteSubject : public Subject {    
public:
    getstate();
}

class Observer {  //Receives data + responds
public:
    virtual notify();
}

class ConcreteObserverA : public Observer {
    notify();
}

/*    
------------------------------------------------------------------------------ 
                                Actual Code
------------------------------------------------------------------------------
*/

class Subject {
    Observer *observers[maxObservers];
    int numObservers;
public:
    bool attach(Observer *o); // adds o to obsercers returns true if successful
    void deatch(Observer *o); //removes o from obserces
    void notifyObservers(){
        for (int i=0; i<numObservers; i++){
            observers[i]->notify();
        }
    }
    virtual ~Subject()=0; //Subject is abstract because of pure virtual destructor
};

Subject::~Subject(){}   // Has to have a destructor

class Observer {
public:
    virtual void notify()=0;
    virtual ~Observer(){}
};

/*------------------------------------------------------------------------
 Actual Example Horse Race
 Subject: the race
 Observer: The bettors
 ------------------------------------------------------------------------*/
class HorseRace : public Subject{
    string lastWinner;
public:
    bool runRace(); //returns true if successful
    string getstate() {
        return lastWinner;
    }
};

class Bettor: public Observer {
    HorseRace *subject;
    string name, myhorse;
public:
    Bettor(HorseRace *hr, string name, string horse): subject(hr), name(name), myhorse(horse){
        hr->attach(this);
    }
    ~Bettor(){
        subject->detach(this);
    }
    void notify(){
        string winner = hr->getstate();
        if(winner==myhorse){
            cout<<"winnnnnnnn"<<endl;
        }
        else{
            cout<<"loooooooooose"<<endl;
        }
    }
};


main() {
    HorseRace hr;
    Bettor Larry(&hr, "Larry", "RunsLikeaCow");
    //declare other bettors here
    while (hr.runRace) {
        hr.notifyObservers();
    }
}









