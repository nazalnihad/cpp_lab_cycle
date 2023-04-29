#include <iostream>
using namespace std;
class base
{
    int x, y;

public:
    base() {}
    base(int xval) : x(xval), y(2 * xval) {}
    void show()
    {
        cout << "X value = " << x << "\nY value = " << y << "\n";
    }
}; 
int main()
{
    int x = 20;
    base a;
    a = x;
    a.show();
    return 0;
}