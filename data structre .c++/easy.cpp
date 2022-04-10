// CPP program to remove punctuation from a given string

#include <iostream>
using namespace std;

int main()
{
	// input string
	std::string str = "Welcome???@@##$ to#$% my%$^new$%^&world";

	for (int i = 0, len = str.size(); i < len; i++)
	{
		// check whether parsing character is punctuation or not
		if (ispunct(str[i]))
		{
			str.erase(i--, 1);
			len = str.size();
		}
	}
	
	
	std::cout << str;
	return 0;
}

