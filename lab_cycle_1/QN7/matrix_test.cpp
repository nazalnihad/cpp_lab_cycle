#include <iostream>
class matrix
{
    int **p;
    int rows, cols;

public:
    matrix() {}
    matrix(int, int);
    void getmatrix();
    void display();
    void matrix_add(matrix &, matrix &);
    void matrix_mult(matrix &, matrix &);
    void matrix_transpose(matrix &);
    ~matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete p[i];
        }
        delete p;
        std::cout << "memory release\n";
    }
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

void matrix::getmatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << "Enter value at [" << i + 1 << "][" << j + 1 << "] : ";
            std::cin >> p[i][j];
        }
    }
}

void matrix::display()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << p[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void matrix::matrix_add(matrix &a, matrix &b)
{
    if (a.rows == b.rows && a.cols == b.cols)
    {
        for (int i = 0; i < a.rows; i++)
        {
            for (int j = 0; j < a.cols; j++)
            {
                p[i][j] = a.p[i][j] + b.p[i][j];
            }
        }
    }
}

void matrix::matrix_mult(matrix &a, matrix &b)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < b.cols; j++)
        {
            p[i][j] = 0;

            for (int k = 0; k < a.cols; k++)
            {
                p[i][j] = p[i][j] + a.p[i][k] * b.p[k][j];
            }
        }
    }
}
void matrix::matrix_transpose(matrix &a)
{
}
int main()
{
    int r1, c1, r2, c2;
    int choice;
    matrix c, d;
    std::cout << "Enter no of rows : ";
    std::cin >> r1;
    std::cout << "Enter no of cols : ";
    std::cin >> c1;

    matrix a(r1, c1);
    a.getmatrix();
    a.display();

    std::cout << "Enter no of rows : ";
    std::cin >> r2;
    std::cout << "Enter no of cols : ";
    std::cin >> c2;

    matrix b(r2, c2);
    b.getmatrix();
    b.display();

    do
    {
        std::cout << "\n1 - to matrix_add \n2 - to multiply \n : ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            c(r1, c1);
            c.matrix_add(a, b);
            c.display();
            break;

        case 2:
            d(r1, c2);
            d.matrix_mult(a, b);
            d.display();
            break;

        default:
            std::cout << "Enter a valid choice \n";
            break;
        }
    } while (choice != 0);
    return 0;
}