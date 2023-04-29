#include <iostream>
using namespace std;
class base
{
    int x;

public:
    void getx(int val) { x = val; }
    operator int()
    {
        return x;
    }
};
int main()
{
    base a;
    a.getx(5);
    int y;
    y = a;
    cout << "y = " << y;
    return 0;
}