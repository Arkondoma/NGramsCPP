#include "pch.h"
#include <iostream>
#include "Unigram.h"
#include "Bigram.h"

using namespace std;

int main()
{
	Unigram unigram;
	Bigram bigram;

	unigram.update(0, "C:/TRAINING/ENGLISH/en-moby-dick.txt");
	unigram.update(0, "C:/TRAINING/ENGLISH/en-the-little-prince.txt");

	unigram.update(1, "C:/TRAINING/FRENCH/fr-le-petit-prince.txt");
	unigram.update(1, "C:/TRAINING/FRENCH/fr-vingt-mille-lieues-sous-les-mers.txt");

	unigram.update(2, "C:/TRAINING/DUTCH/du-legend-en-de-heldhaftige.txt");
	unigram.update(2, "C:/TRAINING/DUTCH/du-sherlock-holmes.txt");

	bigram.update(0, "C:/TRAINING/ENGLISH/en-moby-dick.txt");
	bigram.update(0, "C:/TRAINING/ENGLISH/en-the-little-prince.txt");

	bigram.update(1, "C:/TRAINING/FRENCH/fr-le-petit-prince.txt");
	bigram.update(1, "C:/TRAINING/FRENCH/fr-vingt-mille-lieues-sous-les-mers.txt");

	bigram.update(2, "C:/TRAINING/DUTCH/du-legend-en-de-heldhaftige.txt");
	bigram.update(2, "C:/TRAINING/DUTCH/du-sherlock-holmes.txt");

	cout << "\n \n - UNIGRAM - \n";
	unigram.printTotals();
	unigram.evaluate("C:/TEST/test-sentences.txt");

	cout << "\n \n - BIGRAM - \n";
	bigram.printTotals();
	bigram.evaluate("C:/TEST/test-sentences.txt");
}