#pragma once

class SortTwoDHeaders {
public:
	static void twoD_bubble_sort(int* arr[], int n);
	static void twoD_selection_sort(int* arr[], int n, int choice);
	static void twoD_insertion_sort(int* arr[], int n);
	static void twoD_merge_sort(int* arr[], int first, int last);
	static void twoD_merge(int* arr[], int first, int middle, int last);
	static void twoD_quick_sort(int* arr[], int first, int last, int n);
};