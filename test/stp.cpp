#include <iostream>
#include <iomanip>
class store
{
    float *code,*price;
    int *quantity , limit;
    std::string *item_name;

    public:
    store(){}
    void add_items();
    void add_more();
    int delete_items();
    void display();
    void receipt();
};

void store::add_items()
{
    std::cout<<"\nHow many items do you want to purchase : ";
    std::cin>>limit;
    code = new float[limit];
    price = new float[limit];
    item_name = new std::string[limit];
    quantity = new int[limit];

    for(int i=0;i<limit;i++)
    {
    std::cout<<"\nEnter item name : ";
    std::cin>>item_name[i];
    std::cout<<"Enter item code : ";
    std::cin>>code[i];
    std::cout<<"Enter the quantity of the item : ";
    std::cin>>quantity[i];
    std::cout<<"Enter the price of the items : ";
    std::cin>>price[i];
    price[i] = price[i]*quantity[i];
    }
}
int store::delete_items()
{
    int choice;
    std::cout<<"\nEnter the code of the item you want to delete : ";
    std::cin>>choice;
    int item=-1;
    for(int i=0;i<limit;i++)
    {
        if(code[i]==choice)
        {
        item = i;
        }
    }
    if(item != -1)
    {
        for(int i=item ; i<limit-1;i++)
        {
            item_name[i]=item_name[i+1];
            code[i] = code[i+1];
        }
    limit = limit-1;
    }
    else{
        std::cout<<"code not found \n";
    }
    return limit;
}
void store::display()
{
    for(int i=0;i<limit;i++)
    {
        std::cout<<"\nname : "<<item_name[i]<<"\ncode : "<<code[i]<<"\nquantity : "<<quantity[i]<<"\n"<<"===\nprice :"<<price[i]<<"\n===\n";
    }
}

void store::add_more()
{
    int more;
    std::cout<<"How many more items do you want to add : ";
    std::cin>>more;
    int old_limit = limit;
    limit = limit + more; 
    
    float *new_code = new float[limit];
    float *new_price = new float[limit];
    std::string *new_item_name = new std::string[limit];
    int *new_quantity = new int[limit];

    for(int i=0;i<old_limit;i++)
    {
        new_code[i] = code[i];
        new_price[i] = price[i];
        new_item_name[i] = item_name[i];
        new_quantity[i] = quantity[i];
    }
    delete[] code;
    delete[] price;
    delete[] item_name;
    delete[] quantity;

    code = new_code;
    price = new_price;
    item_name = new_item_name;
    quantity = new_quantity;

    for(int i=limit-more;i<limit;i++)
    {
    std::cout<<"\nEnter item name : ";
    std::cin>>item_name[i];
    std::cout<<"Enter item code : ";
    std::cin>>code[i];
    std::cout<<"Enter the quantity of the item : ";
    std::cin>>quantity[i];
    std::cout<<"Enter the price of the items : ";
    std::cin>>price[i];
    price[i] = price[i]*quantity[i];
    }
}
void store::receipt()
{
    int sum=0;
    for(int i=0;i<limit;i++)
    {
        sum = sum+price[i];
    }
    std::cout<<"\n\t======== RECEIPT ========\t\t\n";
    std::cout<<"NAME"<<std::setw(10)<<"CODE"<<std::setw(10)<<"QUANTITY"<<std::setw(20)<<"PRICE"<<"\n";
    for(int i=0;i<limit;i++){
    std::cout<<item_name[i]<<std::setw(10)<<code[i]<<std::setw(10)<<quantity[i]<<std::setw(20)<<price[i]<<"\n";
    }
    std::cout<<std::setw(40)<<"TOTAL AMOUNT = "<<sum<<"\n";
}

int main()
{
    int option;
    std::cout<<"\n=== Welcome to Deparetment Store ===\n";
    std::cout<<"\n press 1 to start \n any other key to quit : ";
    std::cin>>option;
    store a;

    if(option == 1)
    {
        int choice;
        a.add_items();
        do{
            std::cout<<"\nChoose what you want to do \n";
            std::cout<<"1 - to add more items \n";
            std::cout<<"2 - to remove an item \n";
            std::cout<<"3 - to show your cart \n";
            std::cout<<"4 - to get the reciept \n";
            std::cout<<"5 - to buy and quit \n";
            std::cin>>choice;

            switch(choice){
            case 1:
            a.add_more();
            break;

            case 2:
            a.delete_items();
            break;

            case 3:
            a.display();
            break;

            case 4:
            a.receipt();
            break;

            case 5:
            std::cout<<"\n========== THANKYOU ==========\n";
            exit(0);
            }
        }while(choice!=5);
    }
    else{
        exit(0);
    }
    return 0;
}