#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>
int main() {
    int n = 10000;
    int* arr = new int[n];
    int from = -1000, to = 1000;
    auto t1 = Clock::now(), t2 = Clock::now();
    std::ofstream fout;
    fout.open("TEXT.txt");
    if (!fout.is_open()) {
        std::cout << "Error";
    }
    else {

        for (int i = 1000; i <= n; i += 1000)
        {
            ArrayController::setElementsValue(arr, from, to, i);
            t1 = Clock::now();
            Sorting::selectionSort(arr, i);
            t2 = Clock::now();
            fout << i << '\t' << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << '\n';
        }
        fout.close();
    }
}