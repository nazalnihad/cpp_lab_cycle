#include <iostream>
using namespace std;
template <typename t>
t swp(t &x, t &y)
{
    cout << "Before swap \n x = " << x << "\ny = " << y << "\n";
    t temp;
    temp = x;
    x = y;
    y = temp;
    cout << "After swap \n x = " << x << "\ny = " << y << "\n";
    return temp;
}
int main()
{
    // swap<double>(5.2, 3.9);
    int x = 5;
    int y = 3;
    swp<int>(x, y);
    return 0;
}