#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <direct.h>


using namespace std;

class StockDateData {
private:
	string mstr_Date;
	double md_Prices[5];
	long ml_Volume;
	double md_TenDayMovingAverage;

public:
	void SetDate(char * cstrDate) {
		mstr_Date = cstrDate;
	}

	void SetPrice(char *cstrPrice, int nPos) {
		md_Prices[nPos] = strtod(cstrPrice, NULL);
	}

	void setVolume(char *cstrVolume) {
		ml_Volume = strtol(cstrVolume, NULL, 10);
	}
};

class StockDataContainer {
private:
	vector<StockDateData> ticker;

public:
	void add(StockDateData stockData) {
		ticker.push_back(stockData);
	}

	void calculateTenDayMovingAverage() {
	}
};

int main()
{
	StockDataContainer *myStockDataContainer = new StockDataContainer;

	// Get the current working directory:   
	char* buffer;

	buffer = _getcwd(NULL, 0);

	ifstream ifileStocks;
	ifileStocks.open("data-files/names.csv");

	string strStockName;

	while (getline(ifileStocks, strStockName)) {
		ifstream ifileStock;

		ifileStock.open("data-files/" + strStockName + ".csv");

		string strStockDataLine;

		bool bFirstLine = true;

		while (getline(ifileStock, strStockDataLine)) {

			if (bFirstLine) {
				bFirstLine = false;
				continue;
			}
			StockDateData *myStockData = new StockDateData;
			char *next_token1 = NULL;

			char * cstrStockDataLine = (char *)strStockDataLine.c_str();
			myStockData->SetDate(strtok_s(cstrStockDataLine, ",", &next_token1));

			// Do the 5 doubles
			for (int i = 0; i < 5; i++) {
				myStockData->SetPrice(strtok_s(NULL, ",", &next_token1), i);

			}

			// Do the volume as a long
			myStockData->setVolume(strtok_s(NULL, ",", &next_token1));

			myStockDataContainer->add(*myStockData);
		}

		ifileStock.close();

		ofstream ofileStock;

		ofileStock.open("data-files/" + strStockName + ".csv");


	}
}
