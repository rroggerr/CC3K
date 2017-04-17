#include <iostream>
#include <string>
using namespace std;

int main() {
  int choice;
  int numChoices = 5;
  string phrases[] = {"More Vespene Gas required.","The sun is shining. But the ice is slippery.", "Gotta go fast!", "Autobots, roll out!", "Do or do not. There is no try."};
  cout << "Please choose a number from 1-5: ";
  while(cin >> choice) { // cin needs to be read at least once before it can hit eof or fail
    if(choice > numChoices)
      cerr << "Invalid number" << endl;
    else
      cout << phrases[choice-1] << endl;
    cout << "Please choose a number from 1-5: ";
  }
}
