/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#include "GraphicsBufferManager.h"
#include <GraphicsBuffer.h>

// Default GraphicsBufferManager Deconstructor
GraphicsBufferManager::~GraphicsBufferManager()
{
	cleanupGraphicsBufferManager();

	return;
}

// Loops through mGraphicsBufferMap and deletes all GraphicsBuffer(s)
void GraphicsBufferManager::cleanupGraphicsBufferManager()
{
	GraphicsBufferMap::iterator iter;

	for (iter = mGraphicsBufferMap.begin(); iter != mGraphicsBufferMap.end(); ++iter)
	{
		GraphicsBuffer *mpGraphicsBuffer = iter->second;

		delete mpGraphicsBuffer;

		mpGraphicsBuffer = nullptr;
	}

	mGraphicsBufferMap.clear();

	return;
}

// Creates and updates a new GraphicsBuffer into mGraphicsBufferMap
GraphicsBuffer * GraphicsBufferManager::createAndManageGraphicsBuffer(const GraphicsBufferKey key, std::string assetPath, std::string fileName)
{
	GraphicsBuffer *pGraphicsBuffer = nullptr;

	GraphicsBufferMap::iterator iter = mGraphicsBufferMap.find(key);

	if (iter == mGraphicsBufferMap.end())
	{
		pGraphicsBuffer = new GraphicsBuffer(assetPath, fileName);

		mGraphicsBufferMap[key] = pGraphicsBuffer;
	}

	return pGraphicsBuffer;
}

// Delete the GraphicsBuffer in mGraphicsBufferMap at &key
void GraphicsBufferManager::deleteGraphicsBuffer(const GraphicsBufferKey key)
{
	GraphicsBufferMap::iterator iter = mGraphicsBufferMap.find(key);

	if (iter != mGraphicsBufferMap.end())
	{
		delete iter->second;

		iter->second = nullptr;

		mGraphicsBufferMap.erase(iter);

		return;
	}

	return;
}

// Delete the GraphicsBuffer passed into the function
void GraphicsBufferManager::deleteGraphicsBuffer(GraphicsBuffer * pGraphicsBuffer)
{
	GraphicsBufferMap::iterator iter;

	for (iter = mGraphicsBufferMap.begin(); iter != mGraphicsBufferMap.end(); iter++)
	{
		if (pGraphicsBuffer == iter->second)
		{
			delete pGraphicsBuffer;

			pGraphicsBuffer = nullptr;

			mGraphicsBufferMap.erase(iter);

			return;
		}
	}

	return;
}

// Return the GraphicsBuffer in mGraphicsBufferMap at &key
GraphicsBuffer * GraphicsBufferManager::getGraphicsBuffer(const GraphicsBufferKey key) const
{
	GraphicsBufferMap::const_iterator iter = mGraphicsBufferMap.find(key);

	if (iter != mGraphicsBufferMap.end())
	{
		return iter->second;
	}
	else
	{
		return nullptr;
	}
}
