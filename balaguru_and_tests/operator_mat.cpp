#include <iostream>
using namespace std;
class matrix
{
    int **mat;
    int rows, cols;

public:
    matrix() {}
    matrix(int x, int y)
    {
        rows = x;
        cols = y;
        mat = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new int[cols];
        }
    }
    matrix getmatrix();
    void show();
    friend matrix operator*(matrix &, matrix &);
};
matrix matrix::getmatrix()
{
    cout << "Enter the no of rows : ";
    cin >> rows;
    cout << "Enter the no of cols : ";
    cin >> cols;
    matrix a(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter value at [" << i << "][" << j << "] : ";
            cin >> a.mat[i][j];
        }
    }
    return a;
}
void matrix::show()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
matrix operator*(matrix &m, matrix &n)
{
    matrix mult(m.rows, n.cols);
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < n.cols; j++)
        {
            mult.mat[i][j] = 0;
            for (int k = 0; k < m.cols; k++)
            {
                mult.mat[i][j] += m.mat[i][k] * n.mat[k][j];
            }
        }
    }
    return mult;
}
int main()
{
    matrix a, b, c;
    a = a.getmatrix();
    a.show();
    b = b.getmatrix();
    b.show();
    c = a * b;
    c.show();
    return 0;
}