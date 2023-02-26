#include <iostream> 
class matrix
{
    int **p;
    int rows,cols;

    public:
    matrix(){}
    matrix(int,int);
    void getelement(int,int,int);
    int putelement(int,int);
    matrix getmatrix();
    void display();
    matrix operator+(matrix&);
    matrix operator*(matrix&);
    // ~matrix(){
    // for(int i = 0; i < rows; i++){
    //     delete[] p[i];
    // }
    // std::cout<<"MM\n";
    // delete[] p;
// }
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
void matrix::getelement(int x,int y, int value)
{
    p[x][y] = value;
}
int matrix::putelement(int x,int y)
{
    return p[x][y];
}
matrix matrix::getmatrix()
{
    int value,get_rows,get_cols;
    std::cout<<"Enter no of rows : ";
    std::cin>>get_rows;
    std::cout<<"Enter no of cols : ";
    std::cin>>get_cols;
    std::cout<<get_cols<<"\n"<<get_rows<<"\n";
    matrix a(get_rows,get_cols);
    
    for(int i=0;i<get_rows;i++)
    {
        std::cout<<"ROW "<<i+1<<"\n";
        for(int j=0;j<get_cols;j++)
        {
            std::cout<<"Enter value at ["<<i<<"]["<<j<<"] : ";
            std::cin>>value;
            a.getelement(i,j,value);
        }
    }
    return a;
}
void matrix::display()
{   
    std::cout<<"\n========\n";
    for(int i=0; i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            std::cout<<putelement(i,j)<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"========\n";
}
matrix matrix::operator +(matrix&a)
{
    int value;
    if(a.rows==rows && a.cols == cols)
    {
        matrix add(a.rows,a.cols);
        for(int i=0;i<a.rows;i++)
        {
            for(int j=0;j<a.cols;j++)
            {
                value = a.putelement(i,j)+putelement(i,j);
                add.getelement(i,j,value);
            }
        }
    return add;
    }
    else
    {
        std::cout<<"ROWS and COlS must match \n";
    }
}
matrix matrix::operator*(matrix &a)
{
    if(cols == a.rows)
    {
        matrix mult(rows,a.cols);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<a.cols;j++)
            {
                int value=0;
                for(int k=0;k<a.rows;k++)
                {
                    value = value+putelement(i,k)*a.putelement(k,j);
                    mult.getelement(i,j,value);
                }
            }
        }
    return mult;
    }
    else{
        std::cout<<"NO can do \n";
    }
}
int main()
{
    matrix a,b,sum,pdt;
    a=a.getmatrix();
    b=b.getmatrix();
    sum=a+b;
    pdt = a*b;
    a.display();
    b.display();
    sum.display();
    pdt.display();
    return 0;
}