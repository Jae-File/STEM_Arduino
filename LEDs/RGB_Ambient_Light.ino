// Ambient RGB light
// Author: Jae
//
// Controls RGB LEDs; smoothly transitions through color values.

int delayTime = 20;
int maxBright = 255;
int photon = 0;

// The pins which each color value is output to.
int R = 7;
int R1 = 8;
int G = 9;
int G1 = 10;
int B = 11;
int Bl1 = 12;

// The initial values of each color.
int red = 0;
int green = 170;
int blue = 170;

// Indicates whether a color is incrementing (1) or decrementing (0).
int incR = 1;
int incG = 1;
int incB = 0;

// Smoothly changes the color values
void transition()
{
  if (red >= maxBright)
    incR = 0;
  else if (red <= 0)
    incR = 1;
  if (green >= maxBright)
    incG = 0;
  else if (green <= 0)
    incG = 1;
  if (blue >= maxBright)
    incB = 0;
  else if (blue <= 0)
    incB = 1;
  
  if (incR)
    red++;
  else
    red--;
  if(incG)
    green++;
  else
    green--;
  if(incB)
    blue++;
  else
    blue--;
}

// Sets the output voltage on the LED pins.
void setColor()
{
  analogWrite(R, red);
  analogWrite(R1, red);
  analogWrite(G, green);
  analogWrite(G1, green);
  analogWrite(B, blue);
  analogWrite(Bl1, blue);
  
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  photon = analogRead(A0);
  Serial.println(photon);
  int light = map(photon, 850,950, 0, 255);
  
  if (light < 150) { 
    transition();
    setColor();
    delay(delayTime);
  }
  else {
    digitalWrite(R, LOW);
    digitalWrite(R1, LOW);
    digitalWrite(G, LOW);
    digitalWrite(G1, LOW);
    digitalWrite(B, LOW);
    digitalWrite(Bl1, LOW);
  }
}
