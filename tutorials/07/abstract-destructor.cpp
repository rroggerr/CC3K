class AbstractClass{
  int * data;  
 protected:
  AbstractClass():data(new int[10]){}
  virtual ~AbstractClass()=0;
};

AbstractClass::~AbstractClass(){delete [] data;}

