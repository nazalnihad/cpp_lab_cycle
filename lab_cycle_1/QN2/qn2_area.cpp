#include <iostream>

float PI = 3.14;

int area(int side) // square
{
    return side * side;
}

int area(int length, int width) // rectangle
{
    return length * width;
}

float area(float base, float height) // triangle
{
    return 0.5 * base * height;
}

float area(float radius) // circle
{
    return PI * radius * radius;
}

float area(float pll_side1, float pll_side2, float height) // paralellogram
{
    return ((pll_side1 + pll_side2) * height) / 2;
}

int main()
{
    int choice;
    do
    {
        std::cout << "Select a shape:\n";
        std::cout << "1. Square\n";
        std::cout << "2. Rectangle\n";
        std::cout << "3. Triangle\n";
        std::cout << "4. Circle\n";
        std::cout << "5. paralellogram\n";
        std::cout << "6. Exit\n";
        std::cout << " : ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int side;
            std::cout << "Enter the length of a side: ";
            std::cin >> side;
            std::cout << "Area of the square is " << area(side) << "\n";
            break;
        }
        case 2:
        {
            int length, width;
            std::cout << "Enter the length and width: ";
            std::cin >> length >> width;
            std::cout << "Area of the rectangle is " << area(length, width) << "\n";
            break;
        }
        case 3:
        {
            float base, height;
            std::cout << "Enter the base and height: ";
            std::cin >> base >> height;
            std::cout << "Area of the triangle is " << area(base, height) << "\n";
            break;
        }
        case 4:
        {
            float radius;
            std::cout << "Enter the radius: ";
            std::cin >> radius;
            std::cout << "Area of the circle is " << area(radius) << "\n";
            break;
        }
        case 5:
        {
            float pll_side1, pll_side2, height;
            std::cout << "Enter parallel side 1: ";
            std::cin >> pll_side1;
            std::cout << "Enter parallel side 2: ";
            std::cin >> pll_side2;
            std::cout << "Enter height: ";
            std::cin >> height;
            std::cout << "Area of the paralellogram is " << area(pll_side1, pll_side2, height) << "\n";
            break;
        }
        case 6:
        {
            return 0;
            break;
        }
        default:
        {
            std::cout << "Invalid choice. Please try again. \n";
            break;
        }
        }

        std::cout << "\n";
    } while (choice != 6);

    return 0;
}
