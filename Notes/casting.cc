//----Casting
// Eg:
Node n;
int *i - (int *)&n; //c-style casting

//forces C++ to treat a Node * as an int *
//avoid this in C++

//---1. Static casting
// - for sensible casts that you know should work
double d =0;
int i = static_cast<int>(d);

Book *b = new CSBook();
CSbook *csb = static_cast<CSBook*>(b);

//----2. Reinterpret Casting
// - casting between arbitrary types and disregards type safety

vector v;
Student *s = reinterpret_cast<Student*>(&v);

//----3. Const Casting
// - allows to convert between const and non-const
void g(int *p);
void f(const int *p){
    g(const_cast<int*>(*p));
}

//----4. Dynamic Casting
// -

Book *pb;
static_cast<CSBook*>(pb)->getLanguage();
// depends on what pb actually points to
// better to do a tentative cast
CSBook *pcsb = dynamic_cast<CSBook*>(pb);
//              --checks the dynamic type of the arguement
// if the cast works the pcsb will point to object, NULL otherwise
if (pcsb): cout<<pcsb->getLanguage();
else: cout<<"not a csbook";

//Runtime type information
// Better: use virtual functions/ visitor when possible
//Dynamic casting also works with references

CSBook csb;
Book &b = csb;
CSBook &csb2 = dynamic_cast<CSBook&>(b);
//if b is a reference to a CSBook then csb3 is a reference to the same CSBook
// if not, there is not such thing as a null reference

//------------------Exception handling

vector<int> v;
v.push_back(1);
v.push_back(2);
v.at(2); //OUT OF RANGE
//raises an exception

try {
    v.at(2);             //put code here
}
catch (out_of_range) {
    cerr<"Range error";  //handle error
}

//Concrete example
void f() {throw out_of_range("f");} //raise exception
void g() {f();}
void h() {g();}

int main(){
    try {
        h();
    }
    catch (out_of_range) {
        //do something
    }
}

//control goes back to the call chain, it no handler, program terminates
// out_of_range is a Class
// throw out_of_range("f") invokes constructor with arg("f")

//further handling:

catch (someError s) {
    throw SomeotherError("some other error");
}
// or throw the same thing
catch (SomeError s){
    //do something...
    throw;
}

// s may be a subtype of SomeError
throw; throw s;














