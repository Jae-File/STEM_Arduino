void setup() {
  Serial.begin(9600);
 
  pinMode(6, INPUT_PULLUP);
 
  pinMode(5, OUTPUT); //speaker

}
void loop() {
  int knob = analogRead(A0);
  int b = map(knob, 0, 1023, 500, 0);
  if (digitalRead(6) == LOW) {
    tone(5, 725 , 250);
    delay(b);
    tone(5, 1450 , 100);
    delay(b);
    tone(5, 1086 , 200);
    delay(b);
    }      
}
