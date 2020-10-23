#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

void funk1(float x, float y, float z) {
    x *= z;
    y *= z;
    cout << "Variables after func1 worked:" << endl;
    cout << "x = " << x << endl << "y = " << y << endl;
}
void funk2(float* x, float* y, float* z) {
    *x *= *z;
    *y *= *z;
    cout << "Variables after func2 worked:" << endl;
    cout << "x = " << *x << '\n' << "y = " << *y << endl;
}
void funk3(float& x, float& y, float& z) {
    x *= z;
    y *= z;
    cout << "Variables after func1 worked:" << endl;
    cout << "x = " << x << '\n' << "y = " << y << endl;
}
int funk_task2(int var1 = 1, int var2 = 2, int var3 = 3, int var4 = 4) {
    int sum;
    sum = var1 + var2 + var3 + var4;
    return sum;
}
void funk_variant1(int* chislo1, int* chislo2) {
    int a1 = *chislo1, a2 = *chislo2, bufer;
    bufer = a2;
    *chislo2 = a1;
    *chislo1 = bufer;
}
int add(int x, int y) {
    return x + y;
}
int subtract(int x, int y) {
    return x - y;
}
int operation(int(*op)(int, int), int a, int b) {
    return op(a, b);
}




int main()
{
    void funk1(float, float, float);
    void funk2(float*, float*, float*);
    void funk3(float&, float&, float&);

    cout << "--------------------------TASK 1.1:------------------------------" << endl;
    float a = 4.5f, b = 5.5f, c = 9.5f;
    funk1(a, b, c);
    cout << "Variables in main after funk1 worked DIDN'T change:" << endl;
    cout << "a = " << a << '\n' << "b = " << b << '\n' << "c = " << c << endl;

    funk2(&a, &b, &c);
    cout << "Variables in main after funk2 worked CHANGED:" << endl;
    cout << "a = " << a << '\n' << "b = " << b << '\n' << "c = " << c << endl;

    funk3(a, b, c);
    cout << "Variables in main after funk3 worked CHANGED:" << endl;
    cout << "a = " << a << '\n' << "b = " << b << '\n' << "c = " << c << endl;

    cout << "--------------------------TASK 1.2:------------------------------" << endl;
    int var1 = 6, var2 = 7, var3 = 8, var4 = 9;
    cout << "CALL 1:" << endl;
    cout << "sum = " << funk_task2() << endl;
    cout << "CALL 2:" << endl;
    cout << "sum = " << funk_task2(var1) << endl;
    cout << "CALL 3:" << endl;
    cout << "sum = " << funk_task2(var1, var2) << endl;
    cout << "CALL 4:" << endl;
    cout << "sum = " << funk_task2(var1, var2, var3) << endl;
    cout << "CALL 5:" << endl;
    cout << "sum = " << funk_task2(var1, var2, var3, var4) << endl;

    cout << "--------------------------TASK 2 VARIANT 1:------------------------------" << endl;
    int h = 5, i = 7;
    cout << "h=" << h << " i=" << i << endl;
    funk_variant1(&h, &i);
    cout << "After funk work: h=" << h << " i=" << i << endl;

    cout << "--------------------------TASK 3:------------------------------" << endl;
    int k = 10;
    int l = 5;
    int result;
    result = operation(add, a, b);
    cout << "result: " << result << endl;
    result = operation(subtract, a, b);
    cout << "result: " << result << endl;
    return 0;
}
