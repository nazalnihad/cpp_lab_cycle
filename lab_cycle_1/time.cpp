//Create a class TIME with members hours, minutes, seconds. Take input, add
//two time objects by passing objects to function and display result.

#include <iostream>
class time
{
    private:
    int hour,min,sec;

    public:
    void input();
    int add_time(time,time);
    void display();
};

void time::input(){
    std::cout<<"Enter hours : ";
    std::cin>>hour;

    std::cout<<"Enter minutes : ";
    std::cin>>min;

    std::cout<<"Enter seconds : ";
    std::cin>>sec;
}

int time::add_time(time t1, time t2){
    sec = t1.sec+t2.sec;
    min = sec/60+t1.min+t2.min;
    sec = sec%60;
    hour = min/60;
    hour = hour + t1.hour + t2.hour;
    min = min%60;
    
    return sec , min , hour;
}

void time::display(){
    std::cout<<hour<<" : Hours "<<min<<" : Min "<<sec<<" : Seconds";
}
int main()
{
    time t1,t2,t3;
    t1.input();
    t2.input();
    t3.add_time(t1,t2);

    t3.display();
    return 0;

}