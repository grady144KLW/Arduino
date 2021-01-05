#include <DHT.h>
#include <DHT_U.h>

#define Type DHT11 // Declaring what type the sensor is
int pin = 2; // Declaring the pin of the sensor
DHT dht(pin, Type); // Creating the object
float humidity; // Declaring the humidity variable 
float temperature; // Declaring the temperature variable

void setup() {
Serial.begin(9600);
dht.begin();  
}

void loop() {
humidity = dht.readHumidity(); // reading the humidity values and assigning it to the variable
temperature = dht.readTemperature(); // reading the temperature values and assigning it to the variable

// Printing the Humidity 
Serial.print("Humidity: ");
Serial.print(humidity); 
Serial.print("% ");

// Printing the Temperature
Serial.print("Temperature: ");
Serial.print(temperature);
Serial.println(" C");
delay(500);
}
