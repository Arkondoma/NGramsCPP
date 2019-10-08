#include <iostream>
#include <array>
#include <map>
#include <string>

#define ALPHABET "abcdefghijklmnopqrstuvwxyz"

using namespace std;

class Unigram
{
	array< map<char, int>, 3 > unigrams;

	unsigned long int en_total = 0;
	unsigned long int fr_total = 0;
	unsigned long int du_total = 0;

public:

	// Initialize unigram maps
	Unigram()
	{
		for (int i = 0; i < 26; i++)
		{
			unigrams[0].insert(pair<char, int>(ALPHABET[i], 0));
			unigrams[1].insert(pair<char, int>(ALPHABET[i], 0));
			unigrams[2].insert(pair<char, int>(ALPHABET[i], 0));
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