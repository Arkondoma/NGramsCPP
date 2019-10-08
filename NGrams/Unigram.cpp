#include "Unigram.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

// Read text and update character frequencies for each language
// Langs (0: Eng, 1: Fr, 2: Du)
void Unigram::update(int lang, string file)
{
	// Open file
	cout << "Opening " << file << "\n";
	ifstream target;
	target.open(file);

	if (target.is_open())
	{
		string line;
		while (getline(target, line))
		{
			// Remove non-alphabet characters from line
			line.erase(remove_if(line.begin(), line.end(), [](char c) { return !isalpha(c); }), line.end());
			for (auto &c : line)
			{
				// Make sure no weird characters got through
				if (c == '\0') break;
				else if (!isalpha(c)) continue;
				try
				{
					// Normalize character and update frequency
					c = tolower(c);
					unigrams[lang][c]++;

					// Update language tallies
					switch (lang)
					{
					case 0:
						en_total++;
						break;
					case 1:
						fr_total++;
						break;
					case 2:
						du_total++;
						break;
					default:
						cout << "Please submit a valid language value";
						return;
					}
				}
				catch (exception &ex)
				{
					continue;
				}
		    }
		}
	}
}

// Test sample phrases
const void Unigram::evaluate(string file)
{
	// Open file
	ifstream target;
	target.open(file);

	if (target.is_open())
	{
		string text;
		while (getline(target, text))
		{
			double en_prob = 0;
			double fr_prob = 0;
			double du_prob = 0;

			// Remove non-alphabet characters from line
			cout << "Evaluating: " << text << "\n";
			text.erase(remove_if(text.begin(), text.end(), [](char c) { return !isalpha(c); }), text.end());

			for (auto &c : text)
			{
				try 
				{
					// Normalize letters
					c = tolower(c);

					// Update probability for each lang, 0.5 and 13 (26/2) used for consistency
					en_prob += log10(((double)unigrams[0][c] + 0.5) / (double)(en_total + 13));
					fr_prob += log10(((double)unigrams[1][c] + 0.5) / (double)(fr_total + 13));
					du_prob += log10(((double)unigrams[2][c] + 0.5) / (double)(du_total + 13));
				}
				catch (exception& ex)
				{
					continue;
				}
			}

			cout << "English Probability: " << en_prob << "\n";
			cout << "French Probability:  " << fr_prob << "\n";
			cout << "Dutch Probability:   " << du_prob << "\n \n";
		}
	}
}

const void Unigram::print()
{
	for (int l = 0; l < 3; l++)
	{
		switch (l)
		{
		case 0:
			cout << "English \n";
		case 1:
			cout << "French \n";
		case 2:
			cout << "Dutch \n";
		}
		for (int i = 0; i < 26; i++)
		{
			cout << ALPHABET[i] << ": " << unigrams[l][ALPHABET[i]] << "\n";
		}
	}
}