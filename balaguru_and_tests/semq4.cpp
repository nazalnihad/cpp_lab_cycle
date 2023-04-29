#include <iostream>
using namespace std;
class shape
{
protected:
    double val1, val2;
    float area;

public:
    void get_data(int x, int y)
    {
        val1 = x;
        val2 = y;
    }
    virtual void display_area()
    {
        cout << "the are of the shape is : ";
    }
};

class triangle : public shape
{
public:
    void get_tri()
    {
        int base, height;
        cout << "Enter the base : ";
        cin >> base;
        cout << "Enter the height : ";
        cin >> height;
        get_data(base, height);
    }
    void display_area()
    {
        area = val1 * val2 * 1 / 2;
        cout << "Area of the triangle = " << area << "\n";
    }
};

class rectangle : public shape
{
public:
    void get_rect()
    {
        int length, breadth;
        cout << "Enter the length : ";
        cin >> length;
        cout << "Enter the breadth : ";
        cin >> breadth;
        get_data(length, breadth);
    }
    void display_area()
    {
        area = val1 * val2;
        cout << "Area of the triangle = " << area << "\n";
    }
};
int main()
{
    triangle a;
    a.get_tri();
    a.display_area();
    rectangle r;
    r.get_rect();
    r.display_area();
    return 0;
}