#include <iostream>
#include <ctime>
int main()
{
    int n, m, k;
    std::cin >> n;
    std::cin >> m;
    std::cin >> k;
	int a, b, c;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
    if ((a >= 1 && a <= 1000) && (b >= 1 && b <= 1000) && (c >= 1 && c <= 1000)&&(n >= 1 && n <= 1000) && (m >= 1 && m <= 1000) && (k >= 1 && k <= 1000))
    {
       
        return 0;
    }
    else { return 1; }
}