#include "MouseEvent.h"

MouseEvent::MouseEvent(int mouseNum, MousepressType mpType, Vector2D mousePos)
	:Event(MOUSE_EVENT)
	,mMouseNum(mouseNum)
	,mMousepressType(mpType)
	,mMousePosition(mousePos)
{}

MouseEvent::~MouseEvent()
{}
