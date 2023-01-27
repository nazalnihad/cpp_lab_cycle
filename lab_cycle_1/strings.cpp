#include <iostream>
#include <string>
class string_ops
{
    private:
    std::string name;
    int length;

    public:
    void input();
    int length_input();
    void concatenate();
    void compare();
};

void string_ops::input()
{
    std::cout<<"enter string 1 : ";
    std::getline(std::cin, name);

}
int string_ops::length_input()
{
    length = name.length();
    std::cout<<"length of your string is : "<<length<<"\n";
    return length;
}
void string_ops::concatenate()
{

    int n,i;
    std::cout<<"How many strings do you want to concatenate : ";
    std::cin>>n;
    std::string string2[n];
    for(i=0;i<n;i++)
    {
    std::cout<<"enter string "<<i+1<<" : ";
    std::cin>>string2[i];
    }
    for(i=0;i<n;i++)
    {
    name = name+string2[i];
    }
    std::cout<<name<<"\n";
}
void string_ops::compare()
{
        int n,i,big=0;
        std::string check,largest;

        std::cout<<"with how much strings do you want to compare : ";
        std::cin>>n;
        std::string string_check[n];
        for(i=0;i<n;i++)
        {
        std::cout<<"enter string "<<i+1<<" : ";
        std::cin>>string_check[i];
        }
        for(i=0;i<n;i++)
        {
            check = string_check[i];
            int length = check.length();
            if(length > big)
            {
                big = length;
                largest = check;
            }
        }
        std::cout<<"the biggest length of the given string is : "<<big<<" and the word is "<<largest;
}
int main()
{
    string_ops man;
    man.input();
    man.length_input();
    man.concatenate();
    man.compare();
    
    return 0;
}