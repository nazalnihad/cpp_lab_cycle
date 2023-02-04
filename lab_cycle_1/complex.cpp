#include <iostream>
class complex
{
    float real,imag;
    public:
    complex()
    {
        real = 0;
        imag = 0;
    }
    complex(float);
    complex(float,float);
    void complex_add(complex &,complex &);
    void display();
};
complex::complex(float a)
{
    real = a;
    imag = a;
}
complex::complex(float a,float b)
{
    real = a;
    imag = b;
}
void complex::complex_add(complex &a,complex &b)
{
    complex c;
    c.real = a.real+b.real;
    c.imag = a.imag+b.imag;
    
    std::cout<<"\nsum of matrix is "<<c.real<<"+"<<c.imag<<"i";
}
void complex::display()
{
    std::cout<<real<<"+"<<imag<<"i";
}
int main()
{
    float a,b,c,d;
    std::cout<<"\n==== complex 1 ====\n";
    std::cout<<"enter the real part : ";
    std::cin>>a;
    std::cout<<"enter the imaginary part : ";
    std::cin>>b;
    
    complex obj1(a);
    obj1.display();
    
    std::cout<<"\n==== complex 2 ====\n";
    std::cout<<"enter the real part : ";
    std::cin>>c;
    std::cout<<"enter the imaginary part : ";
    std::cin>>d;
    
    complex obj2(c,d);
    obj2.display();
    complex result;
    result.complex_add(obj1,obj2);
    
    
    return 0;
}