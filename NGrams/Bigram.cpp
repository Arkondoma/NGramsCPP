#include "Bigram.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>

void Bigram::update(int lang, string file)
{
	cout << "Opening " << file << "\n";
	ifstream target;
	target.open(file);
	if (target.is_open())
	{
		string line;
		while (getline(target, line))
		{
			line.erase(remove_if(line.begin(), line.end(), [](char c) { return !isalpha(c); }), line.end());
			for (int i = 1; i < line.length(); i++)
			{
				if (line[i] == '\0') break;
				else if (!isalpha(line[i])) continue;
				try
				{
					char c1, c2;
					c1 = tolower(line[i - 1]);
					c2 = tolower(line[i]);
					bigrams[lang][c1][c2]++;

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
				catch (exception& ex)
				{
					continue;
				}
			}
		}
	}
}

const void Bigram::evaluate(string file)
{
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

			cout << "Evaluating: " << text << "\n";
			text.erase(remove_if(text.begin(), text.end(), [](char c) { return !isalpha(c); }), text.end());

			for (int i = 1; i < text.length(); i++)
			{
				try 
				{
					char c1 = tolower(text[i - 1]);
					char c2 = tolower(text[i]);

					en_prob += log10(((double)bigrams[0][c1][c2] + 0.5) / (double)(en_total + 338));
					fr_prob += log10(((double)bigrams[1][c1][c2] + 0.5) / (double)(fr_total + 338));
					du_prob += log10(((double)bigrams[2][c1][c2] + 0.5) / (double)(du_total + 338));
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
