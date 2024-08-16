#include <Stepper.h>
#include <SoftwareSerial.h>

SoftwareSerial miBT(12,13);
char DATO=0;
int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
Stepper motor1(2048,IN1,IN3,IN2,IN4);

int derecha = 2;
int izquierda = 3;
int estado1;
int estado2;
int piso=0;

void setup() {
  pinMode (derecha, INPUT);
  pinMode (izquierda, INPUT);
  digitalWrite(derecha, LOW);
  digitalWrite(izquierda, LOW);
  motor1.setSpeed(13);
  Serial.begin(9600);
  miBT.begin(9600);


}

void loop() {
  

    estado1 = digitalRead(derecha);
    estado2 = digitalRead(izquierda);
  
   if(estado1==HIGH && piso==0){
      motor1.step(512*48);
      delay(2000);
      piso++;
   }
   if (estado1==HIGH && piso==0){
       Serial.println("Error");
    }
   if(estado2==HIGH && piso==1){
    motor1.step(-512*48);
    delay(2000);
    piso--;
    }
     if(estado2==HIGH && piso==0) {
        Serial.println("Error");
    }
    if((estado1==HIGH)&&(estado2==HIGH)){
    Serial.println("Error");
    }

  if(miBT.available()){
      DATO = miBT.read();

      if(DATO=='1' && piso==0){
        motor1.step(512*48);
        delay(2000);
        piso++;
      }
      if (DATO=='1' && piso==0){
         Serial.println("Error");
      }
      if(DATO=='2' && piso==1){
        motor1.step(-512*48);
        delay(2000);
        piso--;
      }
      if(DATO=='2'&& piso==0) {
        Serial.println("Error");
      }
      if((DATO=='1')&&(DATO=='2')){
        Serial.println("Error");
      }



  }


}
