#include "GraphicsBufferManager.h"
#include <GraphicsBuffer.h>

GraphicsBufferManager::~GraphicsBufferManager()
{
	cleanupGraphicsBufferManager();

	return;
}

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

GraphicsBuffer * GraphicsBufferManager::createAndManageGraphicsBuffer(const GraphicsBufferKey & key)
{
	GraphicsBuffer *mpGraphicsBuffer = nullptr;

	GraphicsBufferMap::iterator iter = mGraphicsBufferMap.find(key);

	if (iter == mGraphicsBufferMap.end())
	{
		mpGraphicsBuffer = new GraphicsBuffer();

		mGraphicsBufferMap[key] = mpGraphicsBuffer;
	}

	return mpGraphicsBuffer;
}

void GraphicsBufferManager::deleteGraphicsBuffer(const GraphicsBufferKey & key)
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

void GraphicsBufferManager::deleteGraphicsBuffer(GraphicsBuffer * mpGraphicsBuffer)
{
	GraphicsBufferMap::iterator iter;

	for (iter = mGraphicsBufferMap.begin(); iter != mGraphicsBufferMap.end(); iter++)
	{
		if (mpGraphicsBuffer == iter->second)
		{
			delete mpGraphicsBuffer;

			mpGraphicsBuffer = nullptr;

			mGraphicsBufferMap.erase(iter);

			return;
		}
	}

	return;
}

GraphicsBuffer * GraphicsBufferManager::getGraphicsBuffer(const GraphicsBufferKey & key) const
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
