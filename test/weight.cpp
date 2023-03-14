#include <iostream>

class weight
{
    float kg,gm;

    public:
    weight(){}
    void getDetails();
    friend weight sum(weight&,weight&);
    void display();
};
void weight::getDetails()
{
    int input;
    std::cout<<"Enter your weight in grams : ";
    std::cin>>input;

    kg = input/1000;
    gm = input%1000;

}
weight sum(weight &a ,weight &b)
{
    weight temp;
    temp.kg = a.kg+b.kg;
    temp.gm = a.gm+b.gm;
    return temp;
}

void weight::display()
{
    std::cout<<"Weight is "<<kg<<"kg and  "<<gm<<" gm\n";
}

int main()
{

    weight a,b,c;
    a.getDetails();
    b.getDetails();
    a.display();
    b.display();

    c = sum(a,b);
    c.display();

    return 0;
    // int choice;
    // std::cout<<"Enter 1 to start : ";
    // std::cin>>choice;

    // if(choice == 1)
    // {

    // }
}