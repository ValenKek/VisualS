#include <iostream>
#include <time.h>

namespace std;
//стороння функція для зміни порядку символів
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//BubbleSort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        // якщо елемент масиву більше наступного елемента, то ми поміняємо їх місцями
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
// друк масиву у консолі
void printArrayBub(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
//insertionsort
// Функція сортування масиву за допомогою insertion sort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        //Перемістіть елементи arr [0..i-1], тобто більше, ніж ключ, на одну позицію попереду їх поточного становища
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
// Функція для друку масиву розміром n
void printArrayIns(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
//SelectionSort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    //По черзі переміщують межу невідсортованого підмасиву
    for (i = 0; i < n - 1; i++)
    {
        //Знаходить мінімальний елемент у несортованому масиві
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        //Поміняйте знайдений мінімальний елемент з першим елементом
        swap(&arr[min_idx], &arr[i]);
    }
}
//Функція друку масиву
void printArraySel(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
//MergeSort
void merge(int*, int, int, int);
void merge_sort(int* arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        //розділити масив посередині та сортувати самостійно, використовуючи сортування злиттям
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}
// Merge sort
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n11 = m - l + 1;
    int n22 = r - m;
    int* L = new int[n11];
    int* R = new int[n22];
    for (i = 0; i < n11; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n22; j++)
        R[j] = arr[m + 1 + j];
    i = 0; // Початковий індекс першого підмасиву
    j = 0; // Початковий індекс другого підмасиву
    k = l; // Початковий індекс об’єднаного підмасиву
    while (i < n11 && j < n22)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n11)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n22)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Сортуває першу та другу половинки
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
//QuickSort
//Функція для обміну двома елементами
void swap1(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
// Ця функція приймає останній елемент як опору, місця поворотний елемент у правильному положенні в сортуванні масив, і розміщує всі менші (менше, ніж опорні) ліворуч від повороту та всі більші елементи праворуч опори
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; //опора
    int i = (low - 1); // Індекс меншого елемента

    for (int j = low; j <= high - 1; j++)
    {
        // Якщо поточний елемент менше опорного
        if (arr[j] < pivot)
        {
            i++; //індекс приросту меншого елемента
            swap1(&arr[i], &arr[j]);
        }
    }
    swap1(&arr[i + 1], &arr[high]);
    return (i + 1);
}
// Основна функція, яка реалізує QuickSort arr [] -> масив для сортування, низький -> Початковий індекс, високий -> Кінцевий індекс
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        //pi - індекс розділення, arr [p] - зараз в потрібному місці
        int pi = partition(arr, low, high);

        // Окремо сортуйте елементи раніше розділ і після розділу
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
// Функція друку масиву
void printArrayQui(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int Random(int min, int max)
{
    return min + rand() % (max - min);
}
int main()
{
    ////BubbleSort
    //int arrBub[100000];
    //for (int i = 0; i < 100000; i++)
    //{
    //  arrBub[i] = Random(-1000, 1000);
    //}
    //clock_t start = clock();
    //int n = sizeof(arrBub) / sizeof(arrBub[0]);
    //bubbleSort(arrBub, n);
    //cout << "Bubble sorted array: \n";
    ////printArrayBub(arrBub, n);
    //clock_t end = clock();
    //double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    //cout << seconds << " seconds" << endl;

    ////InsertionSort
    //int arrIns[100000];
    //for (int i = 0; i < 100000; i++)
    //{
    //  arrIns[i] = Random(-1000, 1000);
    //}
    //clock_t start1 = clock();
    //
    //int n11 = sizeof(arrIns) / sizeof(arrIns[0]);

    //insertionSort(arrIns, n11);
    //cout << "Insertion sorted array: \n";
    ////printArrayIns(arrIns, n11);
    //clock_t end1 = clock();
    //double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    //cout << seconds1 << " seconds" << endl;

    //SelectionSort
    int arrSel[100000];
    for (int i = 0; i < 100000; i++)
    {
        arrSel[i] = Random(-1000, 1000);
    }
    clock_t start2 = clock();
    int n2 = sizeof(arrSel) / sizeof(arrSel[0]);
    selectionSort(arrSel, n2);
    cout << "Selection sorted array: \n";
    //printArraySel(arrSel, n2);
    clock_t end2 = clock();
    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    cout << seconds2 << " seconds" << endl;

    //MergeSort

    int arrMer[100000];
    for (int i = 0; i < 100000; i++)
    {
        arrMer[i] = Random(-1000, 1000);
    }
    clock_t start3 = clock();

    int arr_size = sizeof(arrMer) / sizeof(arrMer[0]);

    printf("Merge sorted array \n");
    //printArray(arrMer, arr_size);

    mergeSort(arrMer, 0, arr_size - 1);

    //printf("\nSorted array is \n");
    //printArray(arrMer, arr_size);
    clock_t end3 = clock();
    cout << endl;
    double seconds3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    cout << seconds3 << " seconds" << endl;

    ////QuickSort
    //int arrQui[100000];
    //for (int i = 0; i < 100000; i++)
    //{
    //  arrQui[i] = Random(-1000, 1000);
    //}
    //clock_t start4 = clock();
    //
    //int n4 = sizeof(arrQui) / sizeof(arrQui[0]);
    //quickSort(arrQui, 0, n4 - 1);
    //cout << "Quick sorted array: \n";
    ////printArrayQui(arrQui, n4);
    //clock_t end4 = clock();
    //double seconds4 = (double)(end4 - start4) / CLOCKS_PER_SEC;
    //cout << seconds4 << " seconds" << endl;
    system("pause");
    return 0;
}