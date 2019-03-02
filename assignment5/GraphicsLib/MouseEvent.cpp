#include "MouseEvent.h"

MouseEvent::MouseEvent(MouseCode mouseCode, MousepressType mpType, Vector2D mousePos)
	:Event(MOUSE_EVENT)
	,mMouseCode(mouseCode)
	,mMousepressType(mpType)
	,mMousePosition(mousePos)
{}

MouseEvent::~MouseEvent()
{}
