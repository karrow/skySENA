#include <skySENA.h>
sky Robot;

int T_MUERTO;
int P_MUERTO;
int pos=0;
long tiempo=0,tiempo_anterior=0; 
int pos_ant;
float Tangente=0; 
void setup() {
  Serial.begin(9600);
  Robot.Linebot();
  Robot.LineConfig(8, 18, 19, 15, 16, 9, 8, 7, 4, 14);

  Serial.println("hola estoy listo");
  
  while(Robot.Boton()){}
  delay(2000);
}

void loop() {
  pos=Robot.LineaNegra();
  pos_ant=pos;
  tiempo = millis();
  Robot.Speeds(45,0);
  delay(200);
  Robot.Speeds(0,0);
  tiempo_anterior = tiempo;
  pos=Robot.LineaNegra();
  long millisANT;
  Serial.print("Pos Anterior: ");Serial.print(pos_ant); Serial.print(" Tiempo Anterior: ");Serial.print(tiempo_anterior); 
  Serial.print(" Pos Actual: ");Serial.print(pos); Serial.print(" Tiempo Actual: ");Serial.println(tiempo);

   T_MUERTO=tiempo-tiempo_anterior;
   P_MUERTO=pos-pos_ant;
   Tangente=P_MUERTO/T_MUERTO;
   Serial.print("T_MUERTO: ");Serial.println(T_MUERTO);
   Serial.print("P_MUERTO: ");Serial.println(P_MUERTO);
   Serial.print("Tangente: ");Serial.println(Tangente);

