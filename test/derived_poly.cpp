#include <iostream>
class bc
{
    public:
    int b;
    void show_b()
    {
        std::cout<<"b = "<<b<<"\n";
    }
};

class dc:public bc
{
    public:
    int d;
    void show_d()
    {
        std::cout<<"d = "<<d<<"\n";
    }
};

int main()
{
    bc *ptr;

    // ptr = new bc;
    // ptr -> b = 100;
    // ptr->show_b();

    ptr = new dc;
    ptr->b=200;
    ptr->show_b();

    dc *dptr;
    dptr = (dc*)ptr;
    dptr->b=400;
    dptr->d = 300;
    dptr->show_d();
    dptr->show_b();
}