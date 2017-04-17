#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

const int maxCandidates = 10;
int total=0;

string candidates[maxCandidates];
int votes[maxCandidates];
int valid =0;
int cand =0;

void readVotes(){
    string strin;
    getline(cin, strin);
    stringstream ss(strin);
    // initialize votes[] and candidates[]
    for (int i=0; i<=maxCandidates-1; i++){
        votes[i]=0;
        candidates[i]="*//*";
    }
    char check=0;
    ss>>check;
    while(!(check>=0&&check<=10)){
        candidates[cand]=strin;
        cand++;
        getline(cin,strin);
        ss.str(strin);
        ss>>check;
    }
    int intbuff;
    ss.str(strin);
    do {
        while(ss >> intbuff){
            if (intbuff > 0 && intbuff <= cand) {
                votes[intbuff]++;
                valid++;
            }
            total++;
        }
    } while (getline(cin,strin));
}

void printResults(){
    for(int i = 1; i<cand; i++){
        valid += votes[i];
    }
    int spoilt = total - valid;
    cout<<"Number of voters: "<<total<<endl;
    cout<<"Number of valid votes: "<<valid<<endl;
    cout<<"Number of spoilt votes: "<<spoilt<<endl;
    cout<<endl<<"Candidate      Score"<<endl<<endl;
    for (int i=0; i<cand; i++){
        if(candidates[i]!="*//*"){
            cout<<candidates[i-1];
            cout<<votes[i]<<endl;
        }
        
    }
}

int main() {
    readVotes();
    printResults();
}
