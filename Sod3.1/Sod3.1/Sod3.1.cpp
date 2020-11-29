#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <windows.h>
#include <locale.h>

void exercise3_3();//Завдання №1
void exercise1_2();//Завдання №2
void exercise1_2_2();//Завдання №3
void exercise1_3();//Завдання №4

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	std::cout << "Enter the number of exercice to perform: \n";
	std::cin >> choice;//Вибір номеру завдання
	std::cin.ignore();
	switch (choice) {
	case 1: {
		exercise3_3();
		break;
	}
	case 2: {
		exercise1_2();
		break;
	}
	case 3: {
		exercise1_2_2();
		break;
	}
	case 4: {
		exercise1_3();
		break;
	}
	default:
		break;
	}
	std::cout << "\n\n";
	return 0;
}

void exercise3_3() {
	const int arrSize = 10;
	int arr[arrSize];
	for (int index = 0; index < arrSize; ++index) {
		arr[index] = index;
	}
	std::ofstream ofs("z3_3.txt", std::ios::binary);
	if (!ofs.is_open()) {
		std::cout << "An error has occurred\n";
		return;
	}
	ofs.write((char*)arr, sizeof(arr));

	ofs.close();

	int newNum;
	int numIndex;
	std::cout << "Enter the number and its index\n";
	std::cin >> newNum >> numIndex;

	std::fstream fst("z3_3.txt", std::ios::binary | std::ios::in | std::ios::out);
	if (!fst.is_open()) {
		std::cout << "An error has occurred\n";
		return;
	}
	fst.seekg(0, std::ios::end);
	int lenght = fst.tellg();
	std::cout << "The file size ist: " << lenght << "bytes\n";
	int possition = numIndex * sizeof(int);

	std::cout << "Position of the edited element: " << possition << '\n';
	fst.seekp(possition, std::ios::beg);
	fst.write((char*)&newNum, sizeof(int));
	fst.seekg(0);
	fst.read((char*)&arr, sizeof(arr));
	for (int index = 0; index < arrSize; ++index)
	{
		std::cout << arr[index] << " ";
	}
}

void exercise1_2() {
	int arrSize;
	std::cout << "Enter the size of array\n";
	std::cin >> arrSize;
	int* arr = new int[arrSize];
	for (int index = 0; index < arrSize; ++index) {
		arr[index] = index;
	}
	std::ofstream ofs("z3_3.txt", std::ios::binary);
	if (!ofs.is_open()) {
		std::cout << "An error has occurred\n";
		return;
	}
	ofs.write((char*)arr, sizeof(arr) * arrSize);

	ofs.close();

	int newNum;
	int numIndex;
	std::fstream fst("z3_3.txt", std::ios::binary | std::ios::in | std::ios::out);
	std::cout << "Enter the number and its index\n";
	std::cin >> newNum >> numIndex;

	if (!fst.is_open()) {
		std::cout << "An error has occurred\n";
		return;
	}
	fst.seekg(0, std::ios::end);
	int lenght = fst.tellg();
	std::cout << "The file size ist: " << lenght << "bytes\n";
	int possition = numIndex * sizeof(int);

	std::cout << "Position of the edited element: " << possition << '\n';
	fst.seekp(possition, std::ios::beg);
	fst.write((char*)&newNum, sizeof(int));
	fst.seekp(0);

	fst.read((char*)arr, sizeof(arr) * arrSize);
	for (int index = 0; index < arrSize; ++index)
	{
		std::cout << arr[index] << " ";
	}
}
void exercise1_2_2() {
	int arrSize;
	std::cout << "Enter the size of array\n";
	std::cin >> arrSize;
	int** arr = new int* [arrSize];
	for (int index = 0; index < arrSize; ++index) {
		arr[index] = new int[arrSize];
	}
	for (int index = 0; index < arrSize; ++index) {
		for (int index2 = 0; index2 < arrSize; ++index2) {
			arr[index][index2] = index2 + index * arrSize;
			std::cout << arr[index][index2] << " ";
		}
		std::cout << "\n";
	}
	std::ofstream ofs("z3_3.txt", std::ios::binary);
	if (!ofs.is_open()) {
		std::cout << "An error has occurred\n";
		return;
	}
	//ofs.write((char*)arr, sizeof(arr));
	for (int index = 0; index < arrSize; ++index)
		ofs.write((char*)arr[index], sizeof(arr) * arrSize);

	ofs.close();

	int newNum;
	int numIndex;
	int numIndex2;
	std::cout << "Enter the number and its index1 && index2\n";
	std::cin >> newNum >> numIndex >> numIndex2;

	std::fstream fst("z3_3.txt", std::ios::binary | std::ios::in | std::ios::out);
	if (!fst.is_open()) {
		std::cout << "An error has occurred\n";
		return;
	}
	fst.seekg(0, std::ios::end);
	int lenght = fst.tellg();
	std::cout << "The file size ist: " << lenght << "bytes\n";
	int possition = (numIndex * arrSize * sizeof(int)) + numIndex2 * sizeof(int);

	std::cout << "Position of the edited element: " << possition << '\n';
	fst.seekp(possition, std::ios::beg);
	fst.write((char*)&newNum, sizeof(int));
	fst.seekg(0);
	for (int index = 0; index < arrSize; ++index)
		fst.read((char*)arr[index], sizeof(arr) * arrSize);

	for (int index = 0; index < arrSize; ++index) {
		for (int index2 = 0; index2 < arrSize; ++index2) {
			std::cout << arr[index][index2] << " ";
		}
		std::cout << "\n";
	}
}

void exercise1_3() {
	const int arrSize = 10;
	int arr[arrSize];
	for (int index = 0; index < arrSize; ++index) {
		arr[index] = index;
	}
	for (int index = 0; index < arrSize; ++index) {
		std::cout << arr[index] << " ";
	}
	std::ofstream ofs("z3_3.txt", std::ios::binary);
	if (!ofs.is_open()) {
		std::cout << "An error has occurred\n";
		return;
	}
	for (int index = 0; index < arrSize; ++index)
		ofs.write((char*)&arr[index], sizeof(int));

	ofs.close();

	int newNum;
	int numIndex;
	int numIndex2;
	std::cout << "Enter the index you want to delete\n";
	std::cin >> numIndex;

	std::fstream fst("z3_3.txt", std::ios::binary | std::ios::in | std::ios::out);
	if (!fst.is_open()) {
		std::cout << "An error has occurred\n";
		return;
	}
	fst.seekg(0, std::ios::end);
	int lenght = fst.tellg();
	std::cout << "The file size ist: " << lenght << "bytes\n";
	int possition = (numIndex * sizeof(int));
	int tmp[arrSize - 1];

	fst.seekp(possition, std::ios::beg);
	for (int index = numIndex + 1; index < arrSize; ++index) {
		fst.write((char*)&arr[index], sizeof(int));
	}
	fst.seekg(0);
	fst.read((char*)arr, sizeof(arr));

	for (int index = 0; index < arrSize - 1; ++index) {
		std::cout << arr[index] << " ";
	}
	fst.close();
}