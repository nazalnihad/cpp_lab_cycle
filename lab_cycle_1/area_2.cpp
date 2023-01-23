#include <iostream>

class square_area
{
    private:
    int side;
    public:
    double area(int a)
    {
        side = a;
        return a*a;
    }  
};

class triangle_area
{
    private:
    int base,height;
    public:
    double area(int b, int h)
    {
        base = b;
        height = h;
        return (b*h)/2;
    }  
};

class circle_area
{
    private:
    float pi = 3.14;
    int radius;
    public:
    double area(int r )
    {
        radius = r;
        return pi*r*r;
    }  
};

class trapezium_area
{
    private:
    int pll_side1 , pll_side2 , height;
    public:
    double area(int a,int b,int h)
    {
        pll_side1 = a;
        pll_side2 = b;
        height = h;
        return ((a+b)*h)/2;
    }  
};

class rectangle_area
{
    private:
    int length, breadth;
    public:
    double area(int l,int b)
    {   
        length = l;
        breadth = b;
        return l*b;
    }  
};

int main()
{

 square_area sq;
 int side;
 std::cout<<"\nenter side : ";
 std::cin>>side;
 std::cout<<"Area of the square is : "<<sq.area(side)<<"\n";

 triangle_area t;
 int base,height;
 std::cout<<"\nenter base : ";
 std::cin>>base;
 std::cout<<"enter height : ";
 std::cin>>height;
 std::cout<<"area of the triangle is : "<<t.area(base,height)<<"\n";

 circle_area c;
 int radius;
 std::cout<<"\nenter the radius : ";
 std::cin>>radius;
 std::cout<<"area of the circle is : "<<c.area(radius)<<"\n";

 trapezium_area tp;
 int pll_side1 , pll_side2 , height_t;
 std::cout<<"\nenter the parallel side1 : ";
 std::cin>>pll_side1;
 std::cout<<"enter the parallel side2 : ";
 std::cin>>pll_side2;
 std::cout<<"enter the height : ";
 std::cin>>height_t;
 std::cout<<"area of the trapezium is : "<< tp.area(pll_side1,pll_side2,height_t)<<"\n";

 rectangle_area ect;
 int length, breadth;
 std::cout<<"\nenter the length : ";
 std::cin>>length;
 std::cout<<"enter the breadth : ";
 std::cin>>breadth;
 std::cout<<"area of the rectangle is : "<<ect.area(length,breadth)<<"\n";
 
 return 0;
}



    