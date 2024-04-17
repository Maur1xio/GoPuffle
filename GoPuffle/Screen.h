#pragma once
#include <string>
#include "Helper.h"

enum { AUTH, DASHBOARD };

using namespace std;

class Screen {

protected:
	int screenShowing;
	int originalShowing;
	string data;

public:

	virtual void start() = 0;

	int getScreenShowing() {
		return screenShowing;
	}
	int getOriginalShowing() {
		return originalShowing;
	}


	void setScreenShowing(int newScreen) {
		screenShowing = newScreen;
	}


};