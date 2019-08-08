// CEPHALOPODS - ALTERNATE CODE
// This code will activate a blink all of LEDs when a photocell senses darkness.
// Run the Serial monitor to check that the photoresistor is wired properly (Tools > Serial Monitor)

void setup() {    // beginning of our setup() area.

  Serial.begin(9600);  // start up the Serial Monitor.

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop() {     // beginning of our loop() area.


  int sensorReading = analogRead(A0);   // read what the sensor is telling us
  int i = analogRead(A0)/8; // divide it by 8 and call it "i", higher numbers will make it blink faster
  Serial.println(sensorReading);        // show what the sensor is telling us in the Serial Monitor


  if (sensorReading < 800) {           // If our sensor reads less than this number, then do the code between the {        }
                                      // You can change this number between 0-1023 based on the readings you are getting. Check your serial monitor under the Tools menu.


    digitalWrite(3, HIGH);
    delay(i);
    digitalWrite(3, LOW);

    digitalWrite(5, HIGH);
    delay(i);
    digitalWrite(5, LOW);

    digitalWrite(6, HIGH);
    delay(i);
    digitalWrite(6, LOW);

    digitalWrite(9, HIGH);
    delay(i);
    digitalWrite(9, LOW);

    digitalWrite(10, HIGH);
    delay(i);
    digitalWrite(10, LOW);

    digitalWrite(11, HIGH);
    delay(i);
    digitalWrite(11, LOW);

  }
}
