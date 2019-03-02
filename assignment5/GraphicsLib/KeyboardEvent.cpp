#include "KeyboardEvent.h"

KeyboardEvent::KeyboardEvent(KeyCode keyCode, KeypressType kpType)
	:Event(KEYBOARD_EVENT)
	,mKeyCode(keyCode)
	,mKeypressType(kpType)
{}

KeyboardEvent::~KeyboardEvent()
{}