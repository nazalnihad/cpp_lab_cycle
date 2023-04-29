#include <iostream>
using namespace std;
int factorial(int x)
{
    int p = 1;
    for (int i = 1; i <= x; i++)
    {
        p = p * i;
        // cout << p << endl;
    }
    return p;
}

void ex(int x)
{
    float k = 1, p;
    for (int i = 1; i <= x; i++)
    {
        p = 1;
        for (int j = 1; j <= i; j++)
        {
            p = p * x;
        }
        p = p / factorial(i);
        k = k + p;
        // cout << k << endl;
    }
    cout << "e^" << x << " = " << k << endl;
}
int main()
{
    int x;
    cout << "Enter the no e^x -> x value to find : ";
    cin >> x;
    // factorial(4);
    ex(x);
    return 0;
}