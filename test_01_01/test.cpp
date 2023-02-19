#include<iostream>

template<class T>
void Swap(T& a,T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 11, b = 22;
    Swap(a,b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    return 0;
}