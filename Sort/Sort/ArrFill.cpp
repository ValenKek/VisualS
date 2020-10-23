#include <iostream>
#include <ctime>
#include <windows.h>

#include "ArrHeaders.h"
#include "ControlHeaders.h"
#include "SortTwoDHeaders.h"
#include "SortOneDHeaders.h"

void ArrHeaders::arr_rand(int* arr, int n) { //Для рандому
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 2001 - 1000;
		
	}
}
void ArrHeaders::arr_decrease(int* arr, int n) { //Для спадання
	int j = n;
	for (int i = 0; i < n; i++) {
		arr[i] = j;
		j--;
	}
}
void ArrHeaders::arr_two(int* arr, int n) { //Для двух значень
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 2;
	}
}
void ArrHeaders::arr_same(int* arr, int n) { //Однакові значення
	for (int i = 0; i < n; i++) {
		arr[i] = 1;
	}
}