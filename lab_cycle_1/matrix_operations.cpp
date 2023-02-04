#include <iostream>

class matrix
{
    int rows,cols;
    int **p;
    public:
    matrix(){
        rows = 0;
        cols = 0;
        }
    matrix(int,int);
    void getelement(int,int,int);
    int putelement(int,int);
    matrix get_matrix();
    void sum(matrix&,matrix&);

    // ~matrix()
    // {
    //     for(int i=0; i<d1;i++)
    //     {
    //         delete p[i];
    //     }
    //     delete p;
    //     std::cout<<"memory released \n";
    // }
};

matrix::matrix(int x, int y)
{
    rows = x; 
    cols = y;
    p = new int *[rows];
    for(int i=0;i<rows;i++)
    {
        p[i] = new int [cols];
    }
}

void matrix::getelement(int x,int y,int value)
{
    p[x][y] = value;
}

int matrix::putelement(int x,int y)
{
    return p[x][y];
}

matrix matrix::get_matrix()
{
    int m,n;
    std::cout<<"Enter no of rows : ";
    std::cin>>m;
    std::cout<<"Enter no of cols : ";
    std::cin>>n;

    matrix a(m,n);
    int value;

    for(int i=0;i<m;i++)
    {
        std::cout<<"ROW "<<i+1<<"\n";
        for(int j=0;j<n;j++)
        {
            std::cout<<"Enter value at position "<<j+1<<" : ";
            std::cin>>value;
            a.getelement(i,j,value);
        }
    }

    std::cout<<"your matrix is \n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cout<<a.putelement(i,j)<<"  ";
        }
        std::cout<<std::endl;
    }
    return a;
}

void matrix::sum(matrix &a,matrix &b)
{
    matrix c(a.rows,a.cols);
    int value;
    std::cout<<"sum of the matrix is \n";
    for(int i=0;i<a.rows;i++)
    {
        for(int j=0;j<a.cols;j++)
        {
            value = a.putelement(i,j)+b.putelement(i,j);
            c.getelement(i,j,value);
        }
    }
    for(int i=0;i<a.rows;i++)
    {
        for(int j=0;j<a.cols;j++)
        {
            std::cout<<c.putelement(i,j)<<" ";
        }
        std::cout<<"\n";
    }
}


int main()
{
    matrix a,b,c,d,e;
    d=a.get_matrix();
    e=b.get_matrix();
    c.sum(d,e);
    return 0;
}