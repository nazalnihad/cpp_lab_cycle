#include <iostream>

class matrix
{
    int **p;
    int rows, cols;

public:
    matrix() {}
    matrix(int, int);
    void getMatrix();
    void displayMatrix();
    void sum(matrix &, matrix &);
    void multiply(matrix &, matrix &);
    void transpose();
    void trace();
    ~matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete p[i];
        }
        delete p;
        std::cout << "\nmemory released";
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
void matrix::getMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        std::cout << "Row " << i + 1 << "\n";
        for (int j = 0; j < cols; j++)
        {
            std::cout << "Enter value at [" << i + 1 << "][" << j + 1 << "] : ";
            std::cin >> p[i][j];
        }
    }
}
void matrix::displayMatrix()
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

void matrix::sum(matrix &a, matrix &b)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            p[i][j] = a.p[i][j] + b.p[i][j];
        }
    }
}

void matrix::multiply(matrix &a, matrix &b)
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

void matrix::transpose()
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            std::cout << p[j][i] << " ";
        }
        std::cout << "\n";
    }
}

void matrix::trace()
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            {
                sum += p[i][j];
            }
        }
    }
    std::cout << sum;
}
int main()
{
    int ask;
    std::cout << "\n1 - to start \nAny other key to quit\n : ";
    std::cin >> ask;

    while (ask == 1)
    {
        int r1, c1;
        std::cout << "\n===== matrix 1 ======\n";
        std::cout << "Enter no of rows : ";
        std::cin >> r1;
        std::cout << "Enter no of cols : ";
        std::cin >> c1;

        matrix a(r1, c1);
        a.getMatrix();

        int r2, c2;
        std::cout << "\n===== matrix 2 ======\n";
        std::cout << "Enter no of rows : ";
        std::cin >> r2;
        std::cout << "Enter no of cols : ";
        std::cin >> c2;

        matrix b(r2, c2);
        b.getMatrix();

        int choice;
        do
        {
            std::cout << "\n1 - to display the matrices \n2 - to add the matrices \n3 - to multiply \n4 - to get transpose \n5 - to get trace \n6 - to exit \n : ";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                std::cout << "\n===== matrix 1 ======\n";
                a.displayMatrix();
                std::cout << "\n===== matrix 2 ======\n";
                b.displayMatrix();
                break;

            case 2:
                if (r1 == r2 && c1 == c2)
                {
                    std::cout << "\nSum of the matrices is \n";
                    matrix add(r1, c1);
                    add.sum(a, b);
                    add.displayMatrix();
                }
                else
                {
                    std::cout << "\nRows and cols don't match\n";
                }
                break;

            case 3:
                if (c1 == r2)
                {
                    std::cout << "\nMultiplication of the matrices is\n";
                    matrix mult(r2, c2);
                    mult.multiply(a, b);
                    mult.displayMatrix();
                }
                else
                {
                    std::cout << "\nRows and cols don't match\n";
                }
                break;

            case 4:

                std::cout << "\nTranspose of the matrix 1 is\n";
                a.transpose();

                std::cout << "\nTranspose of the matrix 2 is\n";
                b.transpose();
                break;

            case 5:
                if (r1 == c1)
                {
                    std::cout << "\nTrace of the matrix 1 is\n";
                    a.trace();
                }
                else
                {
                    std::cout << "\nrows and cols must be equal to find trace\n";
                }

                if (r2 == c2)
                {
                    std::cout << "\nTrace of the matrix 2 is\n";
                    b.trace();
                }
                else
                {
                    std::cout << "\nrows and cols must be equal to fin trace\n";
                }
                break;

            case 6:
                std::cout << "\n1 - to continue with another matrix \nany other key to quit\n : ";
                std::cin >> ask;
                break;

            default:
                std::cout << "\nEnter a valid value\n";
            }
        } while (choice != 6);
    }
    std::cout << "\nExiting...";
    return 0;
}