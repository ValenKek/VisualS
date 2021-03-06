﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <windows.h>
#include <locale.h>

void exercise2_1();//Завдання №1
void exercise1_1();//Завдання №2
void exercise2_2();//Завдання №3
void exercise1_2();//Завдання №4
void exerciseV14();//Завдання для 14го варіанту 

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice;
	std::cout << "Enter the number of exercice to perform: \n";
	std::cin >> choice;//Вибір номеру завдання
	std::cin.ignore();
	switch (choice) {
	case 1: {
		exercise2_1();
		break;
	}
	case 2: {
		exercise1_1();
		break;
	}
	case 3: {
		exercise2_2();
		break;
	}
	case 4: {
		exercise1_2();
		break;
	}
	case 5: {
		exerciseV14();
		break;
	}
	default:
		break;
	}
	std::cout << "\n\n";
	return 0;
}

void exercise1_1() {//Завдання №2
	std::ifstream is("text_city_ukr_ansi.txt");//Відкриття файлу
	if (!is.is_open()) {
		std::cout << "Error\n";
		return;
	}
	is.seekg(0, std::ios::end);//Пошук кінця файлу, для разрахування його розміру
	int length = is.tellg();//Розмір файлу
	is.seekg(0, std::ios::beg);

	char* buffer = new char[length];
	char* word = new char[length];
	std::cin.getline(word, length);
	//Розбиття тексту на лексеми та запис у масив 
	int lenghtWord = std::cin.tellg();
	--lenghtWord;
	--length;
	word[lenghtWord] = 0;
	is.read(buffer, length);
	buffer[length] = '\0';
	is.close();
	//Пошук слова задовільняючого умові, та вивід результату
	for (int index1 = 0, index2, index3; buffer[index1] != 0; ++index1) {
		for (index2 = index1, index3 = 0; word[index3] != 0 || buffer[index2] != 0; ++index2, ++index3)
		{
			if (buffer[index2] != word[index3])
				break;
			if (word[index3 + 1] == 0) {
				std::cout << "Found\n";
				return;
			}
		}
	}
	std::cout << "Not found\n";
	delete[] word;
	delete[] buffer;
}

void exercise1_2() {//Завдання №4
	std::ifstream is("Shakespeare_Hamlet.txt");//Відкриття файлу
	int length, wordLength;
	is.seekg(0, std::ios::end);//Пошук кінця файлу, для разрахування його розміру
	length = is.tellg();//Розмір файлу
	is.seekg(std::ios::beg);
	char* buffer = new char[length];
	is.read(buffer, length);

	char* word = new char[length];
	std::cin.getline(word, length);
	//Розбиття тексту на лексеми та запис у масив 
	buffer[length] = 0;
	wordLength = std::cin.tellg();
	wordLength -= 2;
	word[wordLength] = 0;

	int count = 0;
	char* pch;
	pch = strtok(buffer, " ,.");
	bool checker;
	while (pch != NULL)//Пошук слів задовільняючих умові, підрахування, та вивід результату
	{
		checker = true;
		for (int index = 0; pch[index] != '\0'; ++index) {
			if (pch[index] != word[index] || (pch[index + 1] == '\0' && word[index + 1] != '\0')) {
				checker = false;
				break;
			}
		}
		pch = strtok(NULL, " ,.-");
		if (checker) count++;
	}
	std::cout << count;
}

void exercise2_1() {//Завдання №1
	std::ifstream is("text_city.txt");//Відкриття файлу
	if (!is.is_open()) {
		std::cout << "Error\n";
		return;
	}
	is.seekg(0, std::ios::end);//Пошук кінця файлу, для разрахування його розміру
	int length = is.tellg();//Розмір файлу
	is.seekg(0, std::ios::beg);

	char* buffer = new char[length];
	char* word = new char[length];
	std::cin.getline(word, length);
	//Розбиття тексту на лексеми та запис у масив 
	int lenghtWord = std::cin.tellg();
	--lenghtWord;
	--length;
	word[lenghtWord] = 0;
	is.read(buffer, length);
	buffer[length] = 0;
	is.close();
	//Пошук слова задовільняючого умові, та вивід результату
	for (int index1 = 0, index2, index3; buffer[index1] != 0; ++index1) {
		for (index2 = index1, index3 = 0; word[index3] != 0 || buffer[index2] != 0; ++index2, ++index3)
		{
			if (buffer[index2] != word[index3])
				break;
			if (word[index3 + 1] == 0) {
				std::cout << "Found\n";
				return;
			}
		}
	}
	std::cout << "Not found\n";
	delete[] buffer, word;
}
void exercise2_2() {//Завдання №3
	std::ifstream is("Shakespeare_Hamlet.txt");
	int length, wordLength;
	is.seekg(0, std::ios::end);//Пошук кінця файлу, для разрахування його розміру
	length = is.tellg();//Розмір файлу
	is.seekg(std::ios::beg);
	char* buffer = new char[length];
	is.read(buffer, length);

	char* word = new char[length];
	std::cin.getline(word, length);
	//Розбиття тексту на лексеми та запис у масив 
	buffer[length] = 0;
	wordLength = std::cin.tellg();
	wordLength -= 2;
	word[wordLength] = 0;

	int count = 0;
	char* pch;
	char separators[]{ '.', ',','!','?',';', '\n', ' ', '\0' };

	pch = strtok(buffer, separators);
	bool checker;
	while (pch != NULL)//Пошук слів задовільняючих умові, підрахування, та вивід результату
	{
		checker = true;
		for (int index = 0; pch[index] != '\0'; ++index) {
			if (pch[index] != word[index] || (pch[index + 1] == '\0' && word[index + 1] != '\0')) {
				checker = false;
				break;
			}
		}
		pch = strtok(NULL, separators);
		if (checker) count++;
	}
	std::cout << count;
}

void exerciseV14() {
	std::ifstream is("text.txt");//Відкриття файлу
	int lenght;

	is.seekg(0, std::ios::end);//Пошук кінця файлу, для разрахування його розміру
	lenght = is.tellg();//Розмір файлу
	is.seekg(0, std::ios::beg);
	//Розбиття тексту на лексеми та запис у масив 
	char* arr = new char[lenght];
	is.read(arr, lenght);
	--lenght;
	arr[lenght] = 0;
	is.close();
	int index = 0;

	while (arr[index] != '\0') {//Пошук чисел та вивід іх текстових аналогів 
		switch (arr[index])
		{
		case '0':
			std::cout << "нуль ";

			break;
		case '1':
			std::cout << "один ";

			break;
		case '2':
			std::cout << "два ";

			break;
		case '3':
			std::cout << "три ";

			break;
		case '4':
			std::cout << "чотири ";

			break;
		case '5':
			std::cout << "п'ять ";

			break;
		case '6':
			std::cout << "шість ";

			break;
		case '7':
			std::cout << "сім ";

			break;
		case '8':
			std::cout << "вісім ";

			break;
		case '9':
			std::cout << "дев'ять ";

			break;
		case '.':
			std::cout << ".\n";

			break;
		default:
			std::cout << arr[index];

			break;
		}
		++index;
	}
}