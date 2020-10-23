#include "iostream"
#include <set>
#include <map>
#include <iterator>

class Nacion//класс с минулої лб
{
    std::string name;
    int population;
    int area;
public:
    Nacion() :population(0), area(0), name("unkown") {}
    Nacion(std::string name, int population, int area) :population(population), area(area), name(name) {}
    ~Nacion() {}
    bool operator<(const Nacion n)const {//перегрузка < для роботы з set
        return name > n.name ;
    }
    void Show()const
    {
        std::cout << name << " " << population << " " << area << std::endl;
    }
};

int main()
{
    std::set<Nacion> s1;//створення та об'явлення s1
    s1.insert(Nacion("Ukraine", 36000000, 603628));
    s1.insert(Nacion("UK", 66000000, 242495));
    s1.insert(Nacion("France", 66990000, 643801));
    s1.insert(Nacion("Germany", 83020000, 357386));
    auto iterator = s1.begin();
    for (auto i = iterator; i != s1.end(); i++)//вивід з використанням for
    {
        i->Show();
    }
    std::cout << std::endl << std::endl;
    while (iterator != s1.end())//вивід з використанням while
    {
        iterator->Show();
        iterator++;
    }
}
