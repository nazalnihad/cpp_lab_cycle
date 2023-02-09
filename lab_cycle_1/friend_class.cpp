#include <iostream>
class class2;
class class1
{
    int value_1;
    public:
    class1(){}
    int set_value(int x)
    {
        value_1= x;
    }
    void display()
    {
        std::cout<<"Value of number in first class "<<value_1<<std::endl;
    }
    friend void exchange(class1 &,class2 &);
};
class class2
{
    int value_2;
    public:
    int set_value(int y)
    {
        value_2 = y;
    }
    void display()
    {
        std::cout<<"Value of number in first class "<<value_2<<std::endl;
    }
    friend void exchange(class1 &,class2 &);
};

void exchange(class1 &a,class2 &b)
{
    int temp = a.value_1;
    a.value_1 = b.value_2;
    b.value_2 = temp;
}

int main()
{
    std::cout<<"\n=== No exchange program ===\n";
    class1 obj1;
    int value1;
    std::cout<<"Enter value in class 1 : ";
    std::cin>>value1;
    obj1.set_value(value1);
    obj1.display();

    class2 obj2;
    int value2;
    std::cout<<"Enter value in class 2 : ";
    std::cin>>value2;
    obj2.set_value(value2);
    obj2.display();

    std::cout<<"\nValue in classes before exchange \n";
    obj1.display();
    obj2.display(); 
    exchange(obj1,obj2);
    std::cout<<"\nValue in classes after exchange \n";
    obj1.display();
    obj2.display(); 

    std::cout<<"\n=========================\n";
    return 0;
}