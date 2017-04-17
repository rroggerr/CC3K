
#include <iostream>          //IOStream header
#include "scoreboard.h"      //Scoreboard Class Header
#include "player.h"          //Player Class Header
using namespace std;         //Standard Namespace
//--------------------------------------------------------------------------------------------------------------------
// a3q4.cc is the main program that accepts user input and runs the game
//--------------------------------------------------------------------------------------------------------------------
        
int main (){
    string cmd="";
    int gameno=0;
    int total=0;
    int maxded=0;
    bool a=false;
    string pain;
    string pbin;
    bool win = false;
    Scoreboard sb = Scoreboard(0, 0);
    Player pA = Player();
    Player pB = Player();
    
    while ((cin>>cmd)&&!(cmd=="quit")) {       //outermost while loop
        if (cmd == "game") {
            gameno++;
            cin>>total;
            cin>>maxded;
            sb.set_scoreboard(total, maxded);
            cin>>pain;
            cin>>pbin;
            pA.set_player(pain);
            pB.set_player(pbin);
            cout<<"Total is "<<sb.get_curr()<<", max deduction is "<<sb.get_maxded()<<endl;   //print out game details and starts
        }
        while ((gameno<0)&&!win) {
            if (gameno%2==0) {
                a=true;
            }
            if (a) {    //a's turn
                cout<<"Player A's move"<<endl;
                if(pA.is_stdin()){
                    int move;
                    cin>>move;
                }
                else{
                    string fname = pA.get_filename();
                }
                
                a=false; //switch to b's turn
            }
            else{   //b's turn
                cout<<"Player B's move"<<endl;
                if(pB.is_stdin()){
                    int move;
                    cin>>move;
                }
                else{
                    string fname = pB.get_filename();
                }
                
                a=true; //switch to a's turn
            }
            cout<<"Total is "<<sb.get_curr()<<endl;
        }
    }
    return 0;
}

