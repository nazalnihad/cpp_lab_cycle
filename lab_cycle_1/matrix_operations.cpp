#include <iostream>

class matrix
{
    int rows,cols;
    int **p;
    public:
    matrix(){
    }
    matrix(int,int);
    int get_rows(){return rows;}
    int get_cols(){return cols;}
    void getelement(int,int,int);
    int putelement(int,int);
    void get_matrix();
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

void matrix::get_matrix()
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
}

void matrix::sum(matrix &a,matrix &b)
{
    int value,row,col;
    row = a.get_rows();
    col = a.get_cols();

    std::cout<<row<<" "<<col<<"\n";
    matrix c(2, 2);
    std::cout<<"sum of the matrix is \n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            value = a.putelement(i,j)+b.putelement(i,j);
            c.getelement(i,j,value);
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            std::cout<<c.putelement(i,j)<<" ";
        }
        std::cout<<" ";
    }
}


int main()
{
    matrix a,b,c;
    a.get_matrix();
    b.get_matrix();
    c.sum(a,b);
    return 0;
}