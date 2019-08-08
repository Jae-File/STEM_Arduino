
// This code makes a continuous servo motor spin at a different speed based on how much light it is recieving. 

#include <Servo.h>

Servo myservo;   //This is the name of our servo 

void setup() {  

Serial.begin(9600);      // Start up the Serial Monitor, since you're using a sensor   

myservo.attach(10);      // attach your motor to pin 10
}

void loop() { 


int sensorReading = analogRead(A0);     //read the values from A0
Serial.println(sensorReading);         // show photoresistor values in the Serial Monitor window 

sensorReading = map (sensorReading, 100, 700, 0, 90);     // map A0 values to the speed of the motor
                                                          // you may need to change the range of the photoresistor to improve results
                                                          // the first two numbers in the map() represent the lowest and highest values
                                                          // you're seeing in the serial monitor  
                                                          // the second two numbers represent the speed of the 360 servo 
          
myservo.write (sensorReading);          // make the servo spin based on the map
 
    

}
