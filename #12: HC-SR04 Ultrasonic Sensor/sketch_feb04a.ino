#include <NewPing.h>

// Declaring the pins
int trig = 7;
int echo = 12;

int r = 10;

NewPing Sensor(trig,echo); // creating the object
float distance; // declaring the variable distance 

void setup() {
  Serial.begin(9600);
  pinMode(r, OUTPUT);
}

void loop() {
  distance = Sensor.ping_cm(); // assigning the distance to the sensor object in cm
  Serial.print("Distance: ");
    if(distance > 20 || distance < 2){ // if the distance reaches above 400 or less than two 
      digitalWrite(r, HIGH);
      Serial.println("Out of range"); // print out of range
    }
    else{
      digitalWrite(r, LOW);
      Serial.print(distance); // print the values 
      Serial.println(" cm");
      delay(500);
    }
}
