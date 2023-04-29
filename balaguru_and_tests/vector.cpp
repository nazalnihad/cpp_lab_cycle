#include <iostream>
using namespace std;
class vector
{
    float *p;
    int size;

public:
    vector()
    {
        size = 0;
        p = new float[size];
    }
    void getVector();
    int deleteVect();
    int change();
    void show();
};
void vector::getVector()
{
    cout << "\nEnter the size of the vector : ";
    cin >> size;
    delete p;
    p = new float[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value " << i + 1 << " : ";
        cin >> p[i];
    }
}
int vector::deleteVect()
{
    int del;
    cout << "\nEnter the position to delete : ";
    cin >> del;
    if (del > size)
    {
        cout << "Entered wrong value \n";
        return 0;
    }
    del = del - 1;
    for (int i = del; i < size; i++)
    {
        p[i] = p[i + 1];
    }
    size--;
}
int vector::change()
{
    int chng;
    cout << "\nEnter the position to change : ";
    cin >> chng;
    if (chng > size)
    {
        cout << "Entered wrong value \n";
        return 0;
    }
    chng -= 1;
    for (int i = 0; i < size; i++)
    {
        if (chng == i)
        {
            cout << "\nEnter the changed value : ";
            cin >> p[i];
        }
    }
}
void vector::show()
{
    cout << "( ";
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
        {
            cout << p[i];
            break;
        }
        cout << p[i] << " , ";
    }
    cout << ")";
}
int main()
{
    vector a;
    a.getVector();
    int choice;
    do
    {
        cout << "\n1 - to display the vector \n2 - to change a value \n3 - to delete a value \n4 - to exit \n : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            a.show();
            break;

        case 2:
            a.change();
            break;

        case 3:
            a.deleteVect();
            break;

        case 4:
            return 0;

        default:
            cout << "Enter a valid value pls \n";
        }
    } while (choice != 4);

    // a.deleteVect();
    // a.show();
    // a.change();
    // a.show();
    return 0;
}