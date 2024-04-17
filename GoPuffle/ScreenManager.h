#pragma once
#include <string>
#include "AuthScreen.h"
#include "DashboardScreen.h"
#include <vector>

using namespace std;




class ScreenManager {

private:
	vector<Screen*> screens;
	int currentScreen;

public:
		
	ScreenManager() {
		Screen* authScreen = new AuthScreen();
		Screen* dashboardScreen = new DashboardScreen();



		screens.push_back(authScreen);
		screens.push_back(dashboardScreen);

		currentScreen = AUTH;
	}



	vector<Screen*> getScreens() {
		return screens;
	}

	int getCurrentScreen() {
		return currentScreen;
	}

	void changeCurrentScreen(int newScreen) {
		system("cls");
		screens[currentScreen]->setScreenShowing(screens[currentScreen]->getOriginalShowing());
		currentScreen = newScreen;

	}

	void checkChangeScreen(int query) {
		if (query != currentScreen) changeCurrentScreen(query);
	}




};