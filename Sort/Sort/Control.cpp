#include <iostream>
#include <ctime>
#include <windows.h>
#include "ArrHeaders.h"
#include "ControlHeaders.h"
#include "SortTwoDHeaders.h"
#include "SortOneDHeaders.h"
void ControlHeaders::show(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] <<std::endl;
	}
}

int ControlHeaders::control() {
	int n;
	while (true) {
		std::cout << "Enter number: ";
		std::cin >>n;
		if (std::cin.get() == '\n' && n > 0) break;
	}
	return n;
}


void ControlHeaders::shiftArr(int* arr, int from, int to, int n)
{
	int* tmp2 = arr;
	for (int i = from, tmp; i > to; --i) {
		tmp = arr[i - 1];
		arr[i - 1] = arr[i];
		arr[i] = tmp;
	}
}
void ControlHeaders::shiftArr(int* arr[], int from, int to, int n)
{
	int* tmp;
	for (int i = from; i > to; --i) {
		tmp = arr[i - 1];
		arr[i - 1] = arr[i];
		arr[i] = tmp;
	}
}