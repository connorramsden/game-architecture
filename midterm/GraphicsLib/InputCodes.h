/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#ifndef INPUTCODES_H
#define INPUTCODES_H

#include <allegro5/keycodes.h>

enum KeyCode : int
{
	A = ALLEGRO_KEY_A,
	D = ALLEGRO_KEY_D,
	S = ALLEGRO_KEY_S,
	W = ALLEGRO_KEY_W,
	ESCAPE = ALLEGRO_KEY_ESCAPE,
	ENTER = ALLEGRO_KEY_ENTER,
	SPACEBAR = ALLEGRO_KEY_SPACE,
};

enum MouseCode : int
{
	LEFTBUTTON = 1,
	RIGHTBUTTON = 2,
};

#endif