#include <iostream>

void arrfill(double* parr,int n,int m)
{
	for (int i = 0; i < n * m; i++)
	{
		*parr = i;
		std::cout << *parr++ << '\t';
		if ((i + 1) % m == 0)
			std::cout << '\n';
	}
}
void funcsum(double arr[][8], int n, int m)
{
	double sum = 0;
	for (int j = 0; j < m; j++)
	{
			if (j <= ((m / 2)-1))
			{
				for (int i = 0; i <n; i++)
				{
					if (i >= (n-(j+1)))
					{
						sum += arr[j][i];
						
					}
				}
			}
			else
			{
				for (int i = 0; i < n; i++)
				{
					if (i > (n-(n - j)-1))
					{
						sum += arr[j][i];
					}
				}
			}
	}
	std::cout<<sum;
}

int main()
{
    const int n = 8, m = 8;
    double arr[n][m];
	double* parr = &arr[0][0];
	arrfill(parr,n,m);
    funcsum(arr, n,m);
}