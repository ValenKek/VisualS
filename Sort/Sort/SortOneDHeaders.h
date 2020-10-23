#pragma once

class SortOneDHeaders {
public:
	static void bubble_sort(int* arr, int n);
	static void selection_sort(int* arr, int n);
	static void insertion_sort(int* arr, int n);
	static void merge_sort(int* arr, int start, int end, int n);
	static void merge(int* arr, int start, int middle, int end, int n);
	static void quick_sort(int* arr, int first, int last, int n);
};