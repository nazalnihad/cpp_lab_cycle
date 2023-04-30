#include <iostream>

template <class T>
class calculator
{
    T num1, num2;

public:
    calculator()
    {
        std::cout << "\nEnter the two numbers you want to operate on : \n";
        std::cout << "Enter number 1 : ";
        std::cin >> num1;
        std::cout << "Enter number 2 : ";
        std::cin >> num2;
    }
    void add();
    T subtract();
    T multiply();
    T divide();
};
template <class T>
void calculator<T>::add()
{
    std::cout << "sum is : " << num1 + num2 << "\n";
}
template <class T>
T calculator<T>::subtract()
{
    std::cout << "difference is : " << num1 - num2 << "\n";
}
template <class T>
T calculator<T>::multiply()
{
    std::cout << "Product is : " << num1 * num2 << "\n";
}
template <class T>
T calculator<T>::divide()
{
    if (num2 == 0)
    {
        std::cout << "Error 0 divison \n";
    }
    else
    {
        std::cout << "Division is " << num1 / num2 << "\n";
    }
}
int main()
{
    bool start = true;
    int ask;
    int choice;
    while (start)
    {
        std::cout << "\n1 - to operate on float(decimal) values :\n2 - to operate on integer values : \n3 - to quit\n : ";
        std::cin >> choice;
        if (choice == 1)
        {
            calculator<float> a; // t is float
            int float_option;
            do
            {
                std::cout << "\n1 - to add\n2 - to subtract\n3 - to multiply\n4 - to divide \n5 - to exit and change option  :  ";
                std::cin >> float_option;
                switch (float_option)
                {
                case 1:
                    a.add();
                    break;

                case 2:
                    a.subtract();
                    break;

                case 3:
                    a.multiply();
                    break;

                case 4:
                    a.divide();
                    break;

                case 5:
                    std::cout << "\n1 - continue\nany other number to exit \n : ";
                    std::cin >> ask;
                    if (ask != 1)
                    {
                        start = false;
                    }

                    break;

                default:
                    std::cout << "invalid option \n";
                }

            } while (float_option != 5);
        }
        else if (choice == 2)
        {
            calculator<int> b; // t is int
            int int_option;
            do
            {
                std::cout << "\n1 - to add\n2 - to subtract\n3 - to multiply\n4 - to divide \n5 - to exit or change option \n : ";
                std::cin >> int_option;
                switch (int_option)
                {
                case 1:
                    b.add();
                    break;

                case 2:
                    b.subtract();
                    break;

                case 3:
                    b.multiply();
                    break;

                case 4:
                    b.divide();
                    break;

                case 5:
                    std::cout << "\n1 - continue with another number \nany other number to exit \n : ";
                    std::cin >> ask;
                    if (ask != 1)
                    {
                        start = false;
                    }

                    break;

                default:
                    std::cout << "invalid option \n";
                }
            } while (int_option != 5);
        }
        else if (choice == 3)
        {
            start = false;
        }
        else
        {
            std::cout << "pls choose a valid operation \n";
        }
    }
    std::cout << "\nExiting....";
    return 0;
}