
#include <iostream>
#include <time.h>
#include "Sorting.h"
#include "ArrayController.h"
#include "MultArrSorting.h"
#include "Sorting.h"
#include "Controller.h"
#include <ctime>
#include <chrono>
#include <fstream>
typedef std::chrono::high_resolution_clock Clock;

void Controller::sort() {
    int sortMethod;
    while (true) {
        std::cout << "Select a method of sorting\n\n1 - buble sort\n2 - insert sort\n3 - selection sort\n4 - merge sort\n5 - quick sort\n6 - radix sort\n\n";
        std::cin >> sortMethod;
        if (sortMethod > 0 && sortMethod < 7) break;
        std::cout << "Try again(press enter to cont)\n";
        system("pause");
        system("clear");
    }
    int size;
    while (true) {
        std::cout << "Write the size of array\n";
        std::cin >> size;
        if (size > 0) break;
        std::cout << "Try again(press enter to cont)\n";
        system("pause");
        system("clear");
    }
    int* arr = new int[size];
    ArrayController::setElementsValue(arr, size);
    std::cout << "\nBefore\n";
    auto t1 = Clock::now();
    auto t2 = Clock::now(); 
    //ArrayController::showElems(arr, size);
    switch (sortMethod) {
    case 1: {
        Sorting::bubleSort(arr, size);
        break;
    }
    case 2: {
        Sorting::insertSort(arr, size);
        break;
    }
    case 3: {
        Sorting::selectionSort(arr, size);
        break;
    }
    case 4: {
        Sorting::mergeSort(arr, 0, size);
        break;
    }
    case 5: {
        Sorting::quickSort(arr, 0, size);
        break;
    }
    case 6: {
        t1 = Clock::now();
        Sorting::radixSort(arr, -1000, 2000, size);

        t2 = Clock::now();
        std::cout << "Time is: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
            << " milliseconds" << std::endl;
        break;
    }
    default: {
        break;
    }
    }
    std::cout << "\nAfter\n";
   // ArrayController::showElems(arr, size);
}
void Controller::checkSortsTime() {
    int size;
    while (true) {
        std::cout << "Write the size of array\n";
        std::cin >> size;
        if (size > 0) break;
        std::cout << "Try again(press enter to cont)\n";
        system("pause");
        system("clear");
    }
    int* arr = new int[size];
    auto t1 = Clock::now();
    auto t2 = Clock::now();
    std::cout << "\n\nNOTATION\nFirst number -> from -1000 to 1000\nSecond number -> from the biggest to the lowest\nThird number -> two values in random places\nFour number -> one value\n\n";
    std::cout << "\nBubble sort\n";
    for (int i = 0; i < 4; i++) {
        ArrayController::setElementsValue(arr, size, i);
        t1 = Clock::now();
        Sorting::bubleSort(arr, size);
        t2 = Clock::now();
        std::cout << "Time is: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
            << " milliseconds" << std::endl;
    }
    std::cout << "\nInsert sort\n";
    for (int i = 0; i < 4; i++) {
        ArrayController::setElementsValue(arr, size, i);
        t1 = Clock::now();
        Sorting::insertSort(arr, size);

        t2 = Clock::now();
        std::cout << "Time is: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
            << " milliseconds" << std::endl;
    }
    std::cout << "\nSelection sort\n";
    for (int i = 0; i < 4; i++) {
        ArrayController::setElementsValue(arr, size, i);
        t1 = Clock::now();
        Sorting::selectionSort(arr, size);
        t2 = Clock::now();
        std::cout << "Time is: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
            << " milliseconds" << std::endl;
    }
    std::cout << "\nMerge sort\n";
    for (int i = 0; i < 4; i++) {
        ArrayController::setElementsValue(arr, size, i);
        t1 = Clock::now();
        Sorting::mergeSort(arr, 0, size);
        t2 = Clock::now();
        std::cout << "Time is: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
            << " milliseconds" << std::endl;
    }
    std::cout << "\nQuick sort\n";
    for (int i = 0; i < 4; i++) {
        ArrayController::setElementsValue(arr, size, i);
        t1 = Clock::now();
        Sorting::quickSort(arr, 0, size);
        t2 = Clock::now();
        std::cout << "Time is: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
            << " milliseconds" << std::endl;
    }
}
void Controller::secondTask() {
    int columns, rows;
    while (true) {
        std::cout << "Write the size of array(columns, rows)\n";
        std::cin >> columns;
        std::cin >> rows;
        if (columns > 0 && rows > 0) break;
        std::cout << "Try again(press enter to cont)\n";
        system("pause");
        system("clear");
    }
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[columns];
    }
    ArrayController::setElementsValue(arr, columns, rows);
    int** copy = new int* [rows];
    for (int i = 0; i < rows; i++) {
        copy[i] = new int[columns];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            copy[i][j] = arr[i][j];
        }
    }
    int from;
    while (true) {
        std::cout << "What column you wanna sort?\n";
        std::cin >> from;
        if (from > 0 && from < columns) break;
        std::cout << "Try again(press enter to cont)\n";
        system("pause");
        system("clear");
    }
    std::cout << "\nBefore\n";
    ArrayController::showElems(arr, columns, rows);
    ArrayController::replaceColumn(arr, from, rows);

    std::cout << "\nBubble sort\n";
    MultArrSorting::bubleSort(arr, rows);
    ArrayController::replaceColumn(arr, from, rows);
    ArrayController::showElems(arr, columns, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            arr[i][j] = copy[i][j];
        }
    }
    ArrayController::replaceColumn(arr, from, rows);


    std::cout << "\nInsert sort\n";

    MultArrSorting::insertSort(arr, rows);
    ArrayController::replaceColumn(arr, from, rows);
    ArrayController::showElems(arr, columns, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            arr[i][j] = copy[i][j];
        }
    }
    ArrayController::replaceColumn(arr, from, rows);

    std::cout << "\nSelection sort\n";
    MultArrSorting::selectionSort(arr, rows);
    ArrayController::replaceColumn(arr, from, rows);
    ArrayController::showElems(arr, columns, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            arr[i][j] = copy[i][j];
        }
    }
    ArrayController::replaceColumn(arr, from, rows);

    std::cout << "\nMerge sort\n";
    MultArrSorting::mergeSort(arr, 0, rows-1);
    ArrayController::replaceColumn(arr, from, rows);
    ArrayController::showElems(arr, columns, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            arr[i][j] = copy[i][j];
        }
    }
    ArrayController::replaceColumn(arr, from, rows);

    std::cout << "\nQuick sort\n";
    MultArrSorting::quickSort(arr, 0, rows-1);
    ArrayController::replaceColumn(arr, from, rows);
    ArrayController::showElems(arr, columns, rows);
}
void Controller::thirdTask() {
    int* arr = new int[100000];
    std::ofstream fout;
    auto t1 = Clock::now();
    auto t2 = Clock::now();
    fout.open("selectionSort.txt");
    if (!fout.is_open()) {
        std::cout << "Error";
    }
    else {
        for (int i = 1000; i <= 100000; i += 1000)
        {
            ArrayController::setElementsValue(arr, i);
            t1 = Clock::now();
            Sorting::selectionSort(arr, i);
            t2 = Clock::now();
            fout << i << '\t' << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << '\n';
        }
        fout.close();
    }
}
void Controller::menu() {
    int deyst;
    while (true) {
        std::cout << "\n\nSelect a task\n(1, 2, 3, 4)\n";
        std::cin >> deyst;
        if (deyst > 0 && deyst < 5) break;
        std::cout << "Try again(press enter to cont)\n";
        system("pause");
        system("clear");
    }
    std::cout << "\n";
    switch (deyst) {
    case 1: {
        sort();
        break;
    }
    case 2: {
        checkSortsTime();
        break;
    }
    case 3: {
        secondTask();
        break;
    }
    case 4: {
        thirdTask();
        break;
    }
    default: {
        break;
    }
    }

    }
