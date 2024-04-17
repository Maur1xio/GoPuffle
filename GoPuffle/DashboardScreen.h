#pragma once
#include "Screen.h"

class DashboardScreen : public Screen {

public:
	DashboardScreen() {
		originalShowing = DASHBOARD;
		screenShowing = DASHBOARD;
		data = "SOY LA VISTA DEL DASHBOARD"; // No quedará así, solo es un ejemplo para visualizar x informacion en la vista
	}

	void start() override {
		helper->goToXY(10, 10);
		cout << data << endl;

		helper->goToXY(10, 12);
		cout << "Presiona enter para irte al AUTH uwu";

		cin.get();



		//CON ESTE METODO, HACES QUE SE CAMBIE DE PANTALLA SEGUN EL PARAMETRO QUE LE PASES, Y LO PUEDES DONDE Y CUANDO QUIERAS
		setScreenShowing(AUTH); 

	}


}; 
