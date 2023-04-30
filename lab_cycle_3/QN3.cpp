#include <iostream>
float zeroDivision(float x, float y)
{
    if (y == 0)
    {
        throw "Zero division error !";
    }
    else
    {
        return x / y;
    }
}
int main()
{
    float x, y;
    int choice;
    std::cout << "\n1 - to start \nany other key to quit \n : ";
    std::cin >> choice;
    do
    {
        std::cout << "\nEnter X in x/y : ";
        std::cin >> x;

        std::cout << "\nEnter Y in x/y : ";
        std::cin >> y;
        try
        {
            float result = zeroDivision(x, y);
            std::cout << "\nResult = " << result << "\n";
        }
        catch (const char *s)
        {
            std::cout << s << '\n';
        }

        std::cout << "\n1 - continue \nany other key to quit \n : ";
        std::cin >> choice;

    } while (choice == 1);
    std::cout << "\nExiting..";
    return 0;
}