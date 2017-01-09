 int D0 = 32;
 int D1 = 34;
 int D2 = 36;
 int D3 = 38;
 
 void setup()
 { 
   pinMode( D0 , INPUT );
   pinMode( D1 , INPUT );
   pinMode( D2 , INPUT );
   pinMode( D3 , INPUT );
 
   Serial.begin(9600);
 }
 
 
 int a , b , c , d; 
 
 void loop()
 {
    a = digitalRead(D0); 
    b = digitalRead(D1); 
    c = digitalRead(D2);
    d = digitalRead(D3);
 
    Serial.print( a );
    Serial.print( "  " );
    Serial.print( b );
    Serial.print( "  "); 
    Serial.print( c );
    Serial.print( "  " );
    Serial.print( d );
    Serial.println("" );
    delay(1000);
 }
