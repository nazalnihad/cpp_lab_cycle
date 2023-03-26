#include <iostream>
#include <cstring>
class person
{
    char name[20];
    float age;

    public:
    person(){}
    person(char *s , float a)
    {
        strcpy(name,s);
        age = a;
    }
    person &greater(person &x)
    {
        if(x.age>=age)
        {
            return x;
        }
        else{
            return *this;
        }
    }
    void display()
    {
        std::cout<<"Name : "<<name<<"\n";
        std::cout<<"Age : "<<age<<"\n";
    }
};

int main()
{
    person p1("babu" ,37.5) , p2("ramu" , 29) ,p3("sugu",14.5),p;
    p = p2.greater(p1);
    p.display();

    return 0;
}