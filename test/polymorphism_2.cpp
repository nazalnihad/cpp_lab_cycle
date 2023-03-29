#include <iostream>
#include <cstring>
class poly
{
    char *name;
    int len;

public:
    poly()
    {
        len = 0;
        name = new char[len + 1];
    }
    void get_name();
    void display()
    {
        std::cout << "The name of the city is : " << name << "\n";
    }
};

void poly::get_name()
{
    char s[10];
    std::cout << "Enter the city name : ";
    std::cin >> s;

    len = strlen(s);
    // delete name;
    name = new char[len + 1];
    strcpy(name, s);
}

int main()
{
    poly *ptr[5]; // we make 10 pointers for poly

    for (int i = 0; i < 5; i++)
    {
        ptr[i] = new poly;
        ptr[i]->get_name();
    }

    for (int i = 0; i < 5; i++)
    {
        ptr[i]->display();
    }
    return 0;
}