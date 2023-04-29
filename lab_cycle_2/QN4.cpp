#include <iostream>
class matrix
{
    int **p;
    int rows, cols;

public:
    matrix() {}
    matrix(int, int);
    void getelement(int, int, int);
    int putelement(int, int);
    matrix getmatrix();
    matrix operator+(matrix &);
    matrix operator*(matrix &);
    void display();
};
matrix::matrix(int x, int y)
{
    rows = x;
    cols = y;
    p = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        p[i] = new int[cols];
    }
}
void matrix::getelement(int x, int y, int value)
{
    p[x][y] = value;
}
int matrix::putelement(int x, int y)
{
    return p[x][y];
}
matrix matrix::getmatrix()
{
    int value;

    for (int i = 0; i < rows; i++)
    {
        std::cout << "ROW " << i + 1 << "\n";
        for (int j = 0; j < cols; j++)
        {
            std::cout << "Enter value at [" << i << "][" << j << "] : ";
            std::cin >> value;
            getelement(i, j, value);
        }
    }
    // return a;
}
void matrix::display()
{
    std::cout << "\n========\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << putelement(i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "========\n";
}
matrix matrix::operator+(matrix &a)
{
    int value;

    matrix add(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            value = a.putelement(i, j) + putelement(i, j);
            add.getelement(i, j, value);
        }
    }
    return add;
}
matrix matrix::operator*(matrix &a)
{

    matrix mult(rows, a.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            int value = 0;
            for (int k = 0; k < a.rows; k++)
            {
                value = value + putelement(i, k) * a.putelement(k, j);
                mult.getelement(i, j, value);
            }
        }
    }
    return mult;
}
int main()
{
    matrix sum, pdt;
    int choice, ask;
    int r1, r2, c1, c2;
    do
    {
        std::cout << "\nEnter the first matrix \n";
        std::cout << "enter no of rows : ";
        std::cin >> r1;
        std::cout << "enter no of cols : ";
        std::cin >> c1;
        matrix a(r1, c1);
        a.getmatrix();

        std::cout << "\nEnter the second matrix \n";
        std::cout << "enter no of rows : ";
        std::cin >> r2;
        std::cout << "enter no of cols : ";
        std::cin >> c2;
        matrix b(r2, c2);
        b.getmatrix();
        do
        {
            std::cout << "\n1 - to display the matrices \n2 - to add the matrices \n3 - to multiply matrices \n4 - to exit \n : ";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                std::cout << "\nThe entered matrices are\n";
                a.display();
                b.display();
                break;

            case 2:
                if (r1 == r2 && c1 == c2)
                {
                    sum = a + b;
                    sum.display();
                }
                else
                {
                    std::cout << "\nrows and cols must be equal for addition\n";
                }
                break;

            case 3:
                if (c1 == r2)
                {
                    pdt = a * b;
                    pdt.display();
                }
                else
                {
                    std::cout << "\ncols of first matrix must be equal to rows of second matrix\n";
                }
                break;

            case 4:
                std::cout << "\n1 - to continue with different values \nany other key to quit \n : ";
                std::cin >> ask;
                continue;

            default:
                std::cout << "\nEnter a valid value ";
            }
        } while (choice != 4);
    } while (ask == 1);
    std::cout << "\nExiting...";
    return 0;
}