#include <iostream>
bool checkprime(int x)
{
    if (x > 2)
    {
        for (int i = 2; i < x; i++)
        {
            for (int k = x; k > i; k--)
            {
                if (k % i == 0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    }
    else if (x == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int x;
    std::cout << "Enter range : ";
    std::cin >> x;
    for (int i = 0; i < x; i++)
    {
        if (checkprime(i))
        {
            std::cout << i << '\n';
        }
    }
    return 0;
}