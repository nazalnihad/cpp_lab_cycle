#include <iostream>
using namespace std;
class matrix
{
private:
    int rows;
    int columns;
    int result;
    int **m;

public:
    matrix();
    matrix(int r, int c);
    // ~matrix();
    void input();
    void display();
    void matrix_add(matrix &a, matrix &b);
    void matrix_transpose();
    void matrix_trace();
    void matrix_multiply(matrix &a, matrix &b);
};
matrix::matrix() {}
matrix::matrix(int r, int c)
{
    rows = r;
    columns = c;
    m = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        m[i] = new int[columns];
    }
    std::cout << "dynamically allocated memory" << std::endl;
}
void matrix::input()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cin >> m[i][j];
        }
    }
}
void matrix::display()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void matrix::matrix_multiply(matrix &a, matrix &b)
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            m[i][j] = 0;
            for (int k = 0; k < columns; k++)
            {
                m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
}

void matrix::matrix_add(matrix &a, matrix &b)
{
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            m[i][j] = a.m[i][j] + b.m[i][j];
    }
    std::cout << std::endl;
    std::cout << "addition completed" << std::endl;
}
void matrix::matrix_transpose()
{
    std::cout << "********transpose*********" << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            std::cout << m[j][i] << " ";
        }
        std::cout << std::endl;
    }
}
void matrix::matrix_trace()
{
    std::cout << "matric tracing" << std::endl;
    int sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == j)
            {
                sum += m[i][j];
            }
        }
    }
    std::cout << std::endl;
    std::cout << "result : " << sum << std::endl;
}

void menu()
{
    std::cout << "*************** SELECT ****************" << std::endl;
    std::cout << "press 1 for addition of matrices" << std::endl;
    std::cout << "press 2 for getting transpose of matrices" << std::endl;
    std::cout << "press 3 for getting trace of matrix" << std::endl;
    std::cout << "press 4 to multiply two matrices" << std::endl;
}
// matrix::~matrix()
// {
//     for (int i = 0; i < rows; i++)
//     {
//         delete[] m[i];
//     }
//     delete[] m;
//     std::cout << std::endl;
//     std::cout << "destructor released memory" << std::endl;
// }
int main()
{
    int r, c, ro, co;
    int choice, x = 1;

    std::cout << "enter the no. of rows and columns for matrix 1 : " << std::endl;
    std::cin >> r >> c;
    std::cout << "enter the no. of rows and columns for matrix 2 : " << std::endl;
    std::cin >> ro >> co;
    // setting up the matrices
    matrix m(r, c);
    matrix n(ro, co);
    // entering elements to the metrices
    std::cout << "enter elements for matrix 1 " << std::endl;
    m.input();
    m.display(); // displaying first matrix
    std::cout << "enter elements for matrix 2 " << std::endl;
    n.input();
    n.display(); // displaying second matrix

    while (x == 1)
    {
        // menu driven
        menu();
        std::cout << "enter your choice : " << std::endl;
        std::cout << std::endl;
        std::cin >> choice;
        if (choice >= 1 && choice <= 5)
        {
            if (choice == 1) // addition of two matrices
            {
                while (true)
                {
                    if (r == ro && c == co)
                    {
                        matrix g(r, c);
                        g.matrix_add(m, n);
                        g.display();
                        break;
                    }
                    else
                    {
                        std::cout << "invalid matrices entered for addition !" << std::endl;
                        std::cout << std::endl;
                        std::cout << "enter the rows and columns of matrix 1 : " << std::endl;
                        std::cout << std::endl;
                        std::cin >> r >> c;
                        matrix m(r, c);
                        std::cout << "enter elements of matrix 2 again : " << std::endl;
                        m.input();
                        std::cout << std::endl;
                        m.display();
                        std::cout << std::endl;
                        std::cout << "enter the rows and columns of matrix 2 : " << std::endl;
                        std::cin >> ro >> co;
                        matrix n(ro, co);
                        std::cout << "enter elements of matrix 1 again : " << std::endl;
                        n.input();
                        std::cout << std::endl;
                        n.display();
                        matrix g(r, c);
                        g.matrix_add(m, n);
                        g.display();
                        break;
                    }
                }
            }
            else if (choice == 2) // transpose of  matrices
            {
                std::cout << std::endl;
                std::cout << "the transpose matrix 1 : " << std::endl;
                m.matrix_transpose();
                std::cout << std::endl;
                std::cout << "the transpose of matrix 2 is : " << std::endl;
                n.matrix_transpose();
            }
            else if (choice == 3) // trace of matrices
            {
                std::cout << std::endl;
                std::cout << "trace of matrix 1 : " << std::endl;
                m.matrix_trace();
                std::cout << "trace of matrix 2 : " << std::endl;
                n.matrix_trace();
            }
            else if (choice == 4)
            {
                while (true)
                {

                    if (c == ro)
                    {
                        matrix g(r, co);
                        g.matrix_multiply(m, n);
                        g.display();
                        break;
                    }
                    else
                    {
                        std::cout << "the number of columns in the first matrix must be equal to the num" << std::endl;
                        std::cout << "enter the rows and columns of matrix 1 : " << std::endl;
                        std::cout << std::endl;
                        std::cin >> r >> c;
                        matrix m(r, c);
                        std::cout << "enter elements of matrix 2 again : " << std::endl;
                        m.input();
                        std::cout << std::endl;
                        m.display();
                        std::cout << std::endl;
                        std::cout << "enter the rows and columns of matrix 2 : " << std::endl;
                        std::cin >> ro >> co;
                        matrix n(ro, co);
                        std::cout << "enter elements of matrix 1 again : " << std::endl;
                        n.input();
                        std::cout << std::endl;
                        n.display();
                        matrix g(r, c);
                        g.matrix_multiply(m, n);
                        g.display();
                        break;
                    }
                }
            }
        }

        else
        {
            std::cout << "enter a valid input (1 to 5) :" << std::endl;
            std::cin >> choice;
        }

        std::cout << "enter 1 to continue or any other key to exit : ";
        std::cin >> x;
    }
}