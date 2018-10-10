#include <skySENA.h>


sky Robot;


void setup() {
  Serial.begin(9600);
  Robot.Linebot();
  Robot.LineConfig(8, 18, 19, 15, 16, 9, 8, 7, 4, 14);

  Serial.println("hola estoy listo");
  
  while(Robot.Boton()){}
  delay(2000);

}

float pos;
float proporcional,derivativo, integral, setPoint= 50;
float porporcional_past = 0.0;
float kp=1.80,kd=1.00, ki=0.00000017;
short pid = 0, out = 0, velocidad = 45;
short vmi=0, vmd=0;
void loop() {
  //Serialin();
  pos = Robot.LineaNegra();
  out=pid3(pos,120);

  vmi = (velocidad+out);
  vmd = (velocidad-out);
  Serial.print(millis()); Serial.print("\tPos: "); Serial.print(pos);Serial.print("\tSp: "); Serial.print(setPoint); Serial.print("\tPID: "); Serial.print(out); Serial.print("\tvmi: "); Serial.print(vmi); Serial.print("\tvmd: "); Serial.println(vmd);
  Robot.Speeds(vmd,vmi);

  
  porporcional_past = proporcional;
}


short pid3(float positi, int lim){
  proporcional = positi - setPoint;
  integral = porporcional_past + integral;
  derivativo = proporcional - porporcional_past;

  pid = int(proporcional*kp + derivativo*kd + integral*ki);
  if(pid>lim || pid < -lim){
    if(pid < -lim){
      pid= -120;
    }
    pid =120;
  }
  return pid;
}

void Serialin() {

  if (Serial.available() > 0) {
    Robot.Speeds(0,0);
    
    //velMax = Serial.parseInt();
    kp = Serial.parseFloat();// 10.0; 
    kd = Serial.parseFloat();// 10.0;
    ki = Serial.parseFloat();// 10.0;
    //setPoint = Serial.parseFloat();

    if (Serial.readString() == ('\n')) {
      Serial.flush();
      Serial.print("**************************************************");
      Serial.print("**************************************************");
      Serial.print("\tkp: "); Serial.print(kp); Serial.print("\tkd: "); Serial.print(kd); Serial.print("\tki: "); Serial.println(ki);
      delay(5000);
      //Serial.print("base: "); Serial.print(velMax); Serial.print("\tkp: "); Serial.print(kp); Serial.print("\tkd: "); Serial.print(kd); Serial.print("\tki: "); Serial.println(ki);
      //delay(5000);
    }
    
  }
}

