#include <iostream>
using namespace std;

class CoolClass{
public:
  virtual void set(int x){x_=x;};
  virtual int get(){return x_;};
private:
  int x_;
};

class PlainOldClass{
public:
  void set(int x){x_=x;};
  int get(){return x_;};
private:
  int x_;
};

int main3() {
    cout << "Size of PlainOldClass: " << sizeof(PlainOldClass) << endl;  // 4 bytes
    cout << "Size of CoolClass: " << sizeof(CoolClass) << endl;  // 16 bytes

    return 0;
}