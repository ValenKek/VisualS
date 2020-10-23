#include <iostream>
#include <ctime>
#include <windows.h>
#include "ControlHeaders.h"
#include "SortOneDHeaders.h"

void SortOneDHeaders::bubble_sort(int* arr, int n) {
	for ( int i = n - 1, j = 0, tmp; i > 0; --i) {
		while (j < i) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			++j;
		}
		j = 0;
	}
}

void SortOneDHeaders::insertion_sort(int* arr, int n)
{
	for (int i = 1, j; i < n; ++i) {
		j = 0;
		while (j < i) {
			if (arr[j] > arr[i])
				break;
			++j;
		}
		ControlHeaders::shiftArr(arr, i, j, n);
	}
}

void SortOneDHeaders::selection_sort(int* arr, int n) {
	for (int i = 0, k = 0; i < n - 1; ++i) {
		k = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[k] > arr[j])
				k = j;
		}
		if (k != i) {
			arr[i] = arr[k] + arr[i];
			arr[k] = arr[i] - arr[k];
			arr[i] = arr[i] - arr[k];
		}
	}
}

void SortOneDHeaders::merge(int* arr, int first, int middle, int last, int n) {
	int* tmp = new int[last - first + 1];
	int i = first, j = middle + 1, k = 0;
	while (i <= middle && j <= last) {
		if (arr[i] <= arr[j])
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
	while (j <= last)
	{
		tmp[k] = arr[j];

		k++;
		j++;
	}
	for (int i = first; i <= last; i++) {
		arr[i] = tmp[i - first];
	}
}

void SortOneDHeaders::merge_sort(int* arr, int first, int last, int n) {
	if (first < last) {
		int mid = (first + last) / 2;
		merge_sort(arr, first, mid,n);
		merge_sort(arr, mid + 1, last,n);
		merge(arr, first, mid, last,n);
	}
}

void SortOneDHeaders::quick_sort(int* arr, int first, int last, int n)
{
	int f = first;
	int l = last;
	int mid = arr[(f + l) / 2];
	do
	{
		while (arr[f] < mid) f++;
		while (arr[l] > mid) l--;
		if (f <= l)
		{
			std::swap(arr[f], arr[l]);
			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quick_sort(arr, first, l,n);
	if (f < last)quick_sort(arr, f, last,n);
}