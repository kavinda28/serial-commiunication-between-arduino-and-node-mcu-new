#include <SoftwareSerial.h>
SoftwareSerial nodemcu(2, 3);


int sdata1 = 0; // sensor1 data
int sdata2 = 0; // sensor2 data
int sdata3 = 0; // sensor3 data
int sdata4 = 0;
int sdata5 = 0;
String cdata; // complete data, consisting of sensors values

// defines pins numbers
const int trigPin = 4;  //D4
const int echoPin = 5;  //D5

// defines variables
long duration;
int distance;
void setup()
{
  Serial.begin(9600);
  nodemcu.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop()
{


  sdata1 = 101;
  sdata2 = 200;
  sdata3 = 404;
  sdata4 = 500;
  ultrasonic();//call function
  sdata5 = distance;


  cdata = cdata + sdata1 + "," + sdata2 + "," + sdata3 + "," + sdata4 + "," + sdata5; // comma will be used a delimeter
  Serial.println(cdata);
  nodemcu.println(cdata);
  delay(500); // 100 milli seconds
  cdata = "";

}


void ultrasonic() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(2000);
}
