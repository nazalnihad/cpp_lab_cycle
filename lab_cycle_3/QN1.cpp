#include <iostream>
class abstract
{
protected:
    int age;
    std::string name;

public:
    virtual void get_details() = 0; // pure virtual fn
    virtual void display() = 0;     // pute virtual fn
};

class derived1 : public abstract
{
public:
    void get_details(); // describe the derived code here
    void display();
};

void derived1::display()
{
    std::cout << "\nName = " << name << "\n"
              << "Age = " << age << "\n";
}
void derived1::get_details()
{
    std::cout << "\nThis is derived class 1 \n";
    std::cout << "\nEnter your name : ";
    std::cin >> name;
    std::cout << "Enter your age : ";
    std::cin >> age;
}

class derived2 : public abstract
{
public:
    void get_details();
    void display();
};
void derived2::display()
{
    std::cout << "\nfav sport = " << name << "\n"
              << "Your favorite number = " << age << "\n";
}
void derived2::get_details()
{
    std::cout << "\nThis is derived class 2 \n";
    std::cout << "\nEnter your favorite sport : ";
    std::cin >> name;
    std::cout << "Enter your favorite number : ";
    std::cin >> age;
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