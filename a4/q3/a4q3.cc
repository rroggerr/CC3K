//
//  main.cc
//  A4Q3
//
//

#include <iostream>
#include "grid.h"
#include "textdisplay.h"
using namespace std;

int main() {
    Grid g;
    string strbuff;
    int intbuff;
    while (cin>>strbuff) {
        if (strbuff=="new") {
            cin>>intbuff;
            g.init(intbuff);
        }
        else if (strbuff=="init"){
            int r,c;
            string line ="";
            bool stop = false;
            while (!stop) {
                cin>>r;
                cin>>c;
                if (r==-1 && c == -1) {
                    stop = true;
                }
                if (r!=-1 && c != -1) {
                    g.turnOn(r, c);
                }
            }
        }
        else if (strbuff=="step"){
            g.tick();
        }
        else if (strbuff=="steps"){
            cin>>intbuff;
            for (int i=0; i<intbuff; i++) {
                g.tick();
            }
        }
        else if (strbuff=="print"){
            cout<<g;
        }
    }
}

