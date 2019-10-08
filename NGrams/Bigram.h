#include <iostream>
#include <array>
#include <map>
#include <string>

#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

using namespace std;

class Bigram
{
	array< map< char, map<char, int> >, 3 > bigrams;

	unsigned long int en_total = 0;
	unsigned long int fr_total = 0;
	unsigned long int du_total = 0;

public:

	// Initialize 2D bigram maps
	Bigram()
	{
		map <char, int> defaultmap;

		for (int i = 0; i < 26; i++)
		{
			defaultmap.insert(pair<char, int>(ALPHABET[i], 0));
		}
		for (int i = 0; i < 26; i++)
		{
			bigrams[0].insert(pair<char, map<char, int>>(ALPHABET[i], defaultmap));
			bigrams[1].insert(pair<char, map<char, int>>(ALPHABET[i], defaultmap));
			bigrams[2].insert(pair<char, map<char, int>>(ALPHABET[i], defaultmap));
		}
	}

	void update(int lang, string file);

	const void print();

	const void evaluate(string file);

	const void printTotals()
	{
		cout << "Total English values read = " << en_total << "\n";
		cout << "Total French values read =  " << fr_total << "\n";
		cout << "Total Dutch values read =   " << du_total << "\n";
	}
};