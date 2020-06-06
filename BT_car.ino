#include<SoftwareSerial.h>
SoftwareSerial BT(0,1); //Tx Rx respectively
String readdata;

void setup() {
  BT.begin(9600);
Serial.begin(9600);
pinMode(12, OUTPUT); // connect to input 1 of l293d
pinMode(9, OUTPUT); // connect to input 4 of l293d
pinMode(11, OUTPUT); // connect to input 3 of l293d
pinMode(10, OUTPUT); // connect to input 2 of l293d

}
//-----------------------------------------------------------------------// 
void loop() {
while (BT.available()){  //Check if there is an available byte to read
delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
readdata += c; //build the string- "forward", "reverse", "left" and "right"
  } 
if (readdata.length() > 0) {
Serial.println(readdata); // print data to serial monitor
// if data received as forward move robot forward
if(readdata == "forward") 
  {
digitalWrite(12, HIGH);
digitalWrite (9, HIGH);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
delay(100);
  }
  // if data received as reverse move robot reverse

else if(readdata == "backward")
  {
digitalWrite(12, LOW);
digitalWrite(9, LOW);
digitalWrite(11, HIGH);
digitalWrite(10,HIGH);
delay(100);
  }
// if data received as right turn robot to right direction.
else if (readdata == "right")
  {
digitalWrite (12,HIGH);
digitalWrite (9,LOW);
digitalWrite (11,LOW);
digitalWrite (10,LOW);
delay (100);

  }
// if data received as left turn robot to left direction
else if ( readdata == "left")
 {
digitalWrite (12, LOW);
digitalWrite (9, HIGH);
digitalWrite (11, LOW);
digitalWrite (10, LOW);
delay (100);
 }
 // if data received as stop, halt the robot

else if (readdata == "stop")
 {
digitalWrite (12, LOW);
digitalWrite (9, LOW);
digitalWrite (11, LOW);
digitalWrite (10, LOW);
delay (100);
 }




readdata="";}} //Reset the variable


