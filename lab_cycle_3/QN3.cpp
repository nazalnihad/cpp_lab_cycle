#include <iostream>
float zeroDivision(float x, float y)
{
    if (y == 0)
    {
        throw "Zero division error !";
    }
    return x / y;
}
int main()
{
    float x, y;
    std::cout << "Enter X in x/y : ";
    std::cin >> x;
    while (true)
    {
        std::cout << "\nEnter Y in x/y : ";
        std::cin >> y;
        try
        {
            float result = zeroDivision(x, y);
            std::cout << "Result = " << result << "\n";
            break;
        }
        catch (const char *s)
        {
            std::cout << s << '\n';
        }
    }
    return 0;
}