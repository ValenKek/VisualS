#include <iostream>
#include <fstream>

class MyClass
{
public:
    int x, y, z;
    MyClass(int x=0, int y=0, int z=0):x(x),y(y),z(z){}
    friend std::ostream& operator<< (std::ostream& out, const MyClass& mc);
    friend std::istream& operator>> (std::istream& in, MyClass& mc);
};

std::ostream& operator<< (std::ostream& out, const MyClass& mc)
{
    out << "MyClass(" << mc.x << ", " << mc.y << ", " << mc.z << ")";
    std::ofstream fout;
    fout.open("file.txt");
    fout << "MyClass(" << mc.x << ", " << mc.y << ", " << mc.z << ")";
    fout.close();
    return out;
}

std::istream& operator>> (std::istream& in, MyClass& mc)
{

    in >> mc.x;
    in >> mc.y;
    in >> mc.z;

    return in;
}
int main()
{
    
    std::cout << "Enter three digitals: " << std::endl;
    MyClass mc1;
    std::cin >> mc1;
    std::cout << mc1 << std::endl;
}