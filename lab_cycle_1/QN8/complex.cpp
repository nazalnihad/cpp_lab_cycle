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
    complex(float); //overloading constructors
    complex(float,float);
    void complex_add(complex &,complex &);
    void display();
};
complex::complex(float a) //constructor with 1 value
{
    real = a;
    imag = a;
}
complex::complex(float a,float b) //constructor with 2 values
{
    real = a;
    imag = b;
}
void complex::complex_add(complex &a,complex &b)
{
    complex c;
    c.real = a.real+b.real;
    c.imag = a.imag+b.imag;
    if(c.imag>0){
    std::cout<<"\nsum of matrix is "<<c.real<<"+"<<c.imag<<"i \n";
    }
    else{
        std::cout<<"\nsum of matrix is "<<c.real<<c.imag<<"i \n";
    }
}
void complex::display()
{
    if(imag>0)
    {
    std::cout<<real<<"+"<<imag<<"i";
    }
    else{
        std::cout<<real<<imag<<"i";
    }
}
int main()
{
    float a,b,c,d;
    std::cout<<"\n==== complex 1 ====\n";
    std::cout<<"enter the single no to real and image part : ";
    std::cin>>a;
    
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