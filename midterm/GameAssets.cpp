#include "GameAssets.h"


// Converts passed string to ASCII characters
int stringToASCII(std::string s)
{
	int sum = 0;

	for (int i = 0; i < (int)s.length(); i++)
	{
		sum += (int)s[i];
	}

	return sum;
}

// Uses ASCII characters to create an integer hash index
int basicHashFunction(std::string s)
{
	return stringToASCII(s) % HASH_MOD;
}