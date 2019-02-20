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
	GraphicsBufferManager() { return; }
	~GraphicsBufferManager();

	void cleanupGraphicsBufferManager();

	GraphicsBuffer *createAndManageGraphicsBuffer(const GraphicsBufferKey &key);

	void deleteGraphicsBuffer(const GraphicsBufferKey &key);
	void deleteGraphicsBuffer(GraphicsBuffer *mpGraphicsBuffer);

	GraphicsBuffer *getGraphicsBuffer(const GraphicsBufferKey &key) const;

private:
	GraphicsBufferMap mGraphicsBufferMap;
};

#endif