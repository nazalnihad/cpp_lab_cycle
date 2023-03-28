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
    int choice;
    while (start)
    {
        std::cout << "1 - to operate on float(decimal) values :\n2 - to operate on integer values : \n3 - to quit\n : ";
        std::cin >> choice;
        if (choice == 1)
        {
            int float_cont = 1;
            calculator<float> a;
            int float_option;
            do
            {
                std::cout << "\n1 - to add\n2 - to subtract\n3 - to multiply\n4 - to divide\n : ";
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

                default:
                    std::cout << "invalid option \n";
                }
                std::cout << "\n1 - continue\nany other number to exit \n : ";
                std::cin >> float_cont;
            } while (float_cont == 1);
        }
        else if (choice == 2)
        {
            calculator<int> b;
            int int_option;
            int int_cont = 1;
            do
            {
                std::cout << "\n1 - to add\n2 - to subtract\n3 - to multiply\n4 - to divide\n : ";
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

                default:
                    std::cout << "invalid option \n";
                }
                std::cout << "\n1 - continue\nany other number to exit \n : ";
                std::cin >> int_cont;
            } while (int_cont == 1);
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
    return 0;
}