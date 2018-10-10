

 # include "Arduino.h"
 # include "OpenMD17a.h"




 # define AIN1 6    // pin 1 de dirección del Motor Izquierdo
 # define AIN2 5    // pin 2 de dirección del Motor Izquierdo
// # define PWMA 5    // pin PWM del Motor Izquierdo
 # define BIN1 11   // pin 1 de dirección del Motor Derecho
 # define BIN2 10   // pin 2 de dirección del Motor Derecho
// # define PWMB 6    // pin PWM del Motor Derecho

OpenMD17a::OpenMD17a(int TP) {

	pinMode(AIN1, OUTPUT);
	pinMode(AIN2, OUTPUT);
	//pinMode(PWMA, OUTPUT);
	pinMode(BIN1, OUTPUT);
	pinMode(BIN2, OUTPUT);
	//pinMode(PWMB, OUTPUT);
	
}

void OpenMD17a::MotorIz(int value) {
	if (value >= 0) {
		// si valor positivo vamos hacia adelante

		analogWrite(AIN1, value);
		analogWrite(AIN2, LOW);
	} else {
		// si valor negativo vamos hacia atras

		analogWrite(AIN1, LOW);
		analogWrite(AIN2, value*-1);
		//value *= -1;
	}

	// Setea Velocidad

	///analogWrite(PWMA, value);
}

void OpenMD17a::MotorDe(int value) {
	if (value >= 0) {
		// si valor positivo vamos hacia adelante

		analogWrite(BIN1, value);
		analogWrite(BIN2, LOW);
	} else {
		// si valor negativo vamos hacia atras

		analogWrite(BIN1, LOW);
		analogWrite(BIN2, -1*value);
	}

	// Setea Velocidad

	//analogWrite(PWMB, value);
}

void OpenMD17a::Motores(int left, int righ) {
	MotorIz(left);
	MotorDe(righ);
}

void OpenMD17a::Frenos(boolean left, boolean righ, int value) {
	// pin STAND BY


	if (left) {
		// pines LEFT motor

		analogWrite(AIN1, HIGH);
		analogWrite(AIN2, HIGH);
		//analogWrite(PWMA, value);
	}

	if (righ) {
		// pines RIGH motor

		analogWrite(BIN1, HIGH);
		analogWrite(BIN2, HIGH);
		//analogWrite(PWMB, value);
	}
}

void OpenMD17a::ACTFrenoIz(int value) {


	analogWrite(AIN1, LOW);
	analogWrite(AIN2, LOW);
	//analogWrite(PWMA, value);

}

void OpenMD17a::ACTFrenoDe(int value) {


	analogWrite(BIN1, LOW);
	analogWrite(BIN2, LOW);
	//analogWrite(PWMB, value);

}

void OpenMD17a::PASFrenoIz(int value) {


	analogWrite(AIN1, value);
	analogWrite(AIN2, value);
	//analogWrite(PWMA, value);

}

void OpenMD17a::PASFrenoDe(int value) {


	analogWrite(BIN1, value);
	analogWrite(BIN2, value);
	//analogWrite(PWMB, value);

}
