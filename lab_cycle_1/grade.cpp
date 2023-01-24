#include <iostream>
class grades 
{
    private:
    std::string name;
    int roll_no;
    int mark_a , mark_b , mark_c ;

    public:
    void get_info();
    void set_input(int a,int b,int c ,std::string name1,int roll)
    {
        mark_a = a;
        mark_b = b;
        mark_c = c;
        name = name1;
        roll_no = roll;
    }
    int calc()
    {
        return (mark_a+mark_b+mark_c)*100/150;
    }
    void display(void);
};

void grades::get_info()
    {

    int a,b,c,roll;
    std::string name1;
    
    std::cout<<"\n";
    
    std::cout<<"Enter name : ";
    std::cin>>name1;

    std::cout<<"Enter roll number : ";
    std::cin>>roll;

    std::cout<<"Enter mark1 (out of 50) : ";
    std::cin>>a;

    std::cout<<"Enter mark2 (out of 50) : ";
    std::cin>>b;

    std::cout<<"Enter mark3 (out of 50) : ";
    std::cin>>c;

    if (a>50 || b>50 || c>50)
    {
        std::cout<<"You have entered invalid marks , pls try again \n";
        exit(0);
    }
    set_input(a, b, c,name1,roll);
    }
    
void grades::display(void)
    {
        std::cout<<"\n---- Grade list ----\n";
        if (calc()>=90){ 
            std::cout<<" Name : "<<name<<"\n"<<" Roll no : "<<roll_no <<"\n"<<" Grade : "<<"A" <<"\n";
        }
        else if (calc()>80){
            std::cout<<" Name : "<<name<<"\n"<<" Roll no : "<<roll_no <<"\n"<<" Grade : "<<"B" <<"\n";
        }
        else if (calc()>70){
            std::cout<<" Name : "<<name<<"\n"<<" Roll no : "<<roll_no <<"\n"<<" Grade : "<<"C" <<"\n";
        }
        else {
            std::cout<<" Name : "<<name<<"\n"<<" Roll no : "<<roll_no <<"\n"<<" Grade : "<<"D" <<"\n";
        }
        std::cout<<"-------- ---------- \n";
    }
int main()
{
grades std1;
grades std3;
std1.get_info();
std3.get_info();
std1.display();
std3.display();
return 0;
}
