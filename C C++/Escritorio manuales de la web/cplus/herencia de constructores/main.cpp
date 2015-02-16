#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout<<"Constructor A\n";
    }
};
class B
{
public:
    B()
    {
        cout<<"Constructor B\n";
    }
};
class C
{
public:
    C()
    {
        cout<<"Constructor C\n";
    }
};
class D:A
{
public:
    B c;
    C d;
    D()
    {
        cout<<"Constructor D\n";
    }
};
int main(void)
{
    D d;
}
