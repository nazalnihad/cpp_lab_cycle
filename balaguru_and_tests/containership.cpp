#include <iostream>
using namespace std;
class student
{
    int marks;
    string name;

public:
    student() {}
    student(string n, int m)
    {
        name = n;
        marks = m;
    }
    int getmarks() { return marks; }
    string getname() { return name; }
};

class teacher
{
    char grade;
    student s;

public:
    teacher(char x, student st) : grade(x), s(st) {}
    void getResult()
    {
        cout << "Name = " << s.getname() << "\n";
        cout << "Marks = " << s.getmarks() << "\n";
        cout << "Grade = " << grade << "\n";
    }
};
int main()
{
    student s("Babu", 99);
    teacher t('A', s);
    t.getResult();
    return 0;
}