#include <iostream>
#include <string>
using namespace std;

class Leaf;
class Binary;
class Unary;

class Visitor{
  public:
    virtual void visit(Unary &) = 0;
    virtual void visit(Binary &) = 0;
    virtual void visit(Leaf &) = 0;
    virtual ~Visitor() = 0;
};

Visitor::~Visitor(){}

class Tree{
  protected:
    string data;
  public:
    Tree(string data) : data(data){}
    virtual void accept(Visitor& v) = 0;
    string getData(){return data;}
    virtual ~Tree() = 0;
};
Tree::~Tree(){}

class Leaf : public Tree{
  public:
    void accept(Visitor &v){
      v.visit(*this);
    }
    Leaf(string data) : Tree(data){};
    ~Leaf(){}
};

class Unary : public Tree{
  protected:
    Tree * child;
  public:
    void accept(Visitor& v){
      child->accept(v);
      v.visit(*this);
    }
    
    Unary(string data, Tree *t): Tree(data), child(t){}
    ~Unary(){delete child;}
};

class Binary : public Tree{
  protected:
    Tree * left, * right;
  public:
    void accept(Visitor& v){
      left->accept(v);
      v.visit(*this);
      right->accept(v);
    }
    
    Binary(string data, Tree * t1, Tree *t2):Tree(data), left(t1), right(t2){};
    ~Binary(){delete left; delete right;}
};

class Counter: public Visitor{
    unsigned int lcount, ucount, bcount;
  public:
    void visit(Leaf& l){
      lcount+=1;
    }
    void visit(Unary& u){
      ucount+=1;
    }
    void visit(Binary& b){
      bcount+=1;
    }
  
    Counter():lcount(0), bcount(0), ucount(0){}
    int getLCount(){return lcount;}
    int getUCount(){return ucount;}
    int getBCount(){return bcount;}
    ~Counter(){}
};

class Printer: public Visitor{
  public:
    void visit(Leaf& l){
      cout << "Leaf : " << l.getData() << endl;
    }
    void visit(Unary& u){
      cout << "Unary: " << u.getData() << endl;
    }
    void visit(Binary& b){
      cout << "Binary: " << b.getData() << endl;
    }
    ~Printer(){}
};

int main(){
    Tree * tp = new Unary("foo", new Binary("bar", new Unary("baz", new Leaf("taco")), new Binary("bat", new Leaf ("burrito"), new Unary("cat", new Leaf("pez")))));
    Counter c;
    tp->accept(c);
    cout << c.getLCount() << endl;
    cout << c.getUCount() << endl;
    cout << c.getBCount() << endl;
    Printer p;
    tp->accept(p);
}
