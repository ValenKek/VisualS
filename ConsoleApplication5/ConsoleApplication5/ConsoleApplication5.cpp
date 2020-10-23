#include <iostream>

void arrfill(int* parr, int n, int m)
{
	for (int i = 0; i < n * m; i++)
	{
		*parr = i;
		std::cout << *parr++ << '\t';
		if ((i + 1) % m == 0)
			std::cout << '\n';
	}
	std::cout << std::endl << std::endl;
}
void arrmerg(int* parr1, int* parr2, int* parr3, int n, int m)
{
	for (int i = 0; i < n * m; i++)
	{
		*parr3 = *parr1+ *parr2;
		std::cout << *parr3 << '\t';
		if ((i + 1) % m == 0)
			std::cout << '\n';
		parr1++;
		parr2++;
		parr3++;
	}
}

int main()
{
	const int n = 8,m=8;
	int arr1[n][m];
	int arr2[n][m];
	int arr3[n][m];
	int* parr1 = &arr1[0][0];
	int* parr2 = &arr2[0][0];
	arrfill(parr1, n, m);
	arrfill(parr2, n, m);
	arrmerg(parr1, parr2, parr2,n,m);
}
