

 # ifndef OpenL293D_h
 # define OpenL293D_h
 # include "Arduino.h"

class OpenL293D{
	public:
	OpenL293D(int TP);

	void MotorIz(int value);
	void MotorDe(int value);
	void Motores(int left, int righ);
	void Frenos(boolean left, boolean righ, int value);
	void ACTFrenoIz(int value);
	void ACTFrenoDe(int value);
	void PASFrenoIz(int value);
	void PASFrenoDe(int value);
	private:

	long duration;
	long distance_cm;
};

# endif
