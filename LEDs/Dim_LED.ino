// CEPHALOPODS - BASE CODE

// This code will activate a sequence of LEDs when a photocell senses darkness.



////////////   VOID SETUP(): CODE THAT RUNS ONCE   ////////////



void setup() {    // beginning of our setup() area.



  Serial.begin(9600);  // start up the Serial Monitor.



  //////  SETTING UP THE PINS FOR YOUR LEDS

  // We have to tell the Arduino which pins we want to plug our LEDs into.

  // The six numbers below are the pins on the Arduino that have the ~ symbol printed.

  // The ~ means the pin has a special function which lets you glow and fade your LEDs.

  // Be sure to change them if you decide to use different pins!



  pinMode(3, OUTPUT);

  pinMode(5, OUTPUT);

  pinMode(6, OUTPUT);

  pinMode(9, OUTPUT);

  pinMode(10, OUTPUT);

  pinMode(11, OUTPUT);



}                  // end of our setup() area.





////////////   VOID LOOP(): CODE THAT RUNS OVER AND OVER   ////////////



void loop() {     // beginning of our loop() area.



  ////// SENSOR READING AND IF STATEMENT

  // Just like with our Plants domain, we are going to use a sensor and an IF statement to control our lights.

  // This time we are using a photoresistor (light sensor), which will report different numbers than our IR sensor did.

  // Upload the code, play with covering up the sensor or shining light on it, and see how it reacts in the Serial Monitor.



  int sensorReading = analogRead(A0);   // read what the sensor is telling us

  Serial.println(sensorReading);        // show what the sensor is telling us in the Serial Monitor



  // The rest of our program is going to be in an IF statement, like it was in the Plants domain.

  // You will have to change the number in the (          ) to customize your creature's behavior.



  if (sensorReading < 750) {           // If our sensor reads less than this number, then do the code between the {        }.



    

////// SWITCHING YOUR LEDS ON AND OFF

    // Next, you can switch LEDs completely ON and completely OFF using the command digitalWrite() with HIGH and LOW.

    // You can control how long they stay on or off by using the delay() command.

    // They will be at maximum brightness no matter what!



    digitalWrite(3, HIGH);  // The LEDs on every pin switch ON,

    digitalWrite(5, HIGH);

    delay(250);            // and then they shine for two seconds.

    digitalWrite(3, LOW);   // Then, they all get switched OFF,

    digitalWrite(5, LOW); 

    delay(250);            // and they stay off for half a second.





 ////// FADING YOUR LEDS UP AND DOWN

    // The glowLED and dimLED commands let you FADE your LEDs high or low. The first number is the pin of the LED,

    // and the second number is how much time it takes to completely fade (a higher number will take longer).

    // A value from 1 (fast) to 10 (slow) is usually pretty good.

    

    glowLED(3, 4);    // The LEDs on every pin will fade UP at a relatively fast speed.

    glowLED(5, 4);

    delay(250);      // They will shine at full fade for 2 seconds,  

    dimLED(3, 4);     // And then they will fade DOWN at the same speed.

    dimLED(5, 4);     

    delay(250);     // The program will wait 1 second before the loop restarts.      



  }                    // End of our if statement.

  

}                      // End of our loop() area.







// Don't change the code under here or your program might break.

// This is some custom code to make LED fading easier to use,

// so that we don't have to use more complicated concepts in our main program.



void glowLED(int ledPin, int glowTime) {

  for (int i = 0; i <= 255; i++) {

    analogWrite(ledPin, i);

    delay(glowTime);

  }

}



void dimLED(int ledPin, int fadeTime) {

  for (int i = 255; i >= 0; i--) {

    analogWrite(ledPin, i);

    delay(fadeTime);

  }

}
