#include "MenuManager.h"
#include "Game.h"
#include "GraphicsBufferManager.h"
#include "DataManager.h"

using std::cout;
using std::endl;

MenuManager::MenuManager()
{
	mCurrentMenu = 0;
	mInMenu = true;

	return;
}

MenuManager::~MenuManager()
{
	return;
}

void MenuManager::generateMenu()
{
	// HACK: Hardcoding some asset management for speedily creating this system
	Game* pGameInstance = Game::getGameInstance();
	System* pSystemInstance = pGameInstance->getSystemInstance();
	GraphicsSystem* pGraphicsSystemInstance = pSystemInstance->getGraphicsSystem();
	DataManager* pDataManagerInstance = pGameInstance->getDataManager();

	pDataManagerInstance->readData("assets/", "menudata.txt");

	Font drawFont("assets/", pDataManagerInstance->
		getFileName(pDataManagerInstance->getDataStored()), 32);

	float centerX = pSystemInstance->getCenterScreen().getX();
	float centerY = pSystemInstance->getCenterScreen().getY();

	while (mInMenu)
	{
		pSystemInstance->getInputSystem()->updateInputSystem();

		pGraphicsSystemInstance->
			setBufferColor(pSystemInstance->
				getGraphicsSystem()->
				getBackBuffer(), Color(125, 0, 125));

		pGraphicsSystemInstance->
			writeText(centerX, centerY - 125, drawFont, Color(), "Welcome to Snake!", 1);

		pGraphicsSystemInstance->
			writeText(pSystemInstance->
				getCenterScreen(), drawFont, Color(), "Press Spacebar to Start!", 1);

		pGraphicsSystemInstance->updateDisplay();
	}

	return;
}