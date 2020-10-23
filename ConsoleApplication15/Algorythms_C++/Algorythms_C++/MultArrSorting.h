#pragma once
class MultArrSorting
{
	public:

		static void bubleSort(int* arr[], unsigned int n);
		static void insertSort(int* arr[], int n);
		static void selectionSort(int* arr[], int n);
		static void mergeSort(int* arr[], int start, int end);
		static int partition(int* arr[], int start, int end);
		static void quickSort(int* arr[], int start, int end);
		static void merge(int* arr[], int start, int middle, int end);
};
