#include <iostream>
class item 
{
    int x;
    public:
    void get_data()
    {
        std::cout<<"Enter x : ";
        std::cin>>x;
    }
    void display(){
        std::cout<<"data got "<<x<<"\n";
    }
};

int main()
{
    item *ptr;
    ptr = new item[3];
    item *count = ptr;
    for(int i=0;i<3;i++)
    {
        ptr->get_data();
        ptr++;
    }

    for(int i=0;i<3;i++)
    {
        count->display();
        count++;
    }
    return 0;
}