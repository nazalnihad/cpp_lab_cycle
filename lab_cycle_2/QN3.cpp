#include <iostream>
using namespace std;
class Vector
{
    float x,y,z;
    int static count;
    public:
    Vector(){}
    friend istream& operator >>(istream &in,Vector&a);
    friend ostream& operator <<(ostream &out,const Vector&a);
    friend Vector operator *(const Vector&,const Vector&);
};
int Vector::count = 1;
istream& operator >>(istream &in,Vector &a)
{
    cout<<"\nVector "<<Vector::count<<endl;
    Vector::count++;
    cout<<"x = ";
    in >>a.x;
    cout<<"Y = ";
    in >>a.y;
    cout<<"Z = ";
    in >>a.z;
    return in;
}
ostream& operator <<(ostream &out,const Vector&a)
{
    if(a.y<0 && a.z<0){
    out<<a.x<<"i"<<a.y<<"j"<<a.z<<"k \n";
    }
    else if(a.y <0 && a.z>0)
    {
        out<<a.x<<"i"<<a.y<<"j+"<<a.z<<"k \n";
    }
    else if(a.z<0 && a.y>0){
        out<<a.x<<"i+"<<a.y<<"j"<<a.z<<"k \n";
    }
    else{
        out<<a.x<<"i + "<<a.y<<"j + "<<a.z<<"k \n";
    }
    return out;
}
Vector operator *(const Vector &a,const Vector &b)
{
    Vector temp;
    temp.x = a.x*b.x;
    temp.y = a.y*b.y;
    temp.z = a.z*b.z;
    return temp;
}
int main()
{
    Vector a,b,c;
    cin >> a;
    cin >> b;
    cout<<"\nThe vectors are \n";
    cout<< a;
    cout << b;
    cout<<"\ndot product of the vectors is \n";
    c = a*b;
    cout<<c;
    return 0;
}