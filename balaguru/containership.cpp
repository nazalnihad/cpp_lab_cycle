#include <iostream>

class Point
{
private:
    int x, y;

public:
    Point(int xval, int yval) : x(xval), y(yval) {}
    int get_x() const { return x; }
    int get_y() const { return y; }
};

class Circle
{
private:
    Point center;
    int radius;

public:
    Circle(const Point &p, int r) : center(p), radius(r) {}
    const Point &get_center() const { return center; }
    int get_radius() const { return radius; }
};

int main()
{
    Point my_point(3, 4);
    Circle my_circle(my_point, 5);
    std::cout << "Circle center: (" << my_circle.get_center().get_x() << "," << my_circle.get_center().get_y() << ")" << std::endl;
    std::cout << "Circle radius: " << my_circle.get_radius() << std::endl;
    return 0;
}
