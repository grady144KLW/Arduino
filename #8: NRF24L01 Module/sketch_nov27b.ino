#include <SPI.h> // Including the SPI library

#include <RF24Network.h>
#include <RF24Network_config.h>
#include <Sync.h>

/*
Including the RF24 network libraries 
 */
 
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

/*
Inclduing the RF24 libraries
 */

RF24 radio(7,8); // Declaring the object of CE & CSN (pins 7 & 8)
  RF24Network network(radio); // including the object in the RF 24 network object 
  const uint16_t Potent = 00; // Defining the addresses of the nodes (00 = potentiometer, 01 = LED) 
  const uint16_t LED = 01;

unsigned long pot_pin = A0; // declaring the pin of the Potentiometer 
unsigned long value; // delcaring the value of the potentiometer 
unsigned long led_value; // declaring the calculated value of the led 

void setup() {
  Serial.begin(9600); // turning on the serial monitor 
  SPI.begin(); // initializing the spi
  radio.begin(); // initializing the radio object 
  network.begin(90, Potent); // initializing the channel and the node address 

  pinMode(pot_pin, INPUT); // declaring the potentiometer as an input
}

void loop() {
  network.update(); // updating the network
  unsigned long value = analogRead(pot_pin); // reading the value of the potentiometer 
   unsigned long led_value = 255./1023.*value; // mapping the values of the potentiometer to the value of the LED
      RF24NetworkHeader header(LED); // dclaring a netwrok header to assign the address of the node where the data is going
      bool ok = network.write(header, &led_value, sizeof(led_value)); // sending the data to the LED node
}
