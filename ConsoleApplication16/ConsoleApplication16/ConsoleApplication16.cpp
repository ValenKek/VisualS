#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
class Nacion
{
    std::string name;
    int population;
    int area;
public:
    Nacion() :population(0), area(0), name("unkown"){}
    Nacion(std::string name, int population, int area):population(population), area(area), name(name) {}
    ~Nacion(){}
    void Show()
    {
        std::cout << name << " " << population << " " << area<<std::endl;
    }
    bool operator<(Nacion p) //перегрузка оператора <, так як sort шукае його вызачення
    {
        return population > p.population;
    }
};

int main()
{
    std::vector<Nacion> vec;//Створення вектора який буде приймати об'єкти класу 
    vec.emplace_back(Nacion("Ukraine", 36000000, 603628));//додавання обєктів класу 
    vec.emplace_back(Nacion("UK", 66000000, 242495));
    vec.emplace_back(Nacion("France", 66990000, 643801));
    vec.emplace_back(Nacion("Germany", 83020000, 357386));
    for (int i = 0; i < vec.size(); i++)//вивід вектору
    {
        vec[i].Show();
    }
    std::cout << "-----------Sort by population------------" << std::endl;
    sort(vec.begin(), vec.end());//сортування за насенням
    for (int i = 0; i < vec.size(); i++)//вивід вектору
    {
        vec[i].Show();
    }
}