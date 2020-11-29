#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
using namespace std;

int n = 10;

void print(int* a);

class radix_test
{
	const int bit; // bit position [0..31] to examine
public:
	radix_test(int offset) : bit(offset) {} // constructor

	bool operator()(int value) const // function call operator
	{
		if (bit == 31) // sign bit
			return value < 0; // negative int to left partition
		else
			return !(value & (1 << bit)); // 0 bit to left partition
	}
};


// Most significant digit radix sort (recursive)
void msd_radix_sort(int* first, int* last, int msb = 31)
{
	if (first != last && msb >= 0)
	{
		int* mid = partition(first, last, radix_test(msb));
		msb--; // decrement most-significant-bit
		msd_radix_sort(first, mid, msb); // sort left partition
		msd_radix_sort(mid, last, msb); // sort right partition
	}
}


int main()
{
	int* a = new int[n]; //создание динамического массива
	for (int i = 0; i < n; i++)
		a[i] = rand() % 2001 - 1000; // заполнение массива
	cout << "BEFORE" << endl;
	print(a);
	unsigned int start_time = clock(); // начальное время
	msd_radix_sort(a, a + n);
	cout << "AFTER" << endl;
	print(a);
	cout << endl;
	unsigned int end_time = clock(); // конечное время
	unsigned int search_time = end_time - start_time; // время сортировки
	cout << endl << "Time: " << search_time << " ms" << endl;
	delete[] a;
	system("pause");
	return 0;
}


//вывод для отладки
void print(int* a) {
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
	cout << endl;
}

