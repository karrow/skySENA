#include <OpenMD17a.h>
#include <OpenLamborghino.h>

#define BOTON  12


int setpoint = 0;
int gyroSpeed = 230;
int base = 55;

//para el conteo del tiempo de muestreo.
float start,finish;
float Ts = 5000.0;

float Kprop = 0.9;
float Kderiv = 2.5;
float Kinte = 0.0;

OpenLamborghino OpenLamborghino(BOTON);
OpenMD17a OpenMD17a(0);

void setup() {
  Serial.begin(9600);
   TCCR1A = 0x81; // seleccion del contador. 
   TCCR1B = 0x01; // prescaler = 1.
   OCR1A = 255;   // tope de la señal o maximo pwm 
   TIMSK1 = 0;      //des habilita cualquier interrupcion que 

  
  OpenLamborghino.WaitBoton();
  OpenLamborghino.calibracion();
  OpenLamborghino.WaitBoton();
  delay(1000);
  OpenLamborghino.PIDLambo(Kprop, Kderiv, Kinte);
}
void loop() {

  start = micros();
  int pos =  OpenLamborghino.LineaNegra();
  int Power = OpenLamborghino.PID(pos, setpoint, gyroSpeed);
  OpenMD17a.Motores(base - Power, base + Power );

  finish = micros() - start;
  while(Ts>finish)
  {
    finish = micros() - start; 
  }

}

