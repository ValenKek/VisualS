#include <iostream>
#include "ArrHeaders.h"
#include "ControlHeaders.h"
#include "SortTwoDHeaders.h"
#include "SortOneDHeaders.h"
#include <ctime>
#include <windows.h>
#include <fstream>

static bool askF()
{
	bool answ;
	std::cout << "Continue? 1=yes, 0=no.";
	std::cin >> answ;
	return (answ);
}
void main() {
	srand(time(0));

	int n;


	/*//                              перше завдання
	n = ControlHeaders::control();
	int* arr = new int[n];
	ArrHeaders::arr_rand(arr, n); //Для рандому
	//ArrHeaders::arr_decrease(arr); //Для спадання
	//ArrHeaders::arr_two(arr); //Для двух значеннь
	//ArrHeaders::arr_same(arr); //Однакові значення
	//ControlHeaders::show(arr, n);

	unsigned int start_time = clock(); //початковий час

	SortOneDHeaders::bubble_sort(arr, n);
	//SortOneDHeaders::insertion_sort(arr,n);
	//SortOneDHeaders::selection_sort(arr,n);
	//SortOneDHeaders::merge_sort(arr, 0, n - 1,n);
	//SortOneDHeaders::quick_sort(arr, 0, n-1,n);

	//ControlHeaders::show(arr, n);

	unsigned int end_time = clock();//шуканий час

	unsigned int search_time = end_time - start_time;
	std::cout << "\nProgram run time:" << search_time << std::endl;
	system("pause");*/ 
	//                             Друге завдання

		n = 5;
		int** arr;
		arr = new int* [5];
		int choice;
		for (int i = 0; i < 5; i++) {
			arr[i] = new int[5];
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				//arr[i][j] = 5 - i;
				arr[i][j] = rand() % 5;
			}
		}
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				std::cout << arr[i][j] << " ";
			}
			std::cout << std::endl;
		}

		do
		{
			std::cout << std::endl << "Chose a column:";
			std::cin >> choice;
			/*
			int* tmp = new int[5];
			for (int i = 0; i < 5; i++) {
				tmp[i] = arr[i][choice];
				arr[i][choice] = arr[i][0];
			}
			for (int i = 0; i < 5; i++) {
				arr[i][0] = tmp[i];
				;
			}*/

			std::cout << std::endl;
			//SortTwoDHeaders::twoD_bubble_sort(arr, n);
			//SortTwoDHeaders::twoD_insertion_sort(arr,n-1);
			//SortTwoDHeaders::twoD_selection_sort(arr,n, );
			//SortTwoDHeaders::twoD_merge_sort(arr, 0, n - 1,n);
			//SortTwoDHeaders::twoD_quick_sort(arr, 0, n-1,n);
			//SortTwoDHeaders::show(arr, n);
			{
				int* tmp = new int[5];
				for (int i = 0; i < 5; i++) {
					tmp[i] = arr[i][0];
					arr[i][0] = arr[i][choice];
				}
				for (int i = 0; i < 5; i++) {
					arr[i][choice] = tmp[i];;
				}
			}
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					std::cout << arr[i][j] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		} while (askF());
	//                               Трете завдання
	/*std::ofstream fout;
	fout.open("quick_sort.txt");
	if (!fout.is_open()) {
		std::cout << "Error";
	}
	else {
		for (int i = 1000; i<=100000;i+=1000)
		{
			n =i;
			int* arr = new int[n];
			ArrHeaders::arr_rand(arr, n);

			unsigned int start_time = clock(); //початковий час

			//SortOneDHeaders::bubble_sort(arr, n);
			//SortOneDHeaders::insertion_sort(arr,n);
			//SortOneDHeaders::selection_sort(arr,n);
			//SortOneDHeaders::merge_sort(arr, 0, n - 1,n);
			SortOneDHeaders::quick_sort(arr, 0, n-1,n);

			unsigned int end_time = clock();//шуканий час

			unsigned int search_time = end_time - start_time;
			fout <<n<<" "<< search_time << std::endl;
			
		}
		fout.close();
	}*/
}