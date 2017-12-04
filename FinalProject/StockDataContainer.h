#ifndef STOCK_DATA_CONTAINER_H
#define STOCK_DATA_CONTAINER_H
//
// Filename: StockDataContainer.h
//
// Author: Daniel Watkins
//
// Date: 12/03/2017
//
// Description: Definition of StockDataContainer object - represents a
//              collection of stock data by date
//
// CLASS PROVIDED: StockDataContainer
//
// CONSTRUCTOR:
//
//   StockDataContainer()
//	     Postcondition: The StockDataContainer is intitialized with default
//       values.
//
// METHODS:
//
//   void add(StockDateData stockDateData);
//       Precondition: stockDateData is a valied StockDateData object
//       Postcondition: adds stockDateData to the container.
//
//   void calculateTenDayMovingAverages();
//       Postcondition: calcluates the 10-day moving average for all the
//       stockDateData objects in the container.
//
//   void readFromStream(ifstream &inStream);
//       Precondition: inStream is a valid, open ifstream
//       Postcondition: reads StockDateData objects from a comma-delimited
//       text file and stores them in the container.
//
//   void writeToStream(ofstream &ofStream);
//       Precondition: ofStream is a valid, open ofstream
//       Postcondition: writs StockDateData objects to a comma-delimited
//       text file.
//
//   bool IsLastPriceGreaterThanMovingAverage();
//       Postcondition: returns whether the last adjusted price is greater than
//       the last 10-day moving average field for the StockDateData object
//

#include <string>
using namespace std;

class StockDataContainer {
private:
	string m_strLastDate;
	vector<StockDateData> m_stockData;
	bool m_bLastPriceGreaterThanMovingAverage;

public:
	StockDataContainer();
	void add(StockDateData stockDateData);
	void calculateTenDayMovingAverages();
	void readFromStream(ifstream &inStream);
	void writeToStream(ofstream &ofStream);
	bool IsLastPriceGreaterThanMovingAverage();
};

#endif

