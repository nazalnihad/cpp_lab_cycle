#include <iostream>
class complex
{
    int real, imag;

public:
    complex()
    {
        real = 0;
        imag = 0;
    }
    int getelements();
    void display();
    friend complex add(complex, complex); // friend function
};

int complex::getelements()
{
    std::cout << "\nenter the real part : ";
    std::cin >> real;
    std::cout << "enter the imaginary part : ";
    std::cin >> imag;
}
void complex::display()
{
    if (imag < 0)
        std::cout << "\n"
                  << real << imag << "i\n";
    else
    {
        std::cout << "\n"
                  << real << " + " << imag << "i\n";
    }
}
complex add(complex a, complex b)
{
    complex temp;
    temp.real = a.real + b.real;
    temp.imag = a.imag + b.imag;
    return temp;
}
int main()
{
    int choice;
    std::cout << "Enter the 2 complex numbers \n";
    do
    {
        complex a, b, c;
        a.getelements();
        a.display();
        b.getelements();
        b.display();
        c = add(a, b);

        std::cout << "\nThe sum of the complex numbers is : ";
        c.display();

        std::cout << "\nEnter 1 to continue \nany other key to quit \n";
        std::cin >> choice;
        if (choice != 1)
        {
            std::cout << "\nExiting..";
            return 0;
        }
    } while (choice = 1);

    return 0;
}