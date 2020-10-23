#pragma once

class ArrayController
{
public:
    static void showElems(int* arr, int n);
    static void showElems(int* arr[], int rows, int columns);
    static void setElementsValue(int* arr, int n, int in = 0);
    static void setElementsValue(int* arr[], int rows, int columns);
    static void shiftElementsForInsertSort(int* arr, int from, int to, int n);
    static void shiftElementsForInsertSort(int* arr[], int from, int to, int n);
    static void replaceColumn(int* arr[], int from, int rows, int to = 0);
};
