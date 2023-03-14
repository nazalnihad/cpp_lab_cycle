#include <iostream>
class hello
{
    int x;
    std::string name;
    public:
    hello(int a, std::string nam)
    {
        x = a;
        name = nam;
    }
    void display()
    {
        std::cout<<"name "<<name<<" x "<<x;
    }
    hello(const hello& t)
    {
        name = t.name;
        x = t.x;
    }
};
int main()
{
    hello a(1,"nazal");
    hello b=a;
    a.display();
    b.display();
    return 0;
}