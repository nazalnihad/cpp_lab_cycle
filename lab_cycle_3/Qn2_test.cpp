#include <iostream>
template <class T>
class calculator
{
    T val1,val2;
    public:
    calculator(){}
    T add()
    {
        std::cout<<"Enter value 1 : ";
        std::cin>>val1;
        std::cout<<"Enter value 2 : ";
        std::cin>>val2;

        std::cout<<val1<<" + "<<val2<<" = "<<val1+val2<<std::endl;
    }
};

int main()
{
    calculator<int> a;
    calculator<std::string> b;
    a.add();
    b.add();
}