#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int ARRAY_SIZE = 10000;

void main()
{
	// open a file in write mode.
	ofstream outfile;
	outfile.open("c:\\users\\cod_user\\MyData.txt");

	srand(time(NULL));

	int nRandomNumber = -1;

	do {
		nRandomNumber = rand() % 100;
		outfile << nRandomNumber << "\n";
	} while (nRandomNumber != 0);

	outfile.close();

	// open a file in read mode.
	ifstream infile;
	infile.open("c:\\users\\cod_user\\MyData.txt");

	string strReadLine;
	int nReadInt;
	int nCounter = 0;

	array<int, ARRAY_SIZE> nArray;
	vector<int> nVector;

	while (getline(infile, strReadLine)) {
		nReadInt = stoi(strReadLine);
		nArray[nCounter] = nReadInt;
		nVector.push_back(nReadInt);
		nCounter++;

		if (nCounter >= ARRAY_SIZE) {
			cout << "Array maxed out, stopping\n";
			break;
		}
	}

	infile.close();

	array<int, ARRAY_SIZE>::const_iterator arrIterator;
	vector<int>::const_iterator vectIterator;

	int nNewCounter = 0;

	// Array iterator
	cout << "Array iteration: \n";
	arrIterator = nArray.begin();

	while ((arrIterator != nArray.cend()) && (nNewCounter < nCounter)) {
		cout << *arrIterator++ << "\n";
		nNewCounter++;
	}

	cout << "Vector iteration: \n";

	vectIterator = nVector.begin();

	while (vectIterator != nVector.cend()) {
		cout << *vectIterator++ << "\n";
	}

	system("pause");
	exit;
}
