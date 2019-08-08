#include <Servo.h>

Servo servo1;//360
Servo servo2;//360
Servo servo3;//180
Servo servo4;//180

int blue1 = 2;
int blue2 = 3;

int pos = 90;
int knob = 0;

void setup() {
  servo1.attach(7); //360 attaches the servo to pin 7 
  servo2.attach(8); //360
  servo3.attach(9); //180
  servo4.attach(10); //180
  pinMode(blue1, OUTPUT);
  pinMode(blue2, OUTPUT);
  Serial.begin(9600);
 
  pinMode(6, INPUT_PULLUP);
 
  pinMode(5, OUTPUT); //speaker

}

void loop() {
  knob = analogRead(A0); //read from A0, which is potienmeter
  //int blink = knob/2;
  int pause = map(knob, 0, 1023, 500, 0);
  Serial.println(knob);
  
  digitalWrite(blue1, HIGH);
  digitalWrite(blue2, HIGH);
  delay(pause);
  digitalWrite(blue1, LOW);
  digitalWrite(blue2, LOW);
  delay(pause/2);
  
  
  if (digitalRead(6) == LOW) {
    tone(5, 725 , 250);
    delay(pause);
    tone(5, 1450 , 100);
    delay(pause);
    tone(5, 1086 , 200);
    delay(pause);
  }
  
  servo3.write(90);
  servo4.write(90);
  
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo3.write(pos);
    servo4.write(pos);// tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo3.write(pos);
    servo4.write(pos);// tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  }

  if (knob > 500) {
    servo1.attach(7);  //reattach servo
    servo2.attach(8);
    servo1.write(-360000);
    servo2.write(360000);
  }
  else {
    servo1.detach();   //detach servo, thus stop servo
    servo2.detach();
  }
}
