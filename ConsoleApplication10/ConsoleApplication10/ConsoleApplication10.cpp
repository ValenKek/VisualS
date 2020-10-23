
#include "iostream"
#include <iomanip>
#include <stdio.h>
#include "cmath"
using namespace std;
int konec()
{
	int otvet;
	cout << endl << "Продолжить? 1)ДА; 2)НЕТ." << endl;
	cin >> otvet;
	cout << endl;
	return otvet;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	do {
		int scet = 0;
		long int a, b, m;
		long int fi;
		long int x;
		cout << "Данно уравнение ax \u2261 b(mod m)" << endl;
		cout << "Введите а: ";
		cin >> a;
		cout << "Введите b: ";
		cin >> b;
		cout << "Введите m: ";
		cin >> m;
		fi = m;
		//-----------------------------------------------
		for (int i = 2; i < m; i++)
		{
			if (m % i == 0)
			{
				fi *= 1. - 1. / i;
				scet++;
			}
		}
		if (scet == 0)
		{
			fi = m - 1;
		}

		cout << "fi=" << fi << endl;
		//-----------------------------------------------
		int step1, step2;
		int i = 2, schet2 = 0;
		for (int i = 2; i < 100; i++)
		{
			if ((fi - 1) % i == 0)
			{

				step1 = i;
				step2 = (fi - 1) / i;
				long long int step11 = pow(a, step1);
				long long int m1 = abs(step11 % m);
				long long int step12 = pow(m1, step2);
				break;
				schet2++;
			}

		}
		if (schet2 == 0)
		{
			long long int step = pow(a, fi - 1);
			cout << "x=" << abs(((step % m) * b) % m);
		}
	} while (konec() == 1);
}