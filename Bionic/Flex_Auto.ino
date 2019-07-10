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
  
  if (flexReading < 150) {
    moter.write(0);
    
  }
  else { //
    for (pos = 0; pos <180; pos++) {
      moter.write(pos);
      delay(2);
    }
    for (pos = 180; pos >0; pos--) {
      moter.write(pos);
      delay(5);
    }
  }
}
