#include <iostream>
class Static{
    int static count;
    public:
    Static()
    {
        count++;
    }
    void showcount()
    {
        std::cout<<"\nnow no of objects is "<<count<<std::endl;
    }
};
int Static::count=0;
int main()
{
    int count;
    int i=0;
    std::cout<<"\n=============================================================\n";
    std::cout<<"Press 1 to start \nany other key to quit : ";
    std::cin>>count;
    while(count==1)
    {
        std::cout<<"\npress 1 to create an object  \n any other key to quit : ";
        std::cin>>count;
        if(count == 1){
            Static i;
            i.showcount();
            std::cout<<std::endl;
        }
        else{
        std::cout<<"\n=============================================================\n";
        exit(0);
        }
        i++;
    }
    
}