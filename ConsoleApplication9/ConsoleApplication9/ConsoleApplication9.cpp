#include <iostream>
class Dot {
    //const float PI;
    const int CON = 3;
    int r;
    char name;
    static int count;
public:
    Dot(char name) :name(name)
    {
        count++;
    }
    Dot() { count++; }
    ~Dot() { count--; }

    static void Print() {
        std::cout << "count = " << count << std::endl;
    }

    //Dot(float PI) : PI(PI) {}

    void Show()const {
        int i = 0;
 //       std::cout << "PI = " << PI << "r = " << r;
    }

};

int Dot::count = 0;


int main()
{
    char name = 'H';
    Dot d1(name); 
    d1.Print();
    Dot d2;  
    d2.Print(); 
    d1.Print();
}