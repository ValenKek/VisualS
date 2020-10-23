#pragma once

	class Sorting
	{

	public:

		static void bubleSort( int* arr, unsigned int n);
		static void insertSort(int* arr, int n);
		static void selectionSort(int* arr, int n);
		static void mergeSort(int* arr, int start, int end);
		static void quickSort(int* a, int start, int end);
		static void merge(int* arr, int start, int middle, int end);
		static void radixSort(int* arr, int minElem, int dip, int n);

	};
