#include <iostream>
class abstract
{
    protected:
    int age;
    std::string name;

    public:
    virtual void get_details()=0;
    virtual void display()=0;
};
 
class derived1:public abstract
{
    public:
    void get_details();
    void display();
};

void derived1::display()
{
    std::cout<<"\nName = "<<name<<"\n"<<"Age = "<<age<<"\n";
}
void derived1::get_details()
{
    std::cout<<"This is derived class 1 \n";
    std::cout<<"\nEnter your name : ";
    std::cin>>name;
    std::cout<<"Enter your age : ";
    std::cin>>age;
}

class derived2:public abstract
{
    public:
    void get_details();
    void display();
};
void derived2::display()
{
    std::cout<<"\nfav sport = "<<name<<"\n"<<"Age in 10yrs = "<<age<<"\n";
}
void derived2::get_details()
{
    std::cout<<"This is derived class 2 \n";
    std::cout<<"\nEnter your fav sport : ";
    std::cin>>name;
    std::cout<<"Enter your age in 10 yrs : ";
    std::cin>>age;
}

int main()
{
    abstract *a;
    a = new derived1;
    a->get_details();
    a->display();

    a = new derived2;
    a->get_details();
    a->display();

    return 0;
}