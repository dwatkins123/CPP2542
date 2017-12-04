// Filename: StockDateData.cpp
//
// Author: Daniel Watkins
//
// Date: 12/03/2017
//
// Description: Implementation of StockDateData object - represents a single
//              stock's data on a specific date.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "StockDateData.h"

using namespace std;

// CONSTRUCTORS;

StockDateData::StockDateData()
// Default Constructor
{
	mstr_Date = "";

	for (int i = 0; i < 5; i++) {
		md_Prices[i] = 0.0;
	}

	ml_Volume = 0L;
	md_TenDayMovingAverage = -1.0;
}

StockDateData::StockDateData(const StockDateData& sourceStockData) 
// Copy Constructor
{
	mstr_Date = sourceStockData.GetDate();

	for (int i = 0; i < 5; i++) {
		md_Prices[i] = sourceStockData.GetPrice(i);
	}

	ml_Volume = sourceStockData.GetVolume();
	md_TenDayMovingAverage = sourceStockData.GetTenDayMovingAverage();
}

StockDateData::StockDateData(string strFileLine)
{
	// Create from a line of text
	char *next_token1 = NULL;

	char * cstrStockDataLine = (char *)strFileLine.c_str();
	mstr_Date = strtok_s(cstrStockDataLine, ",", &next_token1);

	// Do the 5 doubles
	for (int i = 0; i < 5; i++) {
		SetPrice(strtok_s(NULL, ",", &next_token1), i);
	}

	// Do the volume as a long
	SetVolume(strtok_s(NULL, ",", &next_token1));
	md_TenDayMovingAverage = -1;
}

// ACCESSORS

string StockDateData::GetDate() const
{
	return mstr_Date;
}

double StockDateData::GetPrice(const int nPriceIdx) const
{
	return md_Prices[nPriceIdx];
}

long StockDateData::GetVolume() const
{
	return ml_Volume;
}

double StockDateData::GetTenDayMovingAverage() const
{
	return md_TenDayMovingAverage;
}

// MODIFIERS

void StockDateData::SetDate(const char * cstrDate)
{
	mstr_Date = cstrDate;
}

void StockDateData::SetPrice(const char *cstrPrice, const int nPos)
{
	md_Prices[nPos] = strtod(cstrPrice, NULL);
}

void StockDateData::SetPrice(const double dPrice, const int nPos)
{
	md_Prices[nPos] = dPrice;
}

void StockDateData::SetVolume(const char *cstrVolume)
{
	ml_Volume = strtol(cstrVolume, NULL, 10);
}

void StockDateData::SetVolume(const long lVolume)
{
	ml_Volume = lVolume;
}

void StockDateData::SetTenDayMovingAverage(const double dTenDayMovingAverage)
{
	md_TenDayMovingAverage = dTenDayMovingAverage;
}

// OVERLOADED OPERATORS:

StockDateData & StockDateData::operator=(const StockDateData& sdData)
{
	mstr_Date = sdData.GetDate();

	for (int i = 0; i < 5; i++) {
		md_Prices[i] = sdData.GetPrice(i);
	}

	ml_Volume = sdData.GetVolume();
	md_TenDayMovingAverage = sdData.GetTenDayMovingAverage();

	return *this;
}

bool StockDateData::operator <(const StockDateData& sdData)
{
	return mstr_Date < sdData.GetDate();
}

bool StockDateData::operator >(const StockDateData& sdData)
{
	return mstr_Date > sdData.GetDate();
}

bool StockDateData::operator ==(const StockDateData& sdData)
{
	return mstr_Date > sdData.GetDate();
}

double & StockDateData::operator[] (int i)
{
	return md_Prices[i];
}

ifstream& operator >> (ifstream& is, StockDateData& sdData)
{
	string strStockDataLine;

	if (getline(is, strStockDataLine)) {
		char *next_token1 = NULL;

		char * cstrStockDataLine = (char *)strStockDataLine.c_str();
		sdData.SetDate(strtok_s(cstrStockDataLine, ",", &next_token1));

		// Do the 5 doubles
		for (int i = 0; i < 5; i++) {
			sdData.SetPrice(strtok_s(NULL, ",", &next_token1), i);
		}

		// Do the volume as a long
		sdData.SetVolume(strtok_s(NULL, ",", &next_token1));
	}

	return is;
}

ofstream& operator << (ofstream& os, StockDateData& sdData)
{
	os << sdData.GetDate() << ",";
	
	for (int i = 0; i < 5; i++) {
		os << fixed << setprecision(6) << sdData.GetPrice(i) << ",";
	}

	os << sdData.GetVolume() << ",";
	
	if (sdData.GetTenDayMovingAverage() == -1.0) {
		os << "n/a\n";
	}
	else {
		os << fixed << setprecision(6) << sdData.GetTenDayMovingAverage() << "\n";
	}

	return os;
}
