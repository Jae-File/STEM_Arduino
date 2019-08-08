// This code plays a pitch that changes based on a changing analog input such as a photoresistor
 

void setup() {            // beginning of our setup() area.
  
  Serial.begin(9600);     // start up the Serial Monitor
}

void loop() {
  
  int sensorReading = analogRead(A0);         // read the sensor 
  Serial.println(sensorReading);              // print the sensor reading so you know its range

  
  int thisPitch = map(sensorReading, 200, 1000, 120, 1500);     // map the photoresistor range (roughly 200 to 1000 - it will vary!)
                                                                // to the output pitch range (120 - 1500Hz)
                                                                // change the minimum and maximum input numbers depending on the range 
                                                                // your sensor's giving and the sounds you want to hear

if(sensorReading < 600)                   // the piezo will only make sound IF the sensor reads less than 600
                                          // change this number to reflect when you want the piezo to make sound 
                                          // if you want the piezo to make sound ALL the time, delete this line. 
                                          
{ tone(8, thisPitch, 10);                 // when this happens, connect pin 8 to the piezo and play the pitch 
 
  delay(1);                               // include a small delay in between reads for stability

}
  


}
