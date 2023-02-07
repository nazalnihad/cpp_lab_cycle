//Create a class TIME with members hours, minutes, seconds. Take input, add
//two time objects by passing objects to function and display result.

#include <iostream>
class TIME
{
    private:
    int hour,min,sec;

    public:
    void input();
    int add_time(TIME,TIME);
    void display();
};

void TIME::input(){
    std::cout<<"Enter hours : ";
    std::cin>>hour;

    std::cout<<"Enter minutes : ";
    std::cin>>min;

    std::cout<<"Enter seconds : ";
    std::cin>>sec;
}

int TIME::add_time(TIME t1, TIME t2){
    sec = t1.sec+t2.sec;
    min = sec/60+t1.min+t2.min;
    sec = sec%60;
    hour = min/60;
    hour = hour + t1.hour + t2.hour;
    min = min%60;
    
    return sec , min , hour;
}

void TIME::display(){
    std::cout<<hour<<" : Hours "<<min<<" : Min "<<sec<<" : Seconds";
}
int main()
{
    TIME t1,t2,t3;
    std::cout<<"Enter time 1  \n";
    t1.input();
    std::cout<<"Enter time 2 \n";   
    t2.input();
    std::cout<<"\n=== Total time  ===\n";
    t3.add_time(t1,t2);

    t3.display();
    return 0;

}