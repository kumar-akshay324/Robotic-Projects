int sensepin[5]={A0,A1,A2,A3,A4};
int motorPin[4]={8,9,10,11},i;
int ledPin[5]={2,3,4,5,6},a[5];
int d=0,c=0;                        // 5V for sensor array

int aref[5]={145,770,240,320,160};//{260,809,411,633,358};    
//int aref[5]={260,402,250,804,266};
//int d=0;
void setup() 
{ 
  for(int i=0;i<5;i++)
  {
      pinMode(sensepin[i],INPUT);
      pinMode(ledPin[i],OUTPUT);
      if(i==4) break;
      pinMode(motorPin[i],OUTPUT);
  }
  
}
void rightTurn()
{
  digitalWrite(motorPin[0],HIGH);
  digitalWrite(motorPin[1],LOW);
  digitalWrite(motorPin[2],HIGH);
  digitalWrite(motorPin[3],LOW); 
  delay(182);
  digitalWrite(motorPin[0],LOW);
  digitalWrite(motorPin[1],HIGH);
  digitalWrite(motorPin[2],HIGH);
  digitalWrite(motorPin[3],LOW);
  delay(1455);
  //while(!(a[0]>aref[0]&&a[1]>aref[1]&&a[2]>aref[2]&&a[3]>aref[3]&&a[4]>aref[4]));
    switch(d)
    {   case 0:
        d=3; // 3=west
        break;
        case 1:
        d=0; //0=north
        break;
        case 2:
        d=1;  // 1=east
        break;
        case 3:
        d=2;  //2=south
        break;
    }
    
      
}
void leftTurn()
{
  digitalWrite(motorPin[0],HIGH);
  digitalWrite(motorPin[1],LOW);
  digitalWrite(motorPin[2],HIGH);
  digitalWrite(motorPin[3],LOW); 
  delay(182);
  digitalWrite(motorPin[0],HIGH);
  digitalWrite(motorPin[1],LOW);
  digitalWrite(motorPin[2],LOW);
  digitalWrite(motorPin[3],HIGH);
  delay(1455);
  //while(!(a[0]>aref[0]&&a[1]>aref[1]&&a[2]>aref[2]&&a[3]>aref[3]&&a[4]>aref[4]));
    switch(d)
    {   case 0:
        d=1; // 1=east
        break;
        case 1:
        d=2; //2=south
        break;
        case 2:
        d=3;  // 3=west
        break;
        case 3:
        d=0;  //0=north
        break;
    }
 
}
void sensorTest()
{   
  for(int i=0;i<5;i++)
  {
    a[i]=analogRead(sensepin[i]);
  }
  if(a[0]>aref[0])
    analogWrite(ledPin[0],255);
  else
    digitalWrite(ledPin[0],LOW);
  if(a[1]>aref[1])
    analogWrite(ledPin[1],255);
  else
    digitalWrite(ledPin[1],LOW);
  if(a[2]>aref[2])
    analogWrite(ledPin[2],255);
  else
    digitalWrite(ledPin[2],LOW);
  if(a[3]>aref[3])
    digitalWrite(ledPin[3],HIGH);
  else
    digitalWrite(ledPin[3],LOW);
  if(a[4]>aref[4])
    digitalWrite(ledPin[4],HIGH);
  else
    digitalWrite(ledPin[4],LOW);
}

void loop() 
{
  
  int j=0;
  for(int i=0;i<5;i++)
  {
    a[i]=analogRead(sensepin[i]);
  }

  sensorTest();                       // for LEDs
   if(j==3) 
   {
    digitalWrite(motorPin[0],LOW);
    digitalWrite(motorPin[1],LOW);
    digitalWrite(motorPin[2],LOW);
    digitalWrite(motorPin[3],LOW);
    delay(8000);
     
   }
  if((a[0]<aref[0]&&a[1]<aref[1]&&a[2]>aref[2]&&a[3]<aref[3]&&a[4]<aref[4])||(a[0]<aref[0]&&a[1]>aref[1]&&a[2]>aref[2]&&a[3]>aref[3]&&a[4]<aref[4])) // 00100 or 01110
  {
    digitalWrite(motorPin[0],HIGH);
    digitalWrite(motorPin[1],LOW);
    digitalWrite(motorPin[2],HIGH);
    digitalWrite(motorPin[3],LOW); 
  }
  else if((a[0]<aref[0]&&a[1]>aref[1]&&a[2]>aref[2]&&a[3]<aref[3]&&a[4]<aref[4])||(a[0]<aref[0]&&a[1]>aref[1]&&a[2]<aref[2]&&a[3]<aref[3]&&a[4]<aref[4])) // 01100 or 01000
  {
    digitalWrite(motorPin[0],HIGH);
    digitalWrite(motorPin[1],LOW);
    digitalWrite(motorPin[2],LOW);
    digitalWrite(motorPin[3],LOW);
    delay(10);
  }
  else if((a[0]<aref[0]&&a[1]<aref[1]&&a[2]>aref[2]&&a[3]>aref[3]&&a[4]<aref[4])||(a[0]<aref[0]&&a[1]<aref[1]&&a[2]<aref[2]&&a[3]>aref[3]&&a[4]<aref[4])) // 00110 or 00010
  {
    digitalWrite(motorPin[0],LOW);
    digitalWrite(motorPin[1],LOW);
    digitalWrite(motorPin[2],HIGH);
    digitalWrite(motorPin[3],LOW);
    delay(10);
  }
  else if((a[0]>aref[0]&&a[1]>aref[1]&&a[2]<aref[2]&&a[3]<aref[3]&&a[4]<aref[4])||(a[0]>aref[0]&&a[1]<aref[1]&&a[2]<aref[2]&&a[3]<aref[3]&&a[4]<aref[4])) // 11000 or 10000
  {  
    digitalWrite(motorPin[0],HIGH);
    digitalWrite(motorPin[1],LOW);
    digitalWrite(motorPin[2],LOW);
    digitalWrite(motorPin[3],LOW);
    delay(10);
  }
  else if((a[0]<aref[0]&&a[1]<aref[1]&&a[2]<aref[2]&&a[3]>aref[3]&&a[4]>aref[4])||(a[0]<aref[0]&&a[1]<aref[1]&&a[2]<aref[2]&&a[3]<aref[3]&&a[4]>aref[4])) // 00011 or 00001
  {
    digitalWrite(motorPin[0],LOW);
    digitalWrite(motorPin[1],LOW);
    digitalWrite(motorPin[2],HIGH);
    digitalWrite(motorPin[3],LOW);
    delay(10);
  }
  else if(a[0]>aref[0]&&a[1]>aref[1]&&a[2]>aref[2]&&a[3]<aref[3]&&a[4]<aref[4]) // 11100
  {
    digitalWrite(motorPin[0],HIGH);
    digitalWrite(motorPin[1],LOW);
    digitalWrite(motorPin[2],LOW);
    digitalWrite(motorPin[3],LOW);
    delay(10);
  }
  else if(a[0]<aref[0]&&a[1]<aref[1]&&a[2]>aref[2]&&a[3]>aref[3]&&a[4]>aref[4]) // 00111
  { 
    digitalWrite(motorPin[0],LOW);
    digitalWrite(motorPin[1],LOW);
    digitalWrite(motorPin[2],HIGH);
    digitalWrite(motorPin[3],LOW);
    delay(10);
  }
  else if(a[0]>aref[0]&&a[1]>aref[1]&&a[2]>aref[2]&&a[3]>aref[3]&&a[4]>aref[4]) // 11111
  {
    
    if(c==0)
    {   
       
      rightTurn();
      c++;
    }
    else
    {   
        j++;//j=0
    }  
  }
  else if(a[0]<aref[0]&&a[1]<aref[1]&&a[2]<aref[2]&&a[3]<aref[3]&&a[4]<aref[4]) // 00000
  {
    digitalWrite(motorPin[0],LOW);
    digitalWrite(motorPin[1],HIGH);
    digitalWrite(motorPin[2],LOW);
    digitalWrite(motorPin[3],HIGH);
  }
}








