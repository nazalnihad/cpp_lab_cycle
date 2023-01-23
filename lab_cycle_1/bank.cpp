#include <iostream>

class bank{
    private:
    std::string cust_name , acc_type;
    int acc_no , balance ;

    public:
    void new_acc();
    int deposit();
    int withdraw();
    int check_balance();
    void statement();
    
};

void bank::new_acc(){
    int accnt_no = 1000;
    std::string name,accnt_type;
    char type;

    std::cout<<"Enter your name : ";
    std::cin>>cust_name;
    std::cout<<"Enter account type "<<"\n"
            <<"Current account - C"<<"\n"
            <<"Savings account - S"<<"\n"<<" : ";
    std::cin>>type;
    if (toupper(type) == 'C'){
        acc_type = "Current account";
    }
    else if (toupper(type) == 'S'){
        acc_type = "Savings account";
    }
    else{
        std::cout<<"Error pls check if you entered the right value ";
    }
    accnt_no+=1;
    std::cout<<"Enter the amount to deposit (min balance must be 500) : ";
    std::cin>>balance;
    acc_no = accnt_no;

}
int bank::deposit()
{
    int bal;
    std::cout<<"\n Enter the amount you want to deposit (min balance is 500) : ";
    std::cin>>bal;
    balance = bal+balance;
    std::cout<<"your new balance is  : "<<balance;
    return balance;
}
int bank::withdraw()
{
    int amnt;
    std::cout<<"\n Enter amount to withdraw : ";
    std::cin>>amnt;
    if (balance<amnt){
        std::cout<<"Not enough money to withdraw "; 
    }
    else if(balance-amnt<500)
    {
        std::cout<<"Min balance must be 500 ";
    }
    else
    {
        balance = balance-amnt;
    }
    
    return balance;
    
}
int bank::check_balance()
{
    std::cout<<"your balance is : "<<balance;
}
void bank::statement()
{
    std::cout<<"Name : "<<cust_name<<"\n";
    std::cout<<"Account type : "<<acc_type<<"\n";
    std::cout<<"Account number : "<<acc_no<<"\n";
    std::cout<<"Account balance : "<<balance<<"\n";
}
int main()
{
    bank cst1;
    cst1.new_acc();
    cst1.deposit();
    cst1.withdraw();
    cst1.statement();
}