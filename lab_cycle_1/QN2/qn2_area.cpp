#include <iostream>

class area_shapes{
    private:
    int side , base , height , pll_side1 , pll_side2  ;
    float  radius , length ,breadth ,pi=3.14 ;
    public:
    int area(int);
    int area(int,int);
    float area(float);
    float area(float,float);
    int area(int,int,int);
};

int area_shapes::area(int a) //square area
{
    side = a;
    return a*a;     
}

int area_shapes::area(int b,int h)
{
    base = b;
    height = h;
    return (b*h)/2;
}

float area_shapes::area(float r)
{
    radius = r;
    return pi*r*r;
}

float area_shapes::area(float l,float b)
{
    length = l;
    breadth = b;
    return l*b;
}

int area_shapes::area(int pl_1,int pl_2,int pl_h)
{
    pll_side1 = pl_1;
    pll_side2 = pl_2;
    height = pl_h;
    return ((pl_1+pl_2)*pl_h)/2;
}

int main()
{

 area_shapes square;
 int side;
 std::cout<<"\n-- Area of square --";
 std::cout<<"\nenter side : ";
 std::cin>>side;
 std::cout<<"Area of the square is : "<<square.area(side)<<"\n";

 area_shapes t;
 int base,height;
 std::cout<<"\n-- Area of triangle --";
 std::cout<<"\nenter base : ";
 std::cin>>base;
 std::cout<<"enter height : ";
 std::cin>>height;
 std::cout<<"area of the triangle is : "<<t.area(base,height)<<"\n";

 area_shapes c;
 int radius;
 std::cout<<"\n-- Area of circle --";
 std::cout<<"\nenter the radius : ";
 std::cin>>radius;
 std::cout<<"area of the circle is : "<<c.area(radius)<<"\n";

 area_shapes tp;
 int pll_side1 , pll_side2 , height_t;
 std::cout<<"\n-- Area of trapezium --";
 std::cout<<"\nenter the parallel side1 : ";
 std::cin>>pll_side1;
 std::cout<<"enter the parallel side2 : ";
 std::cin>>pll_side2;
 std::cout<<"enter the height : ";
 std::cin>>height_t;
 std::cout<<"area of the trapezium is : "<< tp.area(pll_side1,pll_side2,height_t)<<"\n";

 area_shapes ect;
 int length, breadth;
 std::cout<<"\n-- Area of rectangle --";
 std::cout<<"\nenter the length : ";
 std::cin>>length;
 std::cout<<"enter the breadth : ";
 std::cin>>breadth;
 std::cout<<"area of the rectangle is : "<<ect.area(length,breadth)<<"\n";
 
 return 0;
}
