#include <iostream>
#include <string>

class string_ops
{
    private:
    std::string string;
    int length;

    public:
    void input();
    int length_input();
    void concatenate();
    void compare();
};

void string_ops::input()
{
    std::cout<<"enter your string  : ";
    std::getline(std::cin, string);

}

int string_ops::length_input()
{
    length = string.length(); //check length of the string
    std::cout<<"length of your string is : "<<length<<"\n";
    return length;
}

void string_ops::concatenate()
{

    int n,i;
    std::string concate;
    concate = string;
    std::cout<<"How many strings do you want to concatenate : ";
    std::cin>>n;
    
    std::string string2[n]; //array created to store input strings 
    for(i=0;i<n;i++)
    {
    std::cout<<"enter string "<<i+1<<" : ";
    std::cin>>string2[i];
    }
    for(i=0;i<n;i++)
    {
    concate = concate+string2[i]; //concatenating the strings
    }
    std::cout<<"the concatenated string is "<<concate<<"\n"; //display the concatenated strings
}

void string_ops::compare()
{
        int n,i,big=0,count=0;
        std::string check,largest,same;

        std::cout<<"with how much strings do you want to compare : ";
        std::cin>>n;
        
        std::string string_check[n+1]; //array created to store strings to compare
        string_check[0]=string; //first term of array given as the main string 
        
        for(i=1;i<n+1;i++)
        {
        std::cout<<"enter string "<<i<<" : ";
        std::cin>>string_check[i];
        }
        
        for(i=0;i<n+1;i++)
        {
            check = string_check[i];
            int length = check.length();
            if(length > big)
            {
                big = length;
                largest = check;
                count = 1;
            }   
        }
        
        for(i=0;i<n+1;i++)
        {
            if(string_check[i].length() == big)
            {
                count++; 
            }
        }
           
        if(count>1)
        {
            int num=0;
            std::string same[count];
            for(i=0;i<n+1;i++){
                if (string_check[i].length()==big)
                {
                    same[num] = string_check[i];
                    num++;
                }
            }
            if(num>1)
            {
                std::cout<<"there are "<<num<<" same and largest length of strings with length "<<big<<" and they are : ";
                for(i=0;i<num;i++)
                {
                std::cout<<same[i]<<" ";
                }
                std::cout<<"\n";
            }
            else
            {
            std::cout<<"the biggest length of the given string is : "<<big<<" and the word is "<<largest<<"\n";
            }
        }
        else if(count<=1){
            std::cout<<"the biggest length of the given string is : "<<big<<" and the word is "<<largest<<"\n";
        }
            
       
}
int main()
{
    int choice=0;
    string_ops man;
    std::cout<<"---- STRING OPERATIONS ----\n";
    man.input();
    while(choice != 4){
    std::cout<<"\n------------------------------------\n";
    std::cout<<"1 - To check length of your string \n";
    std::cout<<"2 - To concatenate with other strings \n";
    std::cout<<"3 - To compare length with other strings \n";
    std::cout<<"4 - To quit \n";
    std::cout<<"______________________________________\n";
    std::cout<<" : ";
    std::cin>>choice;
        
    switch(choice)
    {
        case 1:
        man.length_input();
        break;
        
        case 2:
        man.concatenate();
        break;
        
        case 3:
        man.compare();
        break;
        
        case 4:
        exit(0);
        break;
    }
    }
    return 0;
}