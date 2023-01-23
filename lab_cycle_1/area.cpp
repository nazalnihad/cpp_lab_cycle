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
    int shape;
do
{
 
 std::cout<<"\n Which area do you want to find : "<<"\n square-1"<<"\n triangle-2"
 <<"\n circle-3"<<"\n trapezium-4"<<"\n rectangle-5"<<"\n : ";
 std::cin>>shape;

 switch (shape)
 {
 case 1:
 {
    square_area square;
    int side;
    std::cout<<"\n"<<"enter side : ";
    std::cin>>side;
    std::cout<<"Area of the square is : "<<square.area(side)<<"\n";
    break;
 }
 case 2:
 {
    triangle_area triangle;
    int base,height;
    std::cout<<"\n"<<"enter base : ";
    std::cin>>base;
    std::cout<<"enter height : ";
    std::cin>>height;
    std::cout<<"area of the triangle is : "<<triangle.area(base,height)<<"\n";
    break;
 }
 case 3:
 {
    circle_area circle;
    int radius;
    std::cout<<"\n"<<"enter the radius : ";
    std::cin>>radius;
    std::cout<<"area of the circle is : "<<circle.area(radius)<<"\n";
    break;
 }
 case 4:
 {
    trapezium_area trapezium;
    int pll_side1 , pll_side2 , height_t;
    std::cout<<"\n"<<"enter the parallel side1 : ";
    std::cin>>pll_side1;
    std::cout<<"enter the parallel side2 : ";
    std::cin>>pll_side2;
    std::cout<<"enter the height : ";
    std::cin>>height_t;
    std::cout<<"area of the trapezium is : "<< trapezium.area(pll_side1,pll_side2,height_t)<<"\n";
    break;
 }
 case 5:
 {
    rectangle_area rectangle;
    int length, breadth;
    std::cout<<"\n"<<"enter the length : ";
    std::cin>>length;
    std::cout<<"enter the breadth : ";
    std::cin>>breadth;
    std::cout<<"area of the rectangle is : "<<rectangle.area(length,breadth)<<"\n";
    break;
 }

 default:
 {
    std::cout<<"pls enter a valid number \n";
    break;
 }
 }
   
} while (shape != 1 , shape != 2,shape != 3,shape != 4,shape != 5);


 return 0;
}



    