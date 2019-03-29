#ifndef MENUMANAGER_H
#define MENUMANAGER_H

// C/C++ Includes
#include <string>

// DeanLib Includes
#include <Trackable.h>

class MenuManager : public Trackable
{
	public:
	MenuManager();
	~MenuManager();

	void generateMenu();
	inline int getCurrentMenu() { return mCurrentMenu; }
	inline void setInMenu(bool newMenuStatus) { mInMenu = newMenuStatus; }

	private:
	int mCurrentMenu;
	bool mInMenu;
};

#endif