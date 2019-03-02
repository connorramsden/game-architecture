#include "KeyboardEvent.h"

KeyboardEvent::KeyboardEvent(int keyNum, KeypressType kpType)
	:Event(KEYBOARD_EVENT)
	,mKeyNum(keyNum)
	,mKeypressType(kpType)
{}

KeyboardEvent::~KeyboardEvent()
{}