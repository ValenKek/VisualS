#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


class Сontinent
{

    char name[20];
    unsigned int area;
    unsigned int population;
public:
    char* GetName()
    {
        return name;
    }
    unsigned int GetArea()
    {
        return area;
    }
    unsigned int GetPopulation()
    {
        return population;
    }
    void SetName(char* name)
    {
        strcpy(this->name, name);
    }
    void SetArea(int area)
    {
        this->area = area;
    }
    void SetPopulation(int population)
    {
        this->population = population;
    }
   Сontinent() :area(0), population(0) {}
   /*Сontinent() {
        area = 10;
        population = 10;
        strcpy(name, "a");
        std::cout << "Constructor \n";
   }*/
   /*Сontinent(int area) :area(area) {
        std::cout << "Constructor \n";
    }*/
    explicit Сontinent(int area) :area(area) {
        std::cout << "Constructor \n";
    }
    Сontinent(int area, int population) {
        this->area = area;
        this->area = population;
        std::cout << "Constructor \n";
    }
    Сontinent(int area, int population, const char* name){
        this->area = area;
        this->area = population;
        strcpy(this->name, name);
        std::cout << "Constructor \n";
    }
    Сontinent(const char* name): area(0), population(0) {
        this->area = area;
        this->area = population;
        strcpy(this->name, name);
        std::cout << "Constructor \n";
    }

    Сontinent(const Сontinent& сontinent) :Сontinent(сontinent.population, сontinent.area, сontinent.name) { std::cout << "CCtor Line" << '\n'; }

   //Сontinent(Сontinent& continent) = default;
   //Сontinent(Сontinent& continent) = delete;

    ~Сontinent() { std::cout <<"Destructor";}
    void Show() {
        std::cout << name<<" "<< population<<" "<< area<<std::endl;
    }
};

void common(Сontinent& continents1)
{
    continents1.Show();
}


int main()
{
    char namesOfContinets[5][20] = { {"Eurasia\0"},{"Africa\0"},{"America\0"},{"Australia\0" },{"Antarctica\0"} };
    int continetsArea[5] = { 54759000, 30370000, 42549000, 8600000, 14000000 };
    int population[5] = { 5287781000 ,1287920000, 1015855000, 41261000, 4490 };
    const int n = 5;
    Сontinent* phot;
    Сontinent continents[n];
    Сontinent continents1=45;
    Сontinent continents2(1234, 4566);
    Сontinent continents3(1234, 4566, "abc");
    Сontinent continents4( "abc" );
    common(continents3);
    unsigned int areaSum = 0;
    for (int i = 0; i < n; i++)
    {
        continents[i].SetName(namesOfContinets[i]);
        continents[i].SetArea(continetsArea[i]);
        continents[i].SetPopulation(population[i]);
        areaSum += continents[i].GetArea();
    }
    std::cout << std::endl;
}
