#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
int inverse(int a, int b)
{
	int inv = -1;
	int q, r, r1 = a, r2 = b, t, t1 = 0, t2 = 1;

	while (r2 > 0)
	{
		q = r1 / r2;
		r = r1 - q * r2;
		r1 = r2;
		r2 = r;

		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}

	if (r1 == 1)
		inv = t1;

	if (inv < 0)
		inv = inv + a;

	return inv;
}

int gcd(int a, int b)
{
	int q, r;
	while (b > 0)
	{
		q = a / b;
		r = a - q * b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int a, b, d, m, a1, b1, m1, x0;
	char ch;
	int inv;

	while (!feof(stdin))
	{
		std::cout << "The given equation is ax = b(mod m)" << std::endl;
		std::cout << "Enter a:";
		std::cin>>a;
		std::cout << "Enter b:";
		std::cin >>b;
		std::cout << "Enter m:";
		std::cin >> m;
		std::cout << a << "x=" << b << "(mod " << m << ")" << std::endl << std::endl;
		if (b < 0)
		{
			b = b + m;
		}

		std::cout << "Reduced Equation:"<<a<<"x="<<b<<"(mod "<<m<<")" << std::endl;
		d = gcd(a, m);

		std::cout << "GCD(" << a << "," << m << ")=" << d << std::endl;

		if ((m % b == 0) || (d % b == 0))
		{
			std::cout << "The given equation has No solution."<< std::endl<< "------------------------------------------------------------" << std::endl << std::endl;
			continue;
		}

		a1 = a / d;
		b1 = b / d;
		m1 = m / d;

		std::cout << "Reduced Equation:"<<a1<<"x="<<b1<<"(mod "<<m1<<")" << std::endl;

		inv = inverse(m1, a1);
		std::cout << "inv(" << a1 << ") = " << inv << std::endl;;

		x0 = (b1 * inv) % m1;
		std::cout << "General Solution: x = "<<x0<<" + "<<m1<<"k where k is any integer" << std::endl << "------------------------------------------------------------" << std::endl << std::endl;
	}
	
	return 0;
}