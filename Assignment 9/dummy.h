
void dummyTest();

class Dummy{
public:
    int* num;
    Dummy();
    ~Dummy();
    //Kopi konstruktør
    Dummy(const Dummy& dummy);
    //overloading av tilordning
    Dummy& operator=(const Dummy& dummy);
    
};