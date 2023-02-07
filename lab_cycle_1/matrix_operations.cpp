#include <iostream>

class matrix
{
    int rows,cols;
    int **p;
    public:
    matrix(){}
    matrix(int,int);
    void getelement(int,int,int);
    int putelement(int,int);
    
    void sum(matrix,matrix);
    void mult(matrix&,matrix&);
    matrix get_matrix();
    matrix display(matrix);

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

    a.display(a);
    return a;
}

matrix matrix::display(matrix a)
{
    for(int i=0;i<a.rows;i++)
    {
        for(int j=0;j<a.cols;j++)
        {
            std::cout<<a.putelement(i,j)<<" ";
        }
        std::cout<<"\n";
    }
} 

void matrix::sum(matrix a,matrix b)
{
    matrix add(a.rows,a.cols);
    int value;

    if(a.rows == b.rows && a.cols == b.cols)
    {
        std::cout<<"sum of the matrix is \n";
        for(int i=0;i<a.rows;i++)
        {
            for(int j=0;j<a.cols;j++)
            {
                value = a.putelement(i,j)+b.putelement(i,j);
                add.getelement(i,j,value);
            }
    }
    add.display(add);
    }
    else
    {
        std::cout<<"matrix sum can only be done when both matrices are of same type \n";
    }
}

void matrix::mult(matrix &a,matrix &b)
{
    matrix mult(a.rows,a.cols);
    std::cout<<"product of the matrix is \n";
    for(int i=0;i<a.rows;i++)
    {
        for(int j=0;j<b.cols;j++)
        {
            int value = 0;
            for(int k=0;k<a.cols;k++)
            {
                value = value + a.putelement(i,k)*b.putelement(k,j);
            }
            mult.getelement(i,j,value);
        }
    }
    mult.display(mult);
}
int main()
{
    matrix a,b,c,d,e;
    d=a.get_matrix();
    e=b.get_matrix();
    c.sum(d,e);
    c.mult(d,e);
    return 0;
}