#include <iostream>
#include <cstring>
class string
{
    char *name;
    int length;

    public:
    string()
    {
        length = 0;
        name = new char[length+1];
    }
    void get_string(char *s);
    void concate(string &a , string &b);
    void compare(const string &a,const string &b);
    void display()
    {
        std::cout<<"Name is "<<name<<"\n";
    }
};
void string::get_string(char *s)
 {
    length = strlen(s);
    delete name;
    name = new char[length+1];
    strcpy(name,s);
}
void string::concate(string &a , string &b)
{
    length = a.length+b.length;
    delete name;
    name = new char[length];
    strcpy(name,a.name);
    strcat(name,b.name);
}
void string::compare(const string &a,const string &b)
{
    if(a.length == b.length)
    {
        std::cout<<"The strings have the same length "<<a.length<<"\n";
    }
    else if(a.length>b.length)
    {
        std::cout<<"The first string "<<a.name<<" with length "<<a.length<<" is greater \n";
    }
    else{
        std::cout<<"The second string "<<b.name<<" with length "<<b.length<<" is greater \n";
    }
}
int main()
{
    string a,b,c;
    char name1[20] , name2[20];
    int choice;
    std::cout<<"Enter first name : ";
    std::cin>>name1;
    std::cout<<"Enter last name : ";
    std::cin>>name2;
    a.get_string(name1);
    b.get_string(name2);
    do{
    std::cout<<"\nChoose \n1 - to display the strings \n2 - to conacatenate the strings \n3 - to compare the strings\n4 - to quit\n : ";
    std::cin>>choice;

    switch (choice)
    {
    case 1:
        a.display();
        b.display();
        break;
    case 2:
        c.concate(a,b);
        c.display();
        break;
    case 3:
        c.compare(a,b);
        break;
    case 4:
        exit(0);
    default:
        std::cout<<"Enter the right choice please \n ";
        break;
    }
    }while(choice!=4);

    return 0;
}