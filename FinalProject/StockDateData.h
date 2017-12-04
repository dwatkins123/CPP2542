#ifndef STOCK_DATE_DATA_H
#define STOCK_DATE_DATA_H

// Filename: StockDataData.h
//
// Author: Daniel Watkins
//
// Date: 12/03/2017
//
// Description: Definition of StockDateData object - represents stock data
//              for a date.
//
// CLASS PROVIDED: StockDateData
//
// CONSTRUCTORS:
//
//   StockDateData()
//	     Postcondition: The StockDateData is intitialized without a date
//       and with 0 values.
//
//   StockDateData(const StockDateData& sourceStockDateData)
//       Precondition: sourceStockDateData is a valid StockDateData object
//       Postcondition: The StockDateData that is being constructed has been
//       initialized with the same values as the source.
//
//   StockDateData(string strFileLine)
//       Precondition: strFileName is a comma delimited string containing all the 
//       values needed on the line
//       Postcondition: The StockDateData that is being constructed has been
//       initialized with the values from the string.
//
// ACCESSORS:
//
//   string GetDate() const;
//       Postcondition: returns the date field for the StockDateData object
//
//   string GetPrice(const int nPriceIdx) const;
//       Precondition: nPriceIdx is an integer between 0 and 4 inclusive.
//       Postcondition: returns the price field for the StockDateData object
//       at the nPriceIdx given
//
//   string GetVolume() const;
//       Postcondition: returns the volume field for the StockDateData object
//
//   string GetTenDayMovingAverage() const;
//       Postcondition: returns the ten day moving average field for the
//       StockDateData object
//
// MODIFIERS:
//
//   void SetDate(const char * cstrDate);
//       Precondition: A cstring cstrDate containing a date in YYYY-MM-DD format
//       Postcondition: The mstr_Date field is set to cstrDate
//
//   void SetPrice(const char *cstrPrice, const int nPos);
//       Precondition: A cstring cstrPrice containing a string representing a
//       decimal price, an int nPos between the values of 0 and 4 inclusive
//       Postcondition: The md_Prices value at index nPos is set to a double
//       representing the cstrPrice passed.
//
//   void SetPrice(const double dPrice, const int nPos);
//       Precondition: A double dPrice representing a
//       decimal price, an int nPos between the values of 0 and 4 inclusive
//       Postcondition: The md_Prices value at index nPos is set to a double
//       representing the dPrice passed.
//
//   void SetVolume(const char *cstrVolume);
//       Precondition: A cstring cstVolume representing an integer volume
//       Postcondition: The ml_Volume field is set to the integer represented
//       by cstrDate
//
//   void SetVolume(const long lVolume);
//       Precondition: A long lVolume representing an integer volume
//       Postcondition: The ml_Volume field is set to the integer represented
//       by lVolume
//
//   void SetTenDayMovingAverage(const double dTenDayMovingAverage);
//       Precondition: A double dTenDayMovingAverage representing a decimal
//       Ten Day Moving average
//       Postcondition: The md_TenDayMovingAverage field is set to the decimal
//       value represented by dTenDayMovingAverage
//
// OVERLOADED OPERATORS:
//
//   StockDateData & operator= (const StockDateData& sdData);
//       Precondition: sdData is a valid StockDateData object
//       Postcondition: returns a StockDateData object that is a copy of sdData
//
//   bool operator < (const StockDateData& sdData);
//       Precondition: sdData is a valid StockDateData object
//       Postcondition: returns true if the date from this object is
//       less than the date in sdData; false otherwise
//
//   bool operator > (const StockDateData& sdData);
//       Precondition: sdData is a valid StockDateData object
//       Postcondition: returns true if the date from this object is
//       greater than the date in sdData; false otherwise
//
//   bool operator == (const StockDateData& sdData);
//       Precondition: sdData is a valid StockDateData object
//       Postcondition: returns true if the date from this object is
//       equal to the date in sdData; false otherwise
//
//   double & operator[] (int i);
//       Postcondition: returns the price of index i from the this
//       StockDateData object.
//
// FRIEND FUNCTIONS:
//
//   ifstream& operator >> (ifstream& is, StockDateData& sdData);
//       Precondition: is is an open, valid ifstream, sdData is a valid StockDateData object
//       Postcondition: a line read from is is used to intialize sdData.
//
//   ofstream& operator << (ofstream& os, StockDateData& sdData);
//       Precondition: os is an open, valid ofstream, sdData is a valid StockDateData object
//       Postcondition: a line written to os with values from sdData.
//

#include <string>
using namespace std;

class StockDateData {
private:
	string mstr_Date;
	double md_Prices[5];
	long ml_Volume;
	double md_TenDayMovingAverage;

public:
	// CONSTRUCTORS:
	StockDateData();
	StockDateData(const StockDateData& sourceStockData);
	StockDateData(string strFileLine);

	// ACCESSORS:
	string GetDate() const;
	double GetPrice(const int nPriceIdx) const;
	long GetVolume() const;
	double GetTenDayMovingAverage() const;

	// MODIFIERS:
	void SetDate(const char * cstrDate);
	void SetPrice(const char *cstrPrice, const int nPos);
	void SetPrice(const double dPrice, const int nPos);
	void SetVolume(const char *cstrVolume);
	void SetVolume(const long lVolume);
	void SetTenDayMovingAverage(const double dTenDayMovingAverage);

    // OVERLOADED OPERATORS:
	StockDateData & operator= (const StockDateData& sdData);
	bool operator < (const StockDateData& sdData);
	bool operator > (const StockDateData& sdData);
	bool operator == (const StockDateData& sdData);
	double & operator[] (int i);

	// FRIEND FUNCTIONS:
	friend ifstream& operator >> (ifstream& is, StockDateData& sdData);
	friend ofstream& operator << (ofstream& os, StockDateData& sdData);
};

#endif
