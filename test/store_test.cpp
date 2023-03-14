//Write a C++ program using class to process shopping list for a Departmental
//Store. The list include details such as the code, name, price and quantity of
//each item and perform the operations like adding & deleting items to the list
//and printing the total value of a purchase order

#include <iostream>

class store
{
    int code[20],price[20],quantity[20];
    std::string name[20];
    static int i;
    public:
    store(){}
    void add_item();
    void delete_item();
    void total();
};
int store::i=0;
void store::add_item()
{
    std::cout<<"Enter code of item : ";
    std::cin>>code[i];
    std::cout<<"Enter name of item : ";
    std::cin>>name[i];
    std::cout<<"Enter price of item : ";
    std::cin>>price[i];
    std::cout<<"Enter quantity of item : ";
    std::cin>>quantity[i];
    i++;
}

void store::delete_item()
{
    int choice,limit;
    bool del = false;
    std::cout<<"Enter item code to delete : ";
    std::cin>>choice;

    for(int l=0;l<20;l++)
    {
        if(code[l]==choice)
        {
            del = true;
            limit = l;
        }
    }

    if(del==true)
    {
        for(int j=limit; j<20;j++ )
        {
            code[j] = code[j-1];
            name[j] = name[j-1];
            price[j] = price[j-1];
            quantity[j] = quantity[j-1];
        }
        i--;
    }
}

void store::total()
{   
    for(int k=0;k<i;k++)
    {
    std::cout<<name[k]<<" "<<code[k]<<" "<<price[k]<<" "<<quantity[k]<<"\n";
    }
} 

int main()
{
 int choice;
 std::cout<<"Enter choice : ";
 std::cin>>choice;

 store a;
 while(choice==1)
 {
    int opt;
    std::cout<<"Enter choice : ";
    std::cin>>opt;

    switch(opt)
    {
        case 1:
        a.add_item();
        break;

        case 2:
        a.delete_item();
        break;

        case 3:
        a.total();
        break;

        case 4:
        exit(0);
        break;
    }
 }
}
