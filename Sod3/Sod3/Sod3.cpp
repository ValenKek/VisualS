#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <windows.h>
#include <locale.h>

void exercise3_1();//Завдання №1
void exercise1_1();//Завдання №2
void exercise3_2();//Завдання №3
void exercise1_2();//Завдання №4

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	std::cout << "Enter the number of exercice to perform: \n";
	std::cin >> choice;//Вибір номеру завдання
	std::cin.ignore();
	switch (choice) {
	case 1: {
		exercise3_1();
		break;
	}
	case 2: {
		exercise1_1();
		break;
	}
	case 3: {
		exercise3_2();
		break;
	}
	case 4: {
		exercise1_2();
		break;
	}
	default:
		break;
	}
	std::cout << "\n\n";
	return 0;
}

void exercise3_1() {//Завдання №1
	std::ifstream is("Shakespeare_WintersTale.txt");//Відкриття файлу
	if (!is.is_open()) {
		std::cout << "Error\n";
		return;
	}
	int lenght;
	is.seekg(0, std::ios::end);//Пошук кінця файлу, для разрахування його розміру
	lenght = is.tellg();//Розмір файлу
	is.seekg(0, std::ios::beg);

	//Розбиття тексту на лексеми та запис у масив
	char* arr = new char[lenght];
	is.read(arr, lenght);
	--lenght;
	arr[lenght] = '\0';

	long n = 0, i = 0;
	while (arr[i]) {
		if (arr[i] == '?') {
			for (int j = n; j <= i; j++)
			{
				if (j == i) std::cout << arr[j] << std::endl;
				else std::cout << arr[j];
			}
			n = i + 1;
		}
		if (arr[i] == '.' || arr[i] == '!' || arr[i] == '\n') n = i + 1;
		i++;
	}
	is.close();
}
void exercise1_1() {//Завдання №2
	std::ifstream is("Shakespeare_WintersTale.txt");//Відкриття файлу
	std::ofstream off("txt.txt");
	if (!is.is_open()) {
		std::cout << "Error\n";
		return;
	}
	int lenght;
	is.seekg(0, std::ios::end);//Пошук кінця файлу, для разрахування його розміру
	lenght = is.tellg();//Розмір файлу
	is.seekg(0, std::ios::beg);

	//Розбиття тексту на лексеми та запис у масив
	char* arr = new char[lenght];
	is.read(arr, lenght);
	--lenght;
	arr[lenght] = '\0';

	long n = 0, i = 0;
	while (arr[i]) {
		if (arr[i] == '?') {
			for (int j = n; j <= i; j++)
			{
				if (j == i) off << arr[j] << std::endl;
				else off << arr[j];
			}
			n = i + 1;
		}
		if (arr[i] == '.' || arr[i] == '!' || arr[i] == '\n') n = i + 1;
		i++;
	}
	is.close();
}
void exercise3_2() {//Завдання №3
	int arr1[] = { 0, 10, 4, 25, 1000, 14, 0, 47, 11, 1 };
	char arr2[] = { 'a', '\ 0', 'b' };
	double m = 3.14, n = 0.0003;
	// відкриття для запису
	std::ofstream is("Z3.dat", std::ios::binary);
	if (!is.is_open()) {
		std::cout << "Error\n";
		return;
	}
	// Запис 8 Байт - розмір m
	is.write((char*)&m, sizeof(m));
	// Запис 8 Байт - розмір n
	is.write((char*)&n, sizeof(n));
	// Запис 4Байт*10 - розмір масиву arr1
	for (int i = 0; i < 10; i++) {
		is.write((char*)&arr1[i], sizeof(arr1[i]));
	}
	// Запис 1Байт *3 - розмір масиву arr2
	for (int i = 0; i < 3; i++) {
		is.write((char*)&arr2[i], sizeof(arr2[i]));
	}
	is.close(); // закриття файлу
	// відкриття для читання
	std::ifstream fout("Z3.dat", std::ios::binary);
	if (!fout.is_open()) { // перевірка
		std::cout << "Error!" << std::endl;
		return;
	}
	fout.seekg(0, std::ios::end); // перехід в кінець файлу
	// поточна позиція в байтах, виміряна від початку
	long len = fout.tellg(); std::cout << len << std::endl;
	fout.close();
}

void exercise1_2() {//Завдання №4
	std::ifstream is("Shakespeare_WintersTale.txt");//Відкриття файлу
	std::ofstream os("z3_31.dat", std::ios::binary);
	if (!os.is_open()) {
		std::cout << "Open z3_31 error\n";
		return;
	}
	if (!is.is_open()) {
		std::cout << "Error\n";
		return;
	}
	int lenght;
	is.seekg(0, std::ios::end);//Пошук кінця файлу, для разрахування його розміру
	lenght = is.tellg();//Розмір файлу
	is.seekg(0, std::ios::beg);

	//Розбиття тексту на лексеми та запис у масив
	char* arr = new char[lenght];
	is.read(arr, lenght);
	--lenght;
	arr[lenght] = '\0';

	long n = 0, i = 0;
	while (arr[i]) {
		if (arr[i] == '?') {
			for (int j = n; j <= i; j++)
			{
				if (j == i) os.write((char*)&arr[j], sizeof(char));
				else os.write((char*)&arr[j], sizeof(char));
			}
			n = i + 1;
		}
		if (arr[i] == '.' || arr[i] == '!' || arr[i] == '\n') n = i + 1;
		i++;
	}
	is.close();
}