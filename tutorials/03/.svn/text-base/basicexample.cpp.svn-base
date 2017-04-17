#include <fstream>
using namespace std;

int main(){
  ifstream ifs("infile");
  ofstream ofs("outfile");
  string s;
  ifs >> s;
  if (! ifs.fail())
    for(int i=s.size()-1; i >= 0; --i) ofs << s.at(i);
  ofs << endl;
}
