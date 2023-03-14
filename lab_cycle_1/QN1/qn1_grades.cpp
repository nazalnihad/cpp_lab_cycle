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

void grades::get_info() //input details 
    {

    int a,b,c,roll;
    std::string name1;
    
    std::cout<<"\n";
    
    std::cout<<"Enter name of student : ";
    std::cin>>name1;

    std::cout<<"Enter roll number : ";
    std::cin>>roll;
    do{
    std::cout<<"Enter mark1 (out of 50) : ";
    std::cin>>a;

    std::cout<<"Enter mark2 (out of 50) : ";
    std::cin>>b;

    std::cout<<"Enter mark3 (out of 50) : ";
    std::cin>>c;

    if(a>50 || b>50 || c>50)
    {
        std::cout<<"invalid marks pls retry \n";
    }
    }while(a>50 || b>50 || c>50);
    set_input(a, b, c,name1,roll);
    }
    
void grades::display(void) //calculate grades according to conditions
    {
        std::cout<<"\n---- Progress Report ----\n";
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
int no_of_students,i,n;
std::cout<<"Enter the number of students : " ;
std::cin>>no_of_students;
grades g[no_of_students];
for(i=0; i<no_of_students; i++)
{  
   std::cout<<"\nEnter details of student : "<<i+1;
   g[i].get_info(); 
}
std::cout<<"\n       Grade list       \n";
for(n=0; n<no_of_students; n++)
{
    g[n].display();
}

return 0;
}
