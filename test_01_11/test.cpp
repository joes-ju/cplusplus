#include<iostream>
using namespace std;

class Person
{
public:
  virtual void BuyTicket(){
    cout<<"买票-全价"<<endl;
  }

  virtual void func1(){
    cout<<"Person::func1()"<<endl;
  }
};

class Student:public Person{
public:
  virtual void BuyTicket(){
    cout<<"买票-半价"<<endl;
  }

  virtual void func1(){
    cout<<"Student::func1()"<<endl;
  }
};

void Func(Person& people){
  people.BuyTicket();
}

class A{
public:
  virtual void func1(){
    cout<<"A::func1()"<<endl;
  }

public:
  int _a;
};

class B:virtual public A{
public:
  virtual void func1(){
    cout<<"B::func1()"<<endl;
  }

  void func2(){
    cout<<"B::func2()"<<endl;
  }

public:
  int _b;
};

class C:virtual public A{
public:
  virtual void func1(){
    cout<<"C::func1()"<<endl;
  }

  void func3(){
    cout<<"C::func3()"<<endl;
  }

public:
  int _c;
};

class D:public B,public C{
public:
  virtual void func1(){
    cout<<"D::func1()"<<endl;
  }

  void func4(){
    cout<<"D::func4()"<<endl;
  }

public:
  int _d;
};

void test_polymorphism01(){
  Person ps;
  Student st;
  Func(ps);
  Func(st);
}

void test_polymorphism02(){
  D d;
  d.B::_a = 1;
  d.C::_a = 2;
  d._c = 3;
  d._d = 4;
}

int main()
{
  test_polymorphism01();
  return 0;
}
