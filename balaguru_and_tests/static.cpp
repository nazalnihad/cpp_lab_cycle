#include <iostream>
using namespace std;
class stati
{
    static int count;

public:
    stati()
    {
        count++;
    }
    void show(void)
    {
        cout << "object number : " << count << "\n";
    }
};
int stati::count = 0;
int main()
{
    int choice;
    do
    {
        cout << "Enter 1 - to create object \n0 - to quit : ";
        cin >> choice;
        if (choice == 1)
        {
            stati a;
            a.show();
        }
        else
        {
            cout << "wrong\n";
        }
    } while (choice != 0);
    return 0;
}