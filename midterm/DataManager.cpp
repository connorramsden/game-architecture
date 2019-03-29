/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#include "DataManager.h"

// C/C++ Usings
using std::cout;
using std::endl;

DataManager::DataManager()
{
	mDataStored = -1;

	return;
}

void DataManager::readData(string assetPath, string fileName)
{
	// Ensure that the data manager is re-set
	mDataStored = -1;
	mDataMap.clear();

	mFileReader.open(assetPath + fileName);

	if (mFileReader.is_open())
	{
		while (!mFileReader.eof())
		{
			mDataStored++;
			int temp;
			string dataValue;

			mFileReader >> temp >> dataValue;

			mDataMap[mDataStored] = dataValue;
		}

		// Close the opened data file
		mFileReader.close();
	}
	else
		cout << "Unable to open " << fileName << ". Please check your path & filename spelling." << endl;

	// clear the file reader after reading data in
	mFileReader.clear();
}

string DataManager::getFileName(int mapIndex)
{
	if (!mDataMap.empty())
		return mDataMap[mapIndex];
	else
		return "";
}