#ifndef skySENA_H
#define skySENA_H
#include <Arduino.h>

/*
	LIBRERIA skySENA V0.1
	Desarrollado por Skybots y tdrobotica y modificada Por Jonathan Gonzalez, para controlar los circuitos y robots de forma simple
	y didactica, contiene una serie de funciones que facilitan el funcionamiento de los circuitos
	la librería va combinada con los ejemplos de Arduino.
	FUNCIONES
	#############
		* Control del Dirver de Motores.
		* Lectura del botón.
		* Lectura del estado de la bateria (En los que esta disponible).
		* Lectura del sensor de linea (En los que esta disponible).
		* Control PID
	#############

*/


class sky{
public:
	//Variables de los sensores.
	int ns, s1, s2, s3, s4, s5, s6, s7, s8, LEDon;
	//Variables de los valores de los sensores
	int line1,line2,line3, line4, line5, line6, line7, line8;
	//Los diferentes circuitos que puedes controlar con esta edicion de la libreria.
	int wizard= 0, linebot= 0, skyDragon= 0;
	//
	float linePos, battery;
	sky();
	void Speeds(int SpeedMA, int SpeedMB);//Velocidades de -255 a 255
	//Selecciona la board que esta utilizando.
	void Wizard();
	void Linebot();
	//void SkyDragon();
	//Permite concer el estado de las variables mas importantes linea, bateria etc...
	float LinePosDigital();
	float Battery();
	short Boton();
	//Configura el sensor de linea
	void LineConfig(int _ns, int _s1, int _s2, int _s3, int _s4, int _s5, int _s6, int _s7, int _s8, int _LEDon);



	//**********************************
	long LineaNegra();
	long LineaBlanca();
	void funcionCruce();
	void vel();
	int controlador();
	void comunicacion();
	void PID_Sky(float kp, float kd, float ki);
	long PID(int POS, int setpoint, int base);

	int change();

private:
	int velocid;
	int a;
	int POS;
	int setpoint;
	int base;
	float kp;
	float kd;
	float ki;
	long _PasosIz;
	long _PasosDe;
	int setv;
	int Pow;
};
#endif
