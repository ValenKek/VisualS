#include <iostream>
#include <string>


int main()
{
	std::string s1{ "example" };
	std::string s2{ "string functions" };
	std::cout << s1 << std::endl << s2 << std::endl << std::endl;

	if (!s1.empty() && !s2.empty())
	{
		while (size(s1) != size(s2))
		{
			if (size(s1) > size(s2))
			{
				s1.pop_back();
			}
			else
			{
				s2.pop_back();
			}
		}
	}
	std::cout << s1 << std::endl << s2 << std::endl;
}