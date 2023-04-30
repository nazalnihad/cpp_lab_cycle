#include <iostream>
class shapes
{
protected:
    float area;

public:
    virtual void get_area(){};
    virtual void display()
    {
        std::cout << "The area is : " << area << "\n";
    }
};

class circle : public shapes
{
    int radius;
    float pi = 3.14;

public:
    void get_area()
    {
        std::cout << "\nEnter the radius of the circle : ";
        std::cin >> radius;
        area = radius * radius * pi;
    }
};

class square : public shapes
{
    int side;

public:
    void get_area()
    {
        std::cout << "\nEnter the side of the square : ";
        std::cin >> side;
        area = side * side;
    }
};

class ellipse : public shapes
{
    int major_axis, minor_axis;
    float pi = 3.14;

public:
    void get_area()
    {
        std::cout << "\nEnter the major axis : ";
        std::cin >> major_axis;
        std::cout << "Enter the minor axis : ";
        std::cin >> minor_axis;

        area = pi * major_axis * minor_axis;
    }
};

class rectangle : public shapes
{
    int length, breadth;

public:
    void get_area()
    {
        std::cout << "\nEnter the length of the triangle : ";
        std::cin >> length;
        std::cout << "Enter the breadth of the triangel : ";
        std::cin >> breadth;

        area = length * breadth;
    }
};

int main()
{
    int choice = 1;

    while (choice >= 1 && choice <= 5)
    {
        shapes *ptr; // base class pointer for calling/pointing all it's derived classes

        std::cout << "\nEnter the choice to find area \n";
        std::cout << "1 - for circle\n";
        std::cout << "2 - for square\n";
        std::cout << "3 - for ellipse\n";
        std::cout << "4 - for rectangle\n";
        std::cout << "5 - to quit\n : ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            ptr = new circle;
            ptr->get_area();
            ptr->display();
            break;

        case 2:
            ptr = new square;
            ptr->get_area();
            ptr->display();
            break;

        case 3:
            ptr = new ellipse;
            ptr->get_area();
            ptr->display();
            break;

        case 4:
            ptr = new rectangle;
            ptr->get_area();
            ptr->display();
            break;

        case 5:
            std::cout << "\nExiting..";
            return 0;

        default:
            std::cout << "Enter a valid value \n";
            break;
        }
    }
    return 0;
}