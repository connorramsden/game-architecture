#include "MouseEvent.h"

MouseEvent::MouseEvent(MouseCode mouseCode, Vector2D mousePos, EventInputState inputState)
	:Event(MOUSEINPUT_EVENT)
	,mMouseCode(mouseCode)
	,mMousePosition(mousePos)
	,mInputState(inputState)
{}

MouseEvent::~MouseEvent()
{}
