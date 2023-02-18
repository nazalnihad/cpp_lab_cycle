#include <iostream>
class complex
{
    float real,imag;
    public:
    complex(){
        real = 0;
        imag = 0;
    }
    void getelements();
    void display();
    friend complex operator *(const complex&, const complex&);
    friend complex operator +(const complex& ,const complex&);
};
void complex::getelements()
{
    std::cout<<"Enter the real part : ";
    std::cin>>real;
    std::cout<<"Enter the imaginary part : ";
    std::cin>>imag;
}
void complex::display()
{
    if (imag>0)
    {
    std::cout<<real<<" + "<<imag<<"i\n";
    }
    else if(imag<0){
        std::cout<<real<<imag<<"i\n";
    }
    else if(real==0)
    {
        std::cout<<imag<<"\n";
    }
    else{
        std::cout<<real<<"\n";
    }
}
complex operator *(const complex &a,const complex &b)
{
    complex mult;
    mult.real = a.real*b.real - a.imag*b.imag;
    mult.imag = a.real*b.imag + b.real*a.imag;
    return mult;
}
complex operator +(const complex &a,const complex &b)
{
    complex temp;
    temp.real = a.real+b.real;
    temp.imag = a.imag+b.imag;
    return temp;
}
int main()
{
    complex a,b,c,d;
    std::cout<<"\n=== Complex number 1 ===\n";
    a.getelements();
    a.display();
    std::cout<<"\n=== Complex number 2 ===\n";
    b.getelements();
    b.display();
    int choice;
    std::cout<<"\nChoose what you want to do \n";
    do{
        std::cout<<"\n1 - to add the complex numbers\n2 - to multiply the complex numbers\n3 - to quit\n: ";
        std::cin>>choice;
        switch(choice){
            case 1:
            std::cout<<"\nThe sum of the complex number is \n";
            c = a+b;
            c.display();
            break;

            case 2:
            std::cout<<"\nThe product of the complex numbers is \n";
            d = a*b;
            d.display();
            break;

            case 3:
            exit(0);

            default:
            std::cout<<"Pls enter a valid value \n";
            break;
        }
    }while(choice !=3);

    return 0;
}