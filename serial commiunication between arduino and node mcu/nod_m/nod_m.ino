#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

//pin tx-2,rx-3



String myString; // complete message from arduino, which consistors of snesors data
char rdata; // received charactors

int c=0;
int x=0;


void setup()
{
  // Debug console
  Serial.begin(9600);


  
}

void loop()
{
 
  if (Serial.available() > 0 ) 
  {

    rdata = Serial.read(); 
    myString = myString+ rdata; 
   // Serial.print(rdata);
    if( rdata == '\n')
    {
   //  Serial.println(myString); 
  // Serial.println("fahad");
// new code
String I = getValue(myString, ',', 0);
String m = getValue(myString, ',', 1);
String n = getValue(myString, ',', 2); 
String k = getValue(myString, ',', 3); 

String nw = getValue(myString, ',', 4); 

Serial.println("value 1= ");
Serial.println(I);
Serial.println("value 2= ");
Serial.println(m);
Serial.println("value 3= ");
Serial.println(n);
Serial.println("value 4= ");
Serial.println(k);
Serial.println("distance= ");
Serial.println(nw);
 
  
  myString = "";
// end new code
delay(500);
    }
  }

}



String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
