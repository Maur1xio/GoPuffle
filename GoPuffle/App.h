#pragma once
#include "Helper.h"
#include "ScreenManager.h"
#include <conio.h>


//ConsoleKeyInfo myKey; PRUEBAS

class App {

	int width;
	int height;
	ScreenManager* screenManager;


public:

	App() {
		width = 211;
		height = 49;
		screenManager = new ScreenManager();
	}



	void configurations() {
		helper->changeWindowColor(126, 26, 187); // PRUEBA PARA VER SI EL METODO FUNCIONA, NO QUEDARÁ ASÍ
		helper->changeWindowSize(width, height);
		Console::CursorVisible = 0;
	}
	void start() {

		configurations();

		while (1){


			Screen* currentScreen = screenManager->getScreens()[screenManager->getCurrentScreen()];
			currentScreen->start();


			screenManager->checkChangeScreen(currentScreen->getScreenShowing());





			// PRUEBAS
			/*
			if (_kbhit()) {
				myKey = Console::ReadKey(true);
				if (myKey.Key == ConsoleKey::A) {
					currentScreen->setScreenShowing(DASHBOARD);
				}
				else if (myKey.Key == ConsoleKey::D) {
					currentScreen->setScreenShowing(AUTH);
				}
			}
			*/
		}

	}

	~App() {
		
	}



};