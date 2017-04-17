#include <iostream>
using namespace std;

struct IntArray {
    int size;
    int capacity;
    int *contents;
};

IntArray readIntArray() {
    IntArray temp = {0,0, NULL};
        int readbuff;
        while (cin>>readbuff) {
            if (temp.capacity==0) {
                temp.capacity = 5;
                temp.contents = new int[5];
            }
            else if(temp.size == temp.capacity){    //
                int newcont[temp.capacity*2];
                temp.capacity*= 2;
                for (int i=0; i<temp.size; i++){      //reallocate array
                    newcont[i] = temp.contents[i];
                }
                delete [] temp.contents;
                temp.contents = new int[temp.capacity];
                for (int i=0; i<temp.size; i++) {
                    temp.contents[i] = newcont[i];
                }
            }
            temp.contents[temp.size] = readbuff;
            temp.size++;
        }
        cin.clear();
        return temp;
    }
void addToIntArray(IntArray& ia){
    int readbuff;
    while (cin>>readbuff) {
        if (ia.capacity==0) {
            ia.capacity = 5;
            ia.contents = new int[5];
        }
        else if(ia.size == ia.capacity){    //
            int newcont[ia.capacity*2];
            ia.capacity*= 2;
            for (int i=0; i<=ia.size; i++){      //reallocate array
                newcont[i] = ia.contents[i];
            }
            delete [] ia.contents;
            ia.contents = new int[ia.capacity];
            for (int i=0; i<ia.size; i++) {
                ia.contents[i] = newcont[i];
            }
        }
        ia.contents[ia.size] = readbuff;
        ia.size++;
    }
    cin.clear();
}
    
    void printIntArray(const IntArray& ia){
        for (int i=0; i< ia.size; i++) {
            cout<< ia.contents[i] <<" ";
        }
        cout<<endl;
    }
    
    
    // Do not change this function!
    
    int main() {  // Test harness for IntArray functions.
        bool done = false;
        IntArray a[4];
        a[0].contents = a[1].contents = a[2].contents = a[3].contents = 0;
        
        while(!done) {
            char c;
            char which;
            
            // Note:  prompt prints to stderr, so it should not occur in .out files
            cerr << "Command?" << endl;  // Valid commands:  ra, rb, rc, rd,
            //                  +a, +b, +c, +d,
            //                  pa, pb, pc, pd, q
            cin >> c;  // Reads r, +, p, or q
            if (cin.eof()) break;
            switch(c) {
                case 'r':
                    cin >> which;  // Reads a, b, c, or d
                    delete [] a[which-'a'].contents;
                    a[which-'a'].contents = 0;
                    a[which-'a'] = readIntArray();
                    break;
                case '+':
                    cin >> which;  // Reads a, b, c, or d
                    addToIntArray(a[which-'a']);
                    break;
                case 'p':
                    cin >> which;  // Reads a, b, c, or d
                    printIntArray(a[which-'a']);
                    cout << "Capacity: " << a[which-'a'].capacity << endl;
                    break;
                case 'q':
                    done = true;
            }
        }
        
        for (int i = 0; i < 4; ++i) delete [] a[i].contents;
    }

