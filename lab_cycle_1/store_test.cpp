#include <iostream>

class store
{
    int quantity;
    float code,price;
    std::string item_name;

    public:
    store(){}
    void add_items();
    void add_more();
    int delete_items();
    void display();
    // void receipt();
};

void store::add_items()
{
    std::cout<<"\nEnter item name : ";
    std::cin>>item_name;
    std::cout<<"Enter item code : ";
    std::cin>>code;
    std::cout<<"Enter the quantity of the item : ";
    std::cin>>quantity;
    std::cout<<"Enter the price of the items : ";
    std::cin>>price;
    price = price*quantity;
}
int store::delete_items()
{
    int code1 , quantity1;
    std::cout<<"Enter the code of item to delete : ";
    std::cin>>code1;
    std::cout<<"enter the quantity of item to delete ";
    std::cin>>quantity1;

}
void store::display()
{
    for(int i=0;i<limit;i++)
    {
        std::cout<<"\nname : "<<item_name[i]<<"\ncode : "<<code[i]<<"\nquantity : "<<quantity<<"\n"<<"===\nprice :"<<price[i]<<"\n===\n";
    }
}

int main()
{
    int option;
    std::cout<<"\n=== Welcome to Deparetment Store ===\n";
    std::cout<<"\n press 1 to start \n any other key to quit : ";
    std::cin>>option;
    store a[100];

    if(option == 1)
    {
        for(int i=0;i<100;i++)
        {
        int choice;
        do{
            std::cout<<"\nChoose what you want to do \n";
            std::cout<<"1 - to add items \n";
            std::cout<<"2 - to remove an item \n";
            std::cout<<"3 - to show your cart \n";
            std::cout<<"4 - to get the reciept \n";
            std::cout<<"5 - to quit \n";
            std::cin>>choice;

            switch(choice){
            case 1:
            a[i].add_items();
            break;

            case 2:
            a[i].delete_items();
            break;

            case 3:
            a[i].display();
            break;

            case 4:
            a[i].display();
            break;

            case 5:
            exit(0);
            }
        }while(choice!=5);
        }
    }
    else{
        exit(0);
    }
    return 0;
}