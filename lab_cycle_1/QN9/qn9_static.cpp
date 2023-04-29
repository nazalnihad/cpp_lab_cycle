#include <iostream>
using namespace std;
class Static
{
    static int count;

public:
    Static()
    {
        count++;
    }
    static void showcount(void)
    {
        cout << "object number : " << count << "\n";
    }
};
int Static::count = 0;
int main()
{
    int choice = 1;
    while (choice != 0)
    {
        cout << "\n1 - to create object \n0 - to quit \n: ";
        cin >> choice;
        if (choice == 1)
        {
            Static a;
            a.showcount();
        }
        else if (choice == 0)
        {
            cout << "\nExiting....";
            return 0;
        }
        else
        {
            cout << "\nenter a valid choice\n";
        }
    }
    return 0;
}