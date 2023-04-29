#include <iostream>
using namespace std;
class invent2;

class invent1
{
    int code, items;
    float price;

public:
    invent1(int a, int b, float c)
    {
        code = a;
        items = b;
        price = c;
    }
    void putdata()
    {
        cout << "Code : " << code << "\n";
        cout << "Items : " << items << "\n";
        cout << "Price : " << price << "\n";
    }
    int getcode() { return code; }
    int getitems() { return items; }
    float getprice() { return price; }
    operator float() { return items * price; }
    operator invent2();
};

class invent2
{
    int code;
    float value;

public:
    invent2() {}
    invent2(int x, float y)
    {
        code = x;
        value = y;
    }

    void putdata()
    {
        cout << "Code : " << code << "\n";
        cout << "value : " << value << "\n";
    }
    friend invent1::operator invent2();
};

invent1::operator invent2()
{
    invent2 temp;
    temp.code = code;
    temp.value = price * items;
    return temp;
}

int main()
{
    invent1 p1(100, 5, 140.0);
    invent2 d2;
    float total;
    total = p1;
    cout << "Total = " << total << "\n";
    d2 = p1;
    cout << "Invent 1 : \n";
    p1.putdata();
    cout << "\nInvent 2 : \n";
    d2.putdata();
    return 0;
}