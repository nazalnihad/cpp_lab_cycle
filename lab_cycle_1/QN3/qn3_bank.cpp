#include <iostream>

class bank
{
private:
    std::string cust_name, acc_type;
    int static accn_no; // static to generate and add account no
    int balance = 0;

public:
    void new_acc();
    int deposit();
    int withdraw();
    int check_balance();
    void statement();
};
int bank::accn_no = 0;
void bank::new_acc()
{
    accn_no++;
    std::string name, accnt_type;
    char type;

    std::cout << "Enter your name : ";
    std::cin >> cust_name;
    do
    {
        std::cout << "Enter account type "
                  << "\n"
                  << "Current account - C"
                  << "\n"
                  << "Savings account - S"
                  << "\n"
                  << " : ";
        std::cin >> type;
        if (toupper(type) == 'C')
        {
            acc_type = "Current account";
        }
        else if (toupper(type) == 'S')
        {
            acc_type = "Savings account";
        }
        else
        {
            std::cout << "Error pls check if you entered the right value \n";
        }
    } while (toupper(type) != 'C' and toupper(type) != 'S');

    do
    {
        std::cout << "Enter the amount to deposit (min balance must be 500) : ";
        std::cin >> balance;
        if (balance < 500)
        {
            std::cout << "pls try again the min balance must be 500\n";
        }
    } while (balance < 500);

    std::cout << "New account created \nYour account number is : " << accn_no << "\n";
}
int bank::deposit()
{
    int bal;
    std::cout << "Enter the amount you want to deposit : ";
    std::cin >> bal;
    balance = bal + balance;
    std::cout << "Deposited   : " << bal << "\nnew balance is : " << balance;
    return balance;
}
int bank::withdraw()
{
    int amnt;
    std::cout << "\n"
              << "Enter amount to withdraw : ";
    std::cin >> amnt;
    if (balance < amnt)
    {
        std::cout << "Not enough money to withdraw \n";
    }
    else if (balance - amnt < 500)
    {
        std::cout << "Min balance must be 500 \n";
    }
    else
    {
        balance = balance - amnt;
        std::cout << amnt << " withdrawn\n";
    }

    return balance;
}
int bank::check_balance()
{
    std::cout << "your balance is : " << balance << "\n";
    return balance;
}
void bank::statement()
{
    std::cout << "\n--------BANK STATEMENT--------\n";
    std::cout << "Name : " << cust_name << "\n";
    std::cout << "Account type : " << acc_type << "\n";
    std::cout << "Account number : " << accn_no << "\n";
    std::cout << "Account balance : " << balance << "\n";
    std::cout << "_______________________________\n";
}
int main()
{
    int no_of_cust, choice, i = 0;
    std::cout << "How many no of users : ";
    std::cin >> no_of_cust;

    bank customer[no_of_cust];
    int ask;
    while (i < no_of_cust)
    {
        ask = 1;
        while (ask == 1)
        {
            do
            {
                std::cout << "\nuser number " << i + 1;
                std::cout << "\n--- Main menu --- \n";
                std::cout << "1 - To create new account \n";
                std::cout << "2 - To deposit \n";
                std::cout << "3 - To withdraw \n";
                std::cout << "4 - To check balance \n";
                std::cout << "5 - Bank statement \n";
                std::cin >> choice;
            } while (choice != 1 and choice != 2 and choice != 3 and choice != 4 and choice != 5);
            switch (choice)
            {
            case 1:
                customer[i].new_acc();
                break;

            case 2:
                customer[i].deposit();
                break;

            case 3:
                customer[i].withdraw();
                break;

            case 4:
                customer[i].check_balance();
                break;

            case 5:
                customer[i].statement();
                break;
            }
            if (i + 1 == no_of_cust)
            {
                std::cout << "\n1 - to continue \n3 - to quit\n";
                std::cin >> ask;
            }
            else
            {
                std::cout << "\n1 - to continue \n2 - to next \n3 - to quit\n";
                std::cin >> ask;
            }
            if (ask == 3)
            {
                exit(0);
            }
        }
        i++;
    }
    return 0;
}