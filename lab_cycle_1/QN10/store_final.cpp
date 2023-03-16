//Write a C++ program using class to process shopping list for a Departmental
//Store. The list include details such as the code, name, price and quantity of
//each item and perform the operations like adding & deleting items to the list
//and printing the total value of a purchase order

#include <iostream>
#include <iomanip>
class store
{
    int code[20],price[20],quantity[20];
    std::string name[20];
    static int i;
    public:
    store(){}
    void add_item();
    void delete_item();
    void change(int);
    void total();
};
int store::i=0;
void store::add_item()
{
    std::cout<<"\nEnter code of item : ";
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

    for(int l=0;l<i;l++)
    {
        if(code[l]==choice)
        {
            del = true;
            limit = l;
        }
        else{
            std::cout<<"Pls make sure to enter the right code \n";
        }
    }

    if(del==true)
    {
        if (quantity[limit]>1)
        {
            int value;
            std::cout<<"\n1 - Enter the quantity you want to reduce\n2 - to delete item completely\n any other key if you have changed your mind \n :  ";
            std::cin>>value;
            switch(value)
            {
                case 1:
                int amount;
                std::cout<<"Enter the amount you want to reduce (current quantity = "<<quantity[limit]<<") : ";
                std::cin>>amount;
                while(quantity[limit]<amount){
                    std::cout<<"Incorrect amount , pls re-enter : ";
                    std::cin>>amount;
                }
                if(amount<quantity[limit])
                {
                quantity[limit] = quantity[limit]-amount;
                }
                else if(amount==quantity[limit])
                {
                    change(limit);
                }
                break;

                case 2:
                change(limit);
                break;
            }
        }
        else{
            change(limit);
        }
        
    }
}

void store::change(int limit)
{
    for(int j=limit; j<i-1;j++ )
    {
        code[j] = code[j+1];
        name[j] = name[j+1];
        price[j] = price[j+1];
        quantity[j] = quantity[j+1];
    }
    i--;
}

void store::total()
{   
    int sum=0;
    for(int j=0;j<i;j++)
    {
        sum = sum+quantity[j]*price[j];
    }
    std::cout<<"\n\t======== RECEIPT ========\t\t\n";
    std::cout<<"NAME"<<std::setw(10)<<"CODE"<<std::setw(10)<<"QUANTITY"<<std::setw(20)<<"PRICE"<<"\n";
    for(int k=0;k<i;k++){
    std::cout<<name[k]<<std::setw(10)<<code[k]<<std::setw(10)<<quantity[k]<<std::setw(20)<<price[k]<<"\n";
    }
    std::cout<<std::setw(40)<<"TOTAL AMOUNT = "<<sum<<"\n";
} 


int main()
{
 int choice;
 std::cout<<"Enter choice \n1 - to start \nany other key - to exit \n : ";
 std::cin>>choice;

 store a;
 while(choice==1)
 {
    int opt;
    std::cout<<"\n1 - to add item \n2 - to remove an item \n3 - to get the total bill \n4 - to quit \n : ";
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
        std::cout<<"THANK YOU\n";
        exit(0);
        break;

        default:
        std::cout<<"Pls enter a valid value \n";
    }
 }
}
