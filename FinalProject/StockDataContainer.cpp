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
#include <fstream>
#include <array>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include "StockDateData.h"
#include "StockDataContainer.h"

using namespace std;

StockDataContainer::StockDataContainer()
{
	m_strLastDate = "";
	m_bLastPriceGreaterThanMovingAverage = false;
}


void StockDataContainer::add(StockDateData stockDateData)
{
	m_stockData.push_back(stockDateData);
}

void StockDataContainer::readFromStream(ifstream &inStream)
{
	string strStockDataLine;

	while (getline(inStream, strStockDataLine)) {
		StockDateData *dateData = new StockDateData(strStockDataLine);

		// Avoid overlapping data
		if (dateData->GetDate() > m_strLastDate) {
			add(*dateData);
			m_strLastDate = dateData->GetDate();
		}

		delete dateData;
	}
}

void StockDataContainer::calculateTenDayMovingAverages()
{
	int nInQueue = 0; // Track number in queue
	double dCurrentTotal = 0.0;
	queue<StockDateData> dateDataQueue; // Queue to calculate averages

	for (vector<StockDateData>::iterator it = m_stockData.begin(); it != m_stockData.end(); ++it) {
		if (nInQueue < 10) { // Queue not full, can't calculate average 
			dCurrentTotal += it->GetPrice(4);  // Adjusted price
			dateDataQueue.push(*it);
			nInQueue++;

			if (nInQueue == 10) {
				it->SetTenDayMovingAverage(dCurrentTotal / 10.0);
				m_bLastPriceGreaterThanMovingAverage = (it->GetPrice(4) > it->GetTenDayMovingAverage());
			}
			else {
				it->SetTenDayMovingAverage(-1.0);
			}
		}
		else {
			// Remove oldest from queue and add this one.  Adjust total and calculate average for this one
			// Subtract oldest adj price from total
			dCurrentTotal -= dateDataQueue.front().GetPrice(4);

			// Add this one's adjusted price to total
			dCurrentTotal += it->GetPrice(4);
			it->SetTenDayMovingAverage(dCurrentTotal / 10.0);
			m_bLastPriceGreaterThanMovingAverage = (it->GetPrice(4) > it->GetTenDayMovingAverage());

			dateDataQueue.pop();
			dateDataQueue.push(*it);
		}
	}
}

void StockDataContainer::writeToStream(ofstream &outStream)
{
	// Print headers
	outStream << "Date, Open, High, Low, Close, Adj Close, Volume, 10-day Moving Average\n";

	for (vector<StockDateData>::iterator it = m_stockData.begin(); it != m_stockData.end(); ++it) {
		outStream << (*it);
	}
}

bool StockDataContainer::IsLastPriceGreaterThanMovingAverage()
{
	return m_bLastPriceGreaterThanMovingAverage;
}
