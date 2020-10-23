#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>
class ArrHeaders {
public:
	static void arr_rand(int* arr, int n) { //Для рандому
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % 2000;
		}
	}
	static void arr_decrease(int* arr, int n) { //Для спадання
		int j = n;
		for (int i = 0; i < n; i++) {
			arr[i] = j;
			j--;
		}
	}
	static void arr_two(int* arr, int n) { //Для двух значень
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % 2;
		}
	}
	static void arr_same(int* arr, int n) { //Однакові значення
		for (int i = 0; i < n; i++) {
			arr[i] = 1;
		}
	}
};

int main()
{
	srand(time(0));
	int n = 1000000, range = 1000000, i = 0;
	int* arr = new int[n];
	int* arr1 = new int[range];
	unsigned int start_time, end_time, search_time;
	//ArrHeaders::arr_rand(arr, n); //Для рандому
	//ArrHeaders::arr_decrease(arr,n); //Для спадання
	//ArrHeaders::arr_two(arr,n); //Для двух значеннь
	ArrHeaders::arr_same(arr,n); //Однакові значення

	for (i = 0; i < range; i++)
	{
		arr1[i] = 0;
	}

	start_time = clock();

	for (i = 0; i < n; i++)
	{
		arr1[arr[i]]++;
	}
	int k = 0;
	for (i = 0; i < range; i++)
	{
		for (int j = 0; j < arr1[i]; j++)
		{
			arr[k] = i;
			k++;
		}
	}
	end_time = clock();//шуканий час
	search_time = end_time - start_time;
	std::cout << range << " " << search_time << std::endl;

	/*
	std::ofstream fout;
	std::ofstream fout2;
	fout.open("radix _sort_quantity.txt");
	fout2.open("radix _sort_value.txt");

	if (!fout.is_open()) {
		std::cout << "Error";
		return 0;
	}
	int* arr = new int[1000000];

	unsigned int start_time, end_time, search_time;
	int n = 1000000;
	for (int range = 1000, i, k; range <= 1000000; range += 1000)
	{
		int* arr1 = new int[range];
		for (i = 0; i < n; i++)
		{
			arr[i] = rand() % range;
		}

		for (i = 0; i < range; i++)
		{
			arr1[i] = 0;
		}

		start_time = clock();

		for (i = 0; i < n; i++)
		{
			arr1[arr[i]]++;
		}
		k = 0;
		for (i = 0; i < range; i++)
		{
			for (int j = 0; j < arr1[i]; j++)
			{
				arr[k] = i;
				k++;
			}
		}
		end_time = clock();//шуканий час
		search_time = end_time - start_time;
		fout2 << range << " " << search_time << std::endl;
	}
	fout.close();
	fout2.close();*/
}