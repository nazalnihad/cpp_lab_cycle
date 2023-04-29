#include <iostream>
using namespace std;

void prime(int x, int y)
{
    int f = 0;
    if (x > 2)
    {
        for (int i = x; i < y; i++)
        {
            f = 0;
            for (int j = 2; j <= i / 2; j++)
            {
                if (i % j == 0)
                {
                    f += 1;
                }
            }
            if (f == 0)
            {
                cout << i << "\n";
            }
        }
    }
}
int main()
{
    prime(3, 20);
    return 0;
}