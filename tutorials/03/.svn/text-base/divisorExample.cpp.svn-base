#include <string>
#include <fstream>
#include <sstream>
#include <iostream> 
using namespace std;

// Step 2.
void readLines(const int numLines, ifstream &file, string lines[]) {
  // Assume provided number of lines exist in the inFile
  for(int i=0; i< numLines; ++i ) {
    getline(file,lines[i]);
  }
}

// Step 3.
void getNumbers( int *numNumbers, const int numLines, string lines[], int numbers[]) {
  for(int i=0; i<numLines; ++i) {
    istringstream ss(lines[i]);
    for(;;) {
      ss >> numbers[*numNumbers];
      if(!ss) break;
      (*numNumbers)++;
    }
  }
}

// Step 4.
void filterNumbers(const int numNumbers, const int numbers[], const int divisor,
                    int filteredNumbers[], int* numFilteredNumbers) {  
  for(int i=0; i<numNumbers; ++i) {
    // Why check if divisor is 0 first?
    if(divisor!=0 && numbers[i]%divisor == 0) {
      filteredNumbers[*numFilteredNumbers] = numbers[i];
      (*numFilteredNumbers)++;
    }
  }
}

// Step 5.
void outputFilteredNumbers( const int numFilteredNumbers, ofstream &outfile, const int filteredNumbers[]) {
  for(int i=0; i<numFilteredNumbers; ++i) {
    outfile << filteredNumbers[i] << endl;
  }
}

const int maxLines = 10;
const int maxNums = 100;
int main() {
  int numLines;
  string fileName;
  int divisor;
  string outfileName;

  cin >> numLines;
  cin >> fileName;
  cin >> divisor;
  cin >> outfileName;

  string lines[maxLines];
  int numbers[maxNums]; 
  int numNumbers = 0;
  int filteredNumbers[maxNums];
  int numFilteredNumbers = 0;
  
  // Open Filestreams
  ifstream file(fileName.c_str()); //assume file exists 
  ofstream outfile(outfileName.c_str()); //assume file exists

  // Call procedures
  readLines( numLines, file, lines);
  getNumbers(&numNumbers, numLines, lines, numbers);
  filterNumbers(numNumbers, numbers, divisor, filteredNumbers, &numFilteredNumbers);
  outputFilteredNumbers(numFilteredNumbers, outfile, filteredNumbers);
}
