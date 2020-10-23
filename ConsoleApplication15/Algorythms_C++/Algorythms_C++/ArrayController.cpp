#include <iostream>
#include "ArrayController.h"

void ArrayController::showElems(int* arr, int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}
void ArrayController::showElems(int* arr[], int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns;++j)
        std::cout << arr[i][j] << " ";
        std::cout << '\n';

    }
}
void ArrayController::setElementsValue(int* arr[], int rows, int columns) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j)
                arr[i][j] = rand() % 10;
        }
}
void ArrayController::setElementsValue(int* arr, int n, int in) {
    if (in == 0)
        for (int i = 0; i < n; i++)
            arr[i] = rand() % -1000 - 1000;
    if (in == 1)
        for (int i = 0; i < n; i++)
            arr[i] = n - i;
    else if (in == 2)
        for (int i = 0; i < n; i++)
            arr[i] = rand() % -1 + 2;

    else if (in == 3)
        for (int i = 0; i < n; i++)
            arr[i] = 1;
}

void ArrayController::shiftElementsForInsertSort(int* arr, int from, int to, int n)
{
    int* tmp2 = arr;
    for (int i = from, tmp; i > to; --i) {
        tmp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = tmp;
    }
}
void ArrayController::shiftElementsForInsertSort(int* arr[], int from, int to, int n)
{
    int* tmp;
    for (int i = from; i > to; --i) {
        tmp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = tmp;
    }
}

void ArrayController::replaceColumn(int* arr[], int from,int rows, int to)
{
    int* tmp = new int[rows];
    for (int i = 0; i < rows; i++) {
        tmp[i] = arr[i][from];
        arr[i][from] = arr[i][to];
    }
    for (int i = 0; i < rows; i++) {
        arr[i][to] = tmp[i];
    }
}
