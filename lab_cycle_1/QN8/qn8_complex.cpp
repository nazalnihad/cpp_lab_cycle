#include <iostream>
class complex
{
    float real, imag;

public:
    complex()
    {
        real = 0;
        imag = 0;
    }
    complex(float); // overloading constructors
    complex(float, float);
    complex complex_add(complex &, complex &);
    void display();
};
complex::complex(float a) // constructor with 1 value
{
    real = a;
    imag = a;
}
complex::complex(float a, float b) // constructor with 2 values
{
    real = a;
    imag = b;
}
complex complex::complex_add(complex &a, complex &b)
{
    complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    if (c.imag > 0)
    {
        std::cout << "\nsum of complex is " << c.real << "+" << c.imag << "i \n";
    }
    else
    {
        std::cout << "\nsum of complex is " << c.real << c.imag << "i \n";
    }
    return c;
}
void complex::display()
{
    if (imag > 0)
    {
        std::cout << "\n"
                  << real << "+" << imag << "i ";
    }
    else
    {
        std::cout << "\n"
                  << real << imag << "i ";
    }
}
int main()
{
    float a, b, c, d;
    complex result;
    int ask;
    do
    {
        int choice;
        std::cout << "\n==== complex 1 ====\n";
        std::cout << "enter the single no to real and image part : ";
        std::cin >> a;

        complex obj1(a);

        std::cout << "\n==== complex 2 ====\n";
        std::cout << "enter the real part : ";
        std::cin >> c;
        std::cout << "enter the imaginary part : ";
        std::cin >> d;

        complex obj2(c, d);
        do
        {
            std::cout << "\n1 - to display the complex numbers \n2 - to add the complex numbers \n3 - exit \n : ";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                obj1.display();
                obj2.display();
                break;

            case 2:
                result.complex_add(obj1, obj2);
                break;

            case 3:
                std::cout << "1 - to continue with another values \n any other key to quit \n : ";
                std::cin >> ask;
            }
        } while (choice != 3);
    } while (ask == 1);
    std::cout << "\nExiting..";
    return 0;
}