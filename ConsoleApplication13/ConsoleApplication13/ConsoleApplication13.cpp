#include <iostream>


class Point {
    int a, b, c;

public:
    
    Point(int a, int b, int c) :a(a), b(b), c(c) {}
    Point() :a(0), b(0), c(0) {}
    ~Point() = default;

    //об'явлення операторів
    Point operator+(const Point& ex)const {
        return Point(a + ex.a, b + ex.b, c + ex.c);
    }
    Point operator+(int num)const {
        return Point(a + num, b + num, c + num);
    }
    Point operator*(const Point& ex)const {
        return Point(a * ex.a, b * ex.b, c * ex.c);
    }
    Point operator*(int num)const {
        return Point(a * num, b * num, c * num);
    }
    Point& operator=(const Point& ex) {
        if (this == &ex) return *this;
        a = ex.a; b = ex.b; c = ex.c;
        return *this;
    }
    Point& operator++() {
        a++, b++, c++;
        return *this;
    }
    Point operator++(int i) {
        Point temp(*this);
        a++, b++, c++;
        return temp;
    }
    friend Point operator+(int i, Point& ex);
    void Print() {
        std::cout << "a = " << a << "\nb = " << b << "\nc = " << c << '\n';
    }
    int GetA() {
        return a;
    }
    void SetA(int a) {
        this->a = a;
    }
    int GetB() {
        return b;
    }
    void SetB(int b) {
        this->b = b;
    }
    int GetC() {
        return c;
    }
    void SetC(int c) {
        this->c = c;
    }

};

Point operator+(int i, Point& ex) {
    return Point(ex.a + i, ex.b + i, ex.c + i);
}

int main() {
    {
        Point first(5, 10, 15), second(1, 2, 3), third;

        //Оператор +
        third = first + second;//Обєкт та обєкт
        third.Print();
        third = first + 25; //Обєкт та змінна
        third.Print();
        std::cout << std::endl;

        //Оператор *
        third = first * second;//Обєкт та обєкт
        third.Print();
        third = second * 8;//Обєкт та змінна
        third.Print();
        third = second * 0;
        std::cout << std::endl;

        //Оператор =
       
        third.Print(); //Не перегруженний оператор
        third = first;
        third.Print(); //Перегруженний оператор
        third = first * 0;
        std::cout << std::endl;

        //Префікс ++
        third.Print(); //До
        third = ++second;
        third.Print(); //Після
        third = first * 0;
        std::cout << std::endl;

        //Постфікс ++
        third.Print();//До
        third = second++;
        third.Print();//Після
        third = first * 0;
        std::cout << std::endl;

        //Оператор +
        third = 10 + first;//Число та обєкт
        third.Print();
        std::cout << std::endl;

        //Пошук
        int type_value;
        bool flag = false;
        std::cout << "Type value: ";
        std::cin >> type_value;

        Point e[3] = { {5, 10, 15}, {1, 2, 3}, {0, 0, 0} };
        for (int i = 0; i < 3; i++) {
            if (type_value == e[i].GetA() || type_value == e[i].GetB() || type_value == e[i].GetC()) {
                e[i].Print();
                flag = true;
            }
        }
        if (!flag) {
            std::cout << "Error, faild to find a field according to your value!"<<std::endl;
        }
    }
    system("pause");
    return 0;
}
