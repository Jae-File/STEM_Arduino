#include <Servo.h>
Servo moter;
int pos = 0;

void setup() {
  moter.attach(9);
  Serial.begin(9600);
}

void loop() {
  int flexReading = analogRead(A0);
  Serial.println(flexReading);
  
  if (flexReading > 250) {
    moter.write(180);
    
  }
  else { 
    moter.write(0);
  }
}
