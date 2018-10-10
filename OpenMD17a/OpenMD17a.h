

 # ifndef OpenMD17a_h
 # define OpenMD17a_h
 # include "Arduino.h"

class OpenMD17a{
	public:
	OpenMD17a(int TP);

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
