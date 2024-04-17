#pragma once
#include "Screen.h"

class AuthScreen : public Screen {


public: 
	AuthScreen() {
		originalShowing = AUTH;
		screenShowing = AUTH;
		data = "SOY LA VISTA DE AUTH"; // No quedará así, solo es un ejemplo para visualizar x informacion en la vista

	}

	void start() override {

		helper->goToXY(10, 10);
		cout << data << endl;
		

		helper->goToXY(10, 15);
		cout << "Presiona enter para irte al DAHSBOARD uwu";


		cin.get();

		//CON ESTE METODO, HACES QUE SE CAMBIE DE PANTALLA SEGUN EL PARAMETRO QUE LE PASES, Y LO PUEDES DONDE Y CUANDO QUIERAS
		setScreenShowing(DASHBOARD); // CON ESTE METODO, HACES QUE SE CAMBIE DE PANTALLA SEGUN EL PARAMETRO QUE LE PASES


	}




};