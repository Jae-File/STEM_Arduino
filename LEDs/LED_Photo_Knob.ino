// declare variables
int blue = 13;
int yellow = 11;

int photoCell = 0;
int knob = 0;

int brightness = 0;
int intensity = 0;

void setup() {
  Serial.begin(9600); // start serial monitor

  // declare LED mode as output
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  photoCell = analogRead(A0); //read from A0, which is photo sensor
  knob = analogRead(A1); //read from A1, which is potienmeter
  
  int i = photoCell/8;  //devide the reading from photo sensor

  //map the reading from photo sensor to the brightness of LED
  brightness = map(photoCell, 650, 920, 0, 255); 

  //map the reading from knob to the bright intensity of LED
  intensity = map(knob, 0, 1024, 0, 255);

  //print on serial monitor
  Serial.print(photoCell);
  Serial.print("\t");
  Serial.println(brightness);

  //write the reading from photosensor to LED
  //analogWrite(yellow, 255-brightness); 

  //write the reading from knob to LED
  analogWrite(yellow, intensity);

  //condition, when mapped reading greater than 220, blue light off
  if (brightness > 220) {
    digitalWrite(blue, LOW);
  } 
  //otherwise, blink blue LED
  else {
    digitalWrite(blue, HIGH);
    delay(i);
    digitalWrite(blue, LOW);
    delay(i);
  }
}
