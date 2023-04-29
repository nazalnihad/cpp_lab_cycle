#include <iostream>
using namespace std;
float zero(int x, int y)
{
    try
    {
        if (y != 0)
        {
            return x / y;
        }
        else
        {
            throw "Zero division error \n";
        }
    }
    catch (const char *msg)
    {
        cout << msg << "\n";
    }
}
int main()
{
    int x, y;
    cout << "X = ";
    cin >> x;
    cout << "Y = ";
    cin >> y;

    float result = zero(x, y);
    cout << result;
    return 0;
}