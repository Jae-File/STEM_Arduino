// HIGH SCHOOL - BIONIC CREATURES - SERVO CODE
// This code will move a servo motor back and forth, without using any sensros.

////////////   CODE COMMENTS   ////////////

// Anytime you see gray text with // before it, this is called a comment. Comments let us write notes in regular language,
// and the computer won't think that it's code.


////////////   NAMING YOUR SERVO MOTOR   ////////////

#include <Servo.h>  // this tells the computer we want to use special commands made for controlling servos.
Servo myservo;      // we are telling the computer we are using a Servo motor and naming it "myservo".


////////////   VOID SETUP(): CODE THAT RUNS ONCE   ////////////

// Underneath this description is an important area in the code called void setup().
// Any code that we put in the setup() area will run just one time, when the Arduino starts up.
// After the word setup(), you can see some brackets that look like this: {    }
// We want to put our code that runs just once between these brackets.

void setup() {        // Beginning of setup().

  myservo.attach(9);  // this command tells the computer that we have a servo motor named "myservo" plugged into pin 9.
                      // Change this if you plugged your motor into a different pin!

}                     // End of setup().


////////////   VOID LOOP(): CODE THAT RUNS OVER AND OVER   ////////////

// Underneath this description is another important area in the code called void loop().
// Any code we put in the loop() area will run over and over again.
// Once the Arduino gets to the end of loop(), it will start over from the beginning of loop().
// The brackets after loop {       } is where we will put the repeating "action" parts of our program.

void loop() {        // Beginning of loop().


////// SWEEP(): HOW WE MOVE OUR SERVO MOTOR
  // Below, you will see sweep(), which is a command that lets us control the speed and position of our servo motor.
  // Inside the (), you have to put three things in order:
  // 1) The name you gave your servo motor (in this case, it's "myservo").
  // 2) The degree you want the motor to move to - servos can move from 0 to 180 degrees. You can tell it exactly which degree to move to.
  // 3) The speed that you want it to move with. The bigger the number, the slower it will go. As an example: 1 is very fast, 10 is medium-slow.

  sweep(myservo, 180, 4);    // move (sweep) our servo to 180 degrees at a medium speed.
  delay(500);                // this delay() command tells the computer to wait a bit before doing anything else. It uses milliseconds (ms), and 1000 ms = 1 second.
  sweep(myservo, 0, 12);     // sweep our servo back to 0 degrees at a slower speed.
  delay(500);                // wait another half a second before doing anything else.


}         // This is the end of loop(). The program will start over from the beginning of loop().



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
