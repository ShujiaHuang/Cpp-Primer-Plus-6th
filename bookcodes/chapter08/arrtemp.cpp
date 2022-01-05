// arrtemp.cpp -- using template functions with array template
#include <iostream>
#include <array>
#include <string>
template <class T, size_t n>
void display(const std::array<T, n> & ar);
int main()
{
	std::array<int, 5> ai = {1,2,3,4,5}; //,6,7,8,9,22};
	std::array<std::string, 5> as =
	{
		"string under construction",
		"stupid string indeed",
		"there's nothing to see",
		"nothing to do",
		"but enjoy all that is"
	};
	display(ai);
	display(as);
	// std::cin.get();
	return 0;
}
template <class T, size_t n>
void display(const std::array<T,  n> & ar)
{
	for (int i = 0; i < 5; i++)
		std::cout << ar[i] << std::endl;
}