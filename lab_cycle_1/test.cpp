#include <iostream>
class matrix
{
    private:
    int rows,cols;
    int **mat;

    public:
    matrix(){}
    void get_matrix();
    int get_rows(){return rows;}
    int get_cols(){return cols;}
    matrix(int,int);
    void matrix_add(matrix& , matrix&);
    
};
matrix::matrix(int x, int y)
{
    rows = x;
    cols = y;
    mat = new int *[rows];
    for(int i=0;i<rows;i++)
    {
    mat[i] = new int [cols];
    }
}
void matrix::get_matrix()
{
    std::cout<<"enter the rows : ";
    std::cin>>rows;

    std::cout<<"enter the cols : ";
    std::cin>>cols;

    mat = new int *[rows];
    for(int i=0;i<rows;i++)
    {
    mat[i] = new int [cols];
    for(int j=0;j<cols;j++)
    {
        std::cout<<"enter value at "<<"["<<i+1<<"]"<<"["<<j+1<<"]";
        std::cin>>mat[i][j];
    }
    }

}

int main()
{

}
