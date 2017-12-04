//
// Filename: Main.cpp
//
// Author: Daniel Watkins
//
// Date: 12/03/2017
//
// Description: Main program file for the stock reading and calculating
// application.
//
#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <direct.h>
#include "StockDateData.h"
#include "StockDataContainer.h"

using namespace std;

int main()
{
	// Get the current working directory:   
	char* buffer;

	buffer = _getcwd(NULL, 0);

	// Get the names file with the stock names
	ifstream ifileStocks;
	ifileStocks.open("data-files/names.csv");

	// Open an output file for the status results
	ofstream oStatsResults;
	oStatsResults.open("data-files/status.csv");

	string strStockName;

	while (getline(ifileStocks, strStockName)) {

		// Create a container for this stock
		StockDataContainer *myStockDataContainer = new StockDataContainer;

		ifstream ifileStock;

		ifileStock.open("data-files/" + strStockName + ".csv");
		// Get header line
		string strHeaderLine;

		getline(ifileStock, strHeaderLine);

		// Now call stock data container to read in file
		myStockDataContainer->readFromStream(ifileStock);
		ifileStock.close();

		// Calculate 10-day moving averages
		myStockDataContainer->calculateTenDayMovingAverages();

		// Write data to file w/10-day moving averages

		ofstream ofileStock;
		ofileStock.open("data-files/" + strStockName + "-final.csv");

		myStockDataContainer->writeToStream(ofileStock);

		ofileStock.close();

		// Now read second file for this stock
		ifileStock.open("data-files/" + strStockName + " (1).csv");
		getline(ifileStock, strHeaderLine);

		// Container method handles preventing overlap
		myStockDataContainer->readFromStream(ifileStock);

		ifileStock.close();

		// Re-calculate 10-day moving averages
		myStockDataContainer->calculateTenDayMovingAverages();

		ofileStock.open("data-files/" + strStockName + "-final.csv");

		// Write the data again with additional dates
		myStockDataContainer->writeToStream(ofileStock);

		ofileStock.close();

		// Write a line to status file
		oStatsResults << strStockName << ",";
		string strStatus = "NO";

		if (myStockDataContainer->IsLastPriceGreaterThanMovingAverage()) {
			strStatus = "YES";
		}

		oStatsResults << strStatus << "\n";

		delete myStockDataContainer;
	}

	oStatsResults.close();
}
