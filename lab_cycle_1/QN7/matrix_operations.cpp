#include <iostream>
class matrix
{
    int rows,cols;
    int **p;
    public:
    matrix(){}
    // ~matrix(){
    // 	for(int i=0;i<rows;i++){
    // 		delete p[i];
    // 	}
    // 	delete p;
    //     std::cout<<"memory release\n";
    // }
    matrix(int,int);
    void getelement(int,int,int);
    int putelement(int,int);
    
    void sum(matrix&,matrix&);
    void mult(matrix&,matrix&);
    void transpose(matrix);
    void trace(matrix);

    matrix get_matrix();
    matrix display(matrix);

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
    for(int i=0;i<m;i++){
        std::cout<<"ROW "<<i+1<<"\n";
        for(int j=0;j<n;j++){
            std::cout<<"Enter value at position ["<<i+1<<"]"<<"["<<j+1<<"] : ";
            std::cin>>value;
            a.getelement(i,j,value);
        }
    }
    a.display(a);
    return a;
}

matrix matrix::display(matrix a)
{
    std::cout<<"\n";
    for(int i=0;i<a.rows;i++){
        for(int j=0;j<a.cols;j++){
            std::cout<<a.putelement(i,j)<<" ";
        }
        std::cout<<"\n";
    }
} 

void matrix::sum(matrix &a,matrix &b)
{
    matrix add(a.rows,a.cols);
    int value;
    if(a.rows == b.rows && a.cols == b.cols){
        std::cout<<"sum of the matrix is \n";
        for(int i=0;i<a.rows;i++){
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
    for(int i=0;i<add.rows;i++){
        delete add.p[i];
    }
    delete add.p;
    std::cout<<"memory released \n";
}

void matrix::mult(matrix &a,matrix &b)
{
    if(a.cols == b.rows){
    matrix multiply(a.rows,b.cols);
    std::cout<<"product of the matrix is \n";
    for(int i=0;i<a.rows;i++){
        for(int j=0;j<b.cols;j++)
        {
            int value = 0;
            for(int k=0;k<a.cols;k++)
            {
                value = value + a.putelement(i,k)*b.putelement(k,j);
            }
            multiply.getelement(i,j,value);
        }
    }
    multiply.display(multiply);
    for(int i=0;i<multiply.rows;i++){
        delete multiply.p[i];
    }
    delete multiply.p;
    std::cout<<"memory released \n";
    }
    else{
        std::cout<<"matrix multiplication is not possible \n";
    }
}

void matrix::transpose(matrix a){
    for(int i=0;i<a.cols;i++){
        for(int j=0;j<a.rows;j++){
            std::cout<<a.putelement(j,i)<<" ";
        }
        std::cout<<"\n";
    }
}

void matrix::trace(matrix a)
{
    int sum = 0;
    if(a.rows == a.cols){
        for(int i=0;i<a.rows;i++){
            for(int j=0;j<a.cols;j++){
                if(i==j)
                {
                sum = sum+a.putelement(i,j);
                }
            }
        }
    std::cout<<"trace of matrix is "<<sum<<"\n";
    }
    else{
        std::cout<<"can't find the trace of the matrix \n";
    }
}
int main()
{

    std::cout<<"==============================\n";
    std::cout<<"Matrix operations \nEnter the value of the matrices \n";

    matrix a,b,c,d,e;
    std::cout<<"\n=== MATRIX 1 ===\n";
    d=a.get_matrix();
    std::cout<<"\n=== MATRIX 2 ===\n";
    e=b.get_matrix();

    int choice;
    do{
    std::cout<<"\n=== Enter the operations you want to do ===";
    std::cout<<"\n 1 - to add matrices ";
    std::cout<<"\n 2 - to multiply matrices "; 
    std::cout<<"\n 3 - to find transpose of matrices ";
    std::cout<<"\n 4 - to find trace of matrices ";
    std::cout<<"\n 5 - to quit \n : ";
    std::cin>>choice;
    switch (choice)
    {
        case 1:
        std::cout<<"==== Sum ====\n";
        c.sum(d,e);
        break;

        case 2:
        std::cout<<"==== Product ====\n";
        c.mult(d,e);
        break;

        case 3:
        std::cout<<"==== Transpose of 1st matrix ====\n";
        c.transpose(d);
        std::cout<<"==== Transpose of 2nd matrix ====\n";
        c.transpose(e);
        break;

        case 4:
        std::cout<<"\n==== Trace of 1st matrix ====\n";
        c.trace(d);
        std::cout<<"\n==== Trace of 2nd matrix ====\n";
        c.trace(e);
        break;

        case 5:
        exit(0);

        default:
        std::cout<<"Enter a valid choice \n";
    }
    }while(choice!=5);
    return 0;
}