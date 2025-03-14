// Thiết kế bởi RC Man 
const int trigPin = 6;
const int echoPin = 5;
long duration;
int distance = 0;
#define rung  2
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(4, 3); // TX, RX
DFRobotDFPlayerMini myDFPlayer;

void setup() 
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(2, OUTPUT);
Serial.begin(9600);
mySoftwareSerial.begin(9600);
if (!myDFPlayer.begin(mySoftwareSerial, true, false)) {while(true){delay(0); }}
myDFPlayer.volume(30); 
myDFPlayer.play(1);delay(1500); // khi cắm điện thì âm thanh khởi động được kích hoạt (bài 1)
}
void loop() {
if ((distance <30)&&(distance > 0))
{
  Vat_can_cach_30cm ();
  digitalWrite(rung, HIGH);   // Motor rung được bật
  delay(200); 
}
else if ((distance > 31)&&(distance < 50))
{
  Vat_can_cach_50cm ();
  digitalWrite(rung, HIGH);   // Bật rung
  delay(200);                 // Thời gian bật rung 
  digitalWrite(rung, LOW);    // Tắt rung
  delay(200);                 // Thời gian tắt rung
}
else if ((distance > 51)&&(distance < 70)) 
{
  Vat_can_cach_70cm ();
  digitalWrite(rung, HIGH);   // Bật rung
  delay(200);                 // Thời gian bật rung 
  digitalWrite(rung, LOW);    // Tắt rung
  delay(200);                 // Thời gian tắt rung
  
}
else if (distance > 90)
{
  digitalWrite(rung, LOW);
}
delayMicroseconds(10);
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
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance); //distance is the returned integer, it is the distance in cm
}
void Vat_can_cach_30cm()           //khi vật cản cách 30cm thì sẽ phát âm thanh (2)
{ 
  myDFPlayer.play(2);delay(1800);
}

void Vat_can_cach_50cm()          //khi vật cản cách 30-50cm thì sẽ phát âm thanh (3) 
{
  myDFPlayer.play(3);delay(1800); 
}
void Vat_can_cach_70cm()           //khi vật cản cách 50-70cm thì sẽ phát âm thanh (4)
{
  myDFPlayer.play(4);delay(1800); 
}
