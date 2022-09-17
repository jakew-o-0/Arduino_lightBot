#include<Servo.h>
Servo serR;
Servo serL;

char PythonData;
int LightL;
int LightR;
int bat = 5;
int defaultLightLvl;

//////////////////////////////////////////////
//// Start Func//Main logic for the robot////
void checkLight(){
    digitalWrite(bat, HIGH);
    
    LightR = analogRead(A0);
    delay(10);
    LightL = analogRead(A1);
    delay(10);

    if(LightR > defultLightLvl && LightL <= defaultLightLvl){
        serR.write(0);
        serL.write(120);
      }
    else if(LightL > defaultLighLvl && LightR <= defaultLightLvl){
        serL.write(180);
        serR.write(40);
      }
    else{
        serR.write(40);
        serL.write(140);
      }
}
//// End Func //////////////////////////
///////////////////////////////////////

///////////////////////////////////////////////////////
//// Start Func//Calabrates the robot to the light/////
void CalabrateLightLvl(){
  LightR = analogRead(A0);
  delay(10);
  LightL = analogRead(A1);
  delay(10);

  return defaultLightLvl = LightR + LightL / 2;
}
//// End Func////////////////////////////////////////
/////////////////////////////////////////////////////

void setup() {
  serR.attach(6);
  serL.attach(7);
  pinMode(bat, OUTPUT);

  CalabrateLightLvl();

  Serial.begin(9600);

}

void loop() {
  if(Serial.available() > 0){
      PythonData = Serial.read();
      Serial.print(PythonData);
    }
  
   if(PythonData == '1'){
      checkLight();
    }
   else{
        serR.write(90);
        serL.write(90);
    } 
  

}
