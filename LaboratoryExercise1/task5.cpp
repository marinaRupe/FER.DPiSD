#include <iostream>

using namespace std;
typedef int (***pfun)();

class B{
public:
    virtual int prva()=0;
    virtual int druga()=0;
};

class D: public B{
public:
    virtual int prva(){return 0;}
    virtual int druga(){return 42;}
};

void callVirtualFunctions(B* pb) {
    pfun vTable = (int (***)())pb;

    cout << "Prva funkcija: " << vTable[0][0]() << endl;
    cout << "Druga funkcija: " << vTable[0][1]() << endl;
}

int main5() {
    B* b = new D();
    callVirtualFunctions(b);
    delete b;
    return 0;
}

