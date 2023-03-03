#include <iostream>
class football{ //base class 1
    protected:
    int fut_players;
    public:
    football(int n){
        fut_players = n;
    }
    void display()
    {
        if(fut_players != 11)
        {
            std::cout<<"You are WRONG!, a football team have 11 players\n";
        }
        else{
        std::cout<<"You are RIGHT! , NO of players in a football team is "<<fut_players<<"\n";
        }
    }
};

class cricket{ //base class 2
    protected:
    int cric_players;
    public:
    cricket(int n){
        cric_players = n;
    }
    void display()
    {
        if(cric_players != 11)
        {
            std::cout<<"You are WRONG!!, a Cricket team have 11 players\n";
        }
        else{
        std::cout<<"You are RIGHT! ,No of players in a cricket team is "<<cric_players<<"\n";
        }
    }
};

//derived class through multiple inheritence
class sports:public football,public cricket 
{
    protected:
    int total_players;
    public:
    sports(int n1,int n2,int n3):football(n2),cricket(n3){
        total_players = n1;
    }
    void display()
    {
        if(total_players != 22)
        {
            std::cout<<"HMmmm...!, your total was wrong try again\n";
        }
        else
        {
            std::cout<<"Nice , Total no of players in football and cricket must be "<<total_players<<"\n";
        }
    }
};

//derived class throught multilevel inheritence i.e from base1+base2 -> derived1 -> derived2
class world:public sports{
    std::string name;
    public:
    world(std::string your_name,int n1,int n2,int n3):sports(n1,n2,n3)
    {
        name = your_name;
    }
    void display()
    {
        std::cout<<"\nHey "<<name<<" your answers are as follows \n";
        football::display(); //displays of different base classes must be like this
        cricket::display();
        sports::display();
    }
};

int main()
{
    int start,choice = 1;
    int foot_players,crick_players,total;
    std::string player_name;
    std::cout<<"\nThis is a quiz test on a very small topic to show different typed of inheritence\n";
    std::cout<<"Press 1 to start\nAny other key to quit\n";
    std::cin>>start;
    if(start==1){
        do{
            std::cout<<"\n======= == =======\n";
            std::cout<<"\nEnter your name : ";
            std::cin>>player_name;
            std::cout<<"Enter the no of players in a football team : ";
            std::cin>>foot_players;
            std::cout<<"Enter the no of player in a cricket team : ";
            std::cin>>crick_players;
            std::cout<<"What is the total no of players if cricket and football players are added : ";
            std::cin>>total;
            world a(player_name,total,foot_players,crick_players);

            a.display();

            std::cout<<"\nPress 1 to try again\nany other key to quit : ";
            std::cin>>choice;
    }   while(choice ==1);
    }
    else{
        exit(0);
    }
    return 0;
}