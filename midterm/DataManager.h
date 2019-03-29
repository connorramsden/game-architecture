/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#ifndef DATAMANAGER_H
#define DATAMANAGER_H

// C/C++ Includes
#include <iostream>
#include <string>
#include <fstream>
#include <map>

// C/C++ Usings
using std::string;
using std::ifstream;
using std::map;

typedef map<int, string> DataMap;

// DeanLib Includes
#include <Trackable.h>

class DataManager : public Trackable
{
	public:
	DataManager();
	~DataManager() { return; }

	void readData(string assetPath, string fileName);
	string getFileName(int mapIndex);
	inline int getDataStored() { return mDataStored; }

	private:
	int mDataStored;
	ifstream mFileReader;
	DataMap mDataMap;
};

#endif