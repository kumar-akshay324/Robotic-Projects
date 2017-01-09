#include<Servo.h>

int servoapin = 3;
int servobpin = 5;
int servocpin = 6;
int servodpin = 9;
int servoepin = 10;
int servofpin = 11;

Servo myaservo;
Servo mybservo;
Servo mycservo;
Servo mydservo;
Servo myeservo;
Servo myfservo;

int flexapin = A0;
int flexbpin = A1;
int flexcpin = A2;
int flexdpin = A3;
int flexepin = A4;
int flexfpin = A5;


void setup()
{
  myaservo.attach(servoapin);
  mybservo.attach(servobpin);
  mycservo.attach(servocpin);
  mydservo.attach(servodpin);
  myeservo.attach(servoepin);
//  myfservo.attach(servofpin);

}

void loop()
{
 int flexa = analogRead(flexapin);
 flexa = constrain(flexa , 491,676 );
 int anglea = map(flexa,491,676,0,180);
 myaservo.write(anglea);
 
 int flexb = analogRead(flexbpin);
 flexb = constrain(flexb ,467 ,801);
 int angleb= map(flexb,467 ,801,0,180);
 mybservo.write(angleb);
 
 int flexc = analogRead(flexcpin);
 flexc = constrain(flexc ,516 ,761);
 int anglec = map(flexc,516 ,761,0,180);
 mycservo.write(anglec);
 
 int flexd = analogRead(flexdpin);
 flexd = constrain(flexd ,411 ,552);
 int angled = map(flexd,411,522,0,180);
 mydservo.write(angled);
 
 int flexe = analogRead(flexepin);
 flexe = constrain(flexe,553 ,697);
 int anglee = map(flexe,553,697,0,180);
 myeservo.write(anglee);
 
 int flexf = analogRead(flexfpin);
 flexf = constrain(flexa ,512, 760);
 int anglef = map(flexf,512,760,0,180);
 myfservo.write(anglef);
 
 
}
