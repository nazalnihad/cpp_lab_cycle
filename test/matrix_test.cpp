#include <iostream>
class matrix
{
    int **p;
    int rows,cols;
    
    public:
    matrix(){}
    matrix(int,int);
    void getmatrix();
    void display();
    void add(matrix &,matrix &);
    void multiply(matrix &,matrix &);
    ~matrix()
    {
        for(int i=0;i<rows;i++)
        {
            delete p[i];
        }
        delete p;
        std::cout<<"memory release\n";
    }
};
matrix::matrix(int x,int y)
{
    rows = x;
    cols = y;

    p = new int *[rows];
    for(int i=0;i<rows;i++)
    {
        p[i] = new int [cols];
    }
}

void matrix::getmatrix()
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            std::cout<<"Enter value at ["<<i+1<<"]["<<j+1<<"] : ";
            std::cin>>p[i][j];
        }
    }
}

void matrix::display()
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            std::cout<<p[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

void matrix::add(matrix &a,matrix &b)
{
    if(a.rows==b.rows && a.cols == b.cols)
    {
        for(int i=0;i<a.rows;i++)
        {
            for(int j=0;j<a.cols;j++)
            {
                p[i][j]=a.p[i][j]+b.p[i][j];
            }
        }
    }
}

void matrix::multiply(matrix &a,matrix &b)
{
    for(int i=0;i<a.rows;i++)
    {
        for(int j=0;j<b.cols;j++)
        {
        p[i][j]=0;
        
        for(int k=0;k<a.cols;k++)
        {
            p[i][j]=p[i][j]+a.p[i][k]*b.p[k][j];
        }
        }
    }
}
int main()
{
    int r1,c1,r2,c2;
    std::cout<<"Enter no of rows : ";
    std::cin>>r1;
    std::cout<<"Enter no of cols : ";
    std::cin>>c1;

    matrix a(r1,c1);
    a.getmatrix();
    a.display();

    std::cout<<"Enter no of rows : ";
    std::cin>>r2;
    std::cout<<"Enter no of cols : ";
    std::cin>>c2;

    matrix b(r2,c2);
    b.getmatrix();
    b.display();

    matrix c(r1,c1);
    c.add(a,b);
    c.display();

    matrix d(r1,c2);
    d.multiply(a,b);
    d.display();

    return 0;

}