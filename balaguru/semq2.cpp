#include <iostream>
using namespace std;
class person
{
    string name;
    int phone;

public:
    person()
    {
        name = "";
        phone = 0;
    }
    void get_details()
    {
        cout << "Enter the name : ";
        cin >> name;
        cout << "Enter phone no : ";
        cin >> phone;
    }
    void showPerson()
    {
        cout << "Name = " << name << "\n";
        cout << "Phone = " << phone << "\n";
    }
};

class employee : virtual public person
{
    int empId;

public:
    employee()
    {
        empId = 0;
    }
    void getEmpId()
    {
        cout << "Enter the employee id : ";
        cin >> empId;
    }
    void showemployee()
    {
        cout << "Employee Id = " << empId << "\n";
    }
};

class student : virtual public person
{
    int stdId;

public:
    student()
    {
        stdId = 0;
    }
    void getStdId()
    {
        cout << "Enter your student id : ";
        cin >> stdId;
    }
    void showStudent()
    {
        cout << "Student Id = " << stdId << "\n";
    }
};

class manager : public employee, public student
{
    string manager_name;
    int manId;

public:
    manager()
    {
        manager_name = "";
        manId = 0;
    }
    void getManager()
    {
        cout << "Enter the name of the manager : ";
        cin >> manager_name;
        cout << "Enter the manager id : ";
        cin >> manId;
    }
    void showManager()
    {
        showPerson();
        showStudent();
        showemployee();
        cout << "Manager name = " << manager_name << "\n";
        cout << "Manager Id  = " << manId << "\n";
    }
};

int main()
{
    manager m;
    m.get_details();
    m.getEmpId();
    m.getStdId();
    m.getManager();
    m.showManager();
    return 0;
}