#include <iostream>

class alpha
{
    protected:
    int alpha_value;

    public:
    alpha(){
        std::cout<<"\nThis is the default constructor of 'alpha' class \n";
    }
    alpha(int n)
    {
        alpha_value = n;
        std::cout<<"\nThis is the parameterised constructor of class 'alpha'\n";
        std::cout<<"alpha value = "<<alpha_value<<"\n";
    }
};


class beta
{
    protected:
    int beta_value;

    public:
    beta(){
        std::cout<<"This is the default constructor of 'beta' class \n";
    }
    beta(int n)
    {
        beta_value = n;
        std::cout<<"This is the parameterised constructor of class 'beta'\n";
        std::cout<<"beta value = "<<beta_value<<"\n";
    }
};

class gamma:public alpha , public beta //first inherited class will show constructor first 
{
    protected:
    int gamma_value;

    public:
    gamma(){
        std::cout<<"This is the default constructor of 'gamma' class \n";
        std::cout<<"Since we are inheriting alpha first then beta , constructors of 'alpha' will be shown first , then 'beta'\n";
    }
    gamma(int n1,int n2,int n3):alpha(n1),beta(n2) //constructor declared according to input 
    {
        gamma_value = n3;
        std::cout<<"This is the parameterised constructor of class 'gamma'\n";
        std::cout<<"gamma value = "<<gamma_value<<"\n";
    }
};

int main()
{
    int choice,alpha_val,beta_val,gamma_val;
    do{
    std::cout<<"\n1 - to show default constructors\n2 - to show parameterised constructors\n3 - to show both\n4 - to quit\n: ";
    std::cin>>choice;
    if(choice ==1)
    {
        gamma a;
    }
    else if(choice == 2){
        std::cout<<"\nEnter value of class alpha : ";
        std::cin>>alpha_val;
        std::cout<<"Enter value of class beta : ";
        std::cin>>beta_val;
        std::cout<<"Enter value of gamma class : ";
        std::cin>>gamma_val;

        gamma b(alpha_val,beta_val,gamma_val);
    }
    
    else if(choice == 3){
        std::cout<<"\nEnter value of class alpha : ";
        std::cin>>alpha_val;
        std::cout<<"Enter value of class beta : ";
        std::cin>>beta_val;
        std::cout<<"Enter value of gamma class : ";
        std::cin>>gamma_val;
        gamma c;
        gamma d(alpha_val,beta_val,gamma_val);
    }
    else if(choice==4){
        exit(0);
    }
    else{
        std::cout<<"Enter a valid value \n";
    }    
    }while(choice != 4);
}