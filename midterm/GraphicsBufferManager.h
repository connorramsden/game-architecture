/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#ifndef GRAPHICSBUFFERMANAGER_H
#define GRAPHICSBUFFERMANAGER_H

// C/C++ Includes
#include <string>
#include <map>

// DeanLib Includes
#include <Trackable.h>

class GraphicsBuffer;

typedef int GraphicsBufferKey;

typedef std::map<GraphicsBufferKey, GraphicsBuffer*> GraphicsBufferMap;

class GraphicsBufferManager : public Trackable
{
public:
	// Default GraphicsBufferManager Constructor
	GraphicsBufferManager() { return; }

	// Default GraphicsBufferManager Deconstructor
	~GraphicsBufferManager();

	// Loops through mGraphicsBufferMap and deletes all GraphicsBuffer(s)
	void cleanupGraphicsBufferManager();

	// Creates and updates a new GraphicsBuffer into mGraphicsBufferMap
	GraphicsBuffer *createAndManageGraphicsBuffer(const GraphicsBufferKey key, std::string assetPath, std::string fileName);

	// Delete the GraphicsBuffer in mGraphicsBufferMap at &key
	void deleteGraphicsBuffer(const GraphicsBufferKey key);

	// Delete the GraphicsBuffer passed into the function
	void deleteGraphicsBuffer(GraphicsBuffer *mpGraphicsBuffer);

	// Return the GraphicsBuffer in mGraphicsBufferMap at &key
	GraphicsBuffer *getGraphicsBuffer(const GraphicsBufferKey key) const;

private:
	// An STL map storing GraphicsBufferKey(s) and GraphicsBuffer(s)
	GraphicsBufferMap mGraphicsBufferMap;
};

#endif