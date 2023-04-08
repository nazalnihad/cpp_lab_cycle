#include <iostream>
using namespace std;
void exchange(int &x, int &y);
int main()
{
    int a = 10, b = 20;
    cout << "X = " << a << "\n";
    cout << "Y = " << b << "\n";

    cout << "Exchange \n";
    exchange(a, b);
    cout << "X = " << a << "\n";
    cout << "Y = " << b << "\n";
    return 0;
}
void exchange(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}