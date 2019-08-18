int blue = 13;
int yellow = 11;
int analogValue = 0;
int brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  analogValue = analogRead(A0);
  Serial.println(analogValue);
  brightness = analogValue/4;
  analogWrite(ledPin, brightness);

}


void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  // Read the value of the potentiometer knob
  int knobValue = analogRead(KNOB);

  // Map the potentiometer value to 1-255
  int intensity = map(knobValue, 1, 1024, 1, 255);

  // Output the respective value to the LED
  analogWrite(LED, intensity);
}
