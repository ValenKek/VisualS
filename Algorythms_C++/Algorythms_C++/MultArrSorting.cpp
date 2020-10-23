#include "MultArrSorting.h"
#include "ArrayController.h"
#include <algorithm> 
#include <iostream>

void MultArrSorting::bubleSort(int* arr[], unsigned int n) {

    int* tmp;
    for (unsigned int i = n - 1, j = 0; i > 0; --i) {
        while (j < i) {
            if (*arr[j] > *arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        j = 0;
    }
}

void MultArrSorting::insertSort(int* arr[], int n) {
    for (int i = 1, j; i < n; ++i) {
        j = 0;
        while (j < i) {

            if (*arr[j] > *arr[i])
            {
                break;
            }
            ++j;
        }
        if(j == 1)
        
        ArrayController::shiftElementsForInsertSort(arr, i, j, n);
    }
}
void MultArrSorting::selectionSort(int* arr[], int n) {
    int* tmp;

    for (int i = 0, k = 0; i < n - 1; ++i) {
        k = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (*arr[k] > *arr[j])
                k = j;
        }
        if (k != i) {
            tmp = arr[k];
            arr[k] = arr[i];
            arr[i] = tmp;
        }
    }
}

void MultArrSorting::mergeSort(int* arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
void MultArrSorting::quickSort(int* arr[], int first, int last)
{
    int f = first;
    int l = last;
    int mid = *arr[(f + l) / 2];
    do
    {
        while (*arr[f] < mid) f++;
        while (*arr[l] > mid) l--;
        if (f <= l)
        {
            std::swap(arr[f], arr[l]);
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quickSort(arr, first, l);
    if (f < last)quickSort(arr, f, last);
}
void MultArrSorting::radixSort(int* arr[], int minElem, int dip, int rows) {
    int** tmp = new int*[dip];
    for (int i = 0; i < dip; i++) {
        *tmp[i] = 0;
    }
    for (int i = 0; i < rows; i++) {
        *tmp[*arr[i] - minElem]++;
    }
    for (int i = 0, j = -1000; i < rows; j++) {
        while (*tmp[j - minElem] > 0) {
            *arr[i] = j;
            ++i;
            --tmp[j - minElem];
        }

    }
}
void MultArrSorting::merge(int* arr[], int start, int middle, int end) {
    int** tmp = new int*[end - start + 1];
    int i = start, j = middle + 1, k = 0;
    while (i <= middle && j <= end) {
        if (*arr[i] <= *arr[j])
        {
            tmp[k] = arr[i];
            k++;
            i++;
        }
        else {
            tmp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= middle)
    {
        tmp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        tmp[k] = arr[j];

        k++;
        j++;
    }
    for (int i = start; i <= end; i++) {
        arr[i] = tmp[i - start];
    }

}