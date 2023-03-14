#include <iostream>

class Vector
{
    int *v;
    int s;

    public:
    Vector(){
    }
    Vector(int x,int y,int z)
    {
        s = 3;
        v = new int[3];
        v[0] = x;
        v[1] = y;
        v[2] = z;
    }
    void merge(Vector &a,Vector &b)
    {
        v[0] = a.v[0]+b.v[0];
        v[1] = a.v[1]+b.v[1];
        v[2] = a.v[2]+b.v[2];
    }

    void display()
    {
        std::cout<<v[0]<<"i + "<<v[1]<<"j + "<<v[2]<<"\n";
    }
};

int main()
{
    Vector c;
    Vector a(1,2,3);
    Vector b(4,5,6);
    a.display();
    b.display();
    c.merge(a,b);
    c.display();
    return 0;
}