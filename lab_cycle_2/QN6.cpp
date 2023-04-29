#include <iostream>

class student
{
protected:
    int roll_no;
    std::string name;

public:
    void getDetails();
    void displayDetails();
};
void student::getDetails()
{
    std::cout << "Enter your name : ";
    std::cin >> name;
    std::cout << "Enter the Roll number : ";
    std::cin >> roll_no;
}
void student::displayDetails()
{
    std::cout << "\n=== DETAILS OF THE STUDENT ===\n";
    std::cout << "NAME : " << name << "\n";
    std::cout << "ROLL NUMBER : " << roll_no << "\n";
}

class test : virtual public student
{
protected:
    int subject_marks[3];

public:
    void getMarks();
    void displayMarks();
};
void test::getMarks()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Enter marks in Subject " << i + 1 << " : ";
        std::cin >> subject_marks[i];
    }
}
void test::displayMarks()
{
    std::cout << "\n===== SCORES ===== \n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Score of subject " << i + 1 << " is : " << subject_marks[i] << "\n";
    }
}

class sports : virtual public student
{
protected:
    int football, cricket;

public:
    void getScores();
    void displayScores();
};
void sports::getScores()
{
    std::cout << "Enter the sports score in football : ";
    std::cin >> football;
    std::cout << "Enter the sports score in cricket : ";
    std::cin >> cricket;
}
void sports::displayScores()
{
    std::cout << "Football Score : " << football << "\n";
    std::cout << "Cricket Score : " << cricket << "\n";
}

class result : public test, public sports
{
    int total_sub, total_sports;

public:
    result() {}
    int addScores();
    void display();
};
int result::addScores()
{
    total_sub = 0;
    for (int i = 0; i < 3; i++)
    {
        total_sub = total_sub + subject_marks[i];
    }
    total_sports = football + cricket;
}
void result::display()
{
    displayDetails();
    displayMarks();
    displayScores();
    std::cout << "\n====== TOTAL ======\n";
    std::cout << "Total subject scores : " << total_sub << "\n";
    std::cout << "Total sports scores : " << total_sports;
}

int main()
{
    result a;
    a.getDetails();
    a.getMarks();
    a.getScores();
    a.addScores();
    a.display();

    return 0;
}
