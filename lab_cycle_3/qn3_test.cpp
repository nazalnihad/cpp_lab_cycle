#include <iostream>
int main()
{
    float x, y;
    std::cout << "Enter the x/y values : ";
    std::cin >> x >> y;
    try
    {
        if (y == 0)
        {
            throw std::runtime_error("zero division error");
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "you got yourself an error buddy i.e : " << e.what() << "\n";
        return 1;
    }
    std::cout << x / y;
    return 0;
}