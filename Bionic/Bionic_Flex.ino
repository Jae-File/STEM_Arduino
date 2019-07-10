// BIONIC MECHANISMS - CODE #2
// This code moves a servo motor according to the degree
// of bending or pressure on a flex sensor.

////////////   CODE COMMENTS   ////////////

// This is a comment! 
// It needs to have the two forward-facing slashes before it,
// and it will last until the next line of the program.


////////////   NAMING YOUR SERVO MOTOR   ////////////

#include <Servo.h>  // this tells the computer we want to use special commands made for controlling servos.
Servo myservo;      // we are telling the computer we are using a Servo motor and naming it "myservo".


////////////   VOID SETUP(): SETTING UP PARTS TO USE  ////////////

void setup() {        // Beginning of setup().

  myservo.attach(9);  // this command tells the computer that we have a servo motor named "myservo" 
                      // plugged into pin 9.
                      
  Serial.begin(9600); // this starts up our Serial Monitor, which gets explained later.

}                     // End of setup().


////////////   VOID LOOP(): CODE THAT RUNS OVER AND OVER   ////////////

void loop() {         // Beginning of loop().         

////// SENSOR READING & SMOOTHING
  int smoothedReading = averageReadings(analogRead(A0), 30);  // we are going to take the average of 30 sensor readings and name it "smoothedReading".

////// PRINTING IN THE SERIAL MONITOR
  Serial.println(smoothedReading);        // Print out our smoothed sensor reading to the Serial Monitor so we can see what it is.
                                         
////// MAPPING SENSOR INFORMATION TO SERVO MOTION
  int servoPosition = map(smoothedReading, 400, 1023, 0, 180);   // We are taking our sensor reading, mapping it to the range of the servo motor
                                                                 // and naming it "servoPosition".

////// MOVING OUR SERVO WITH SWEEP()
  sweep(myservo, servoPosition, 0);    // we are going to move our servo named "myservo" to the servoPosition we stored above, at a very fast speed.

}         // End of loop(). The program will now run again from the beginning of loop().


// Don't change the code under here or your program might break.
// This is some custom code to make the sweeping motion easier to use,
// so that we don't have to use more complicated concepts in our main program.


void sweep(Servo servoName, int targetAngle, int sweepSpeed) {
  int currentPos = servoName.read();

  if (currentPos < targetAngle) {
    for (int i = currentPos; i < targetAngle; i++) {
      servoName.write(i);
      delay(sweepSpeed);
    }
  }

  if (currentPos > targetAngle) {
    for (int i = currentPos; i > targetAngle; i--) {
      servoName.write(i);
      delay(sweepSpeed);
    }
  }
}

int averageReadings(int sensorReading, int numberOfReadings) {
  int smoothedReading = 0;
  for (int i = 0; i < 30; i++) {
    smoothedReading = smoothedReading + analogRead(A0);
  }
  smoothedReading = smoothedReading / numberOfReadings;
  return smoothedReading;
}
