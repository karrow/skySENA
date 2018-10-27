

 # include "Arduino.h"
 # include "OpenL293D.h"




 # define AIN1 2    // pin 1 de dirección del Motor Izquierdo
 # define AIN2 3    // pin 2 de dirección del Motor Izquierdo
// # define PWMA 5    // pin PWM del Motor Izquierdo
 # define BIN1 5   // pin 1 de dirección del Motor Derecho
 # define BIN2 4   // pin 2 de dirección del Motor Derecho
// # define PWMB 6    // pin PWM del Motor Derecho

OpenL293D::OpenL293D(int TP) {

	pinMode(AIN1, OUTPUT);
	pinMode(AIN2, OUTPUT);
	//pinMode(PWMA, OUTPUT);
	pinMode(BIN1, OUTPUT);
	pinMode(BIN2, OUTPUT);
	//pinMode(PWMB, OUTPUT);
	
}

void OpenL293D::MotorIz(int value) {
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

void OpenL293D::MotorDe(int value) {
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

void OpenL293D::Motores(int left, int righ) {
	MotorIz(left);
	MotorDe(righ);
}

void OpenL293D::Frenos(boolean left, boolean righ, int value) {
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

void OpenL293D::ACTFrenoIz(int value) {


	analogWrite(AIN1, LOW);
	analogWrite(AIN2, LOW);
	//analogWrite(PWMA, value);

}

void OpenL293D::ACTFrenoDe(int value) {


	analogWrite(BIN1, LOW);
	analogWrite(BIN2, LOW);
	//analogWrite(PWMB, value);

}

void OpenL293D::PASFrenoIz(int value) {


	analogWrite(AIN1, value);
	analogWrite(AIN2, value);
	//analogWrite(PWMA, value);

}

void OpenL293D::PASFrenoDe(int value) {


	analogWrite(BIN1, value);
	analogWrite(BIN2, value);
	//analogWrite(PWMB, value);

}
