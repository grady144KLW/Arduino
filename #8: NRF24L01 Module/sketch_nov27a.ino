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

RF24 radio(7,8); // Declaring the object
  RF24Network network(radio); // including the object in the RF 24 network object 
  const uint16_t LED = 01; // assigning the node address of the LED 

int red = 5; // delcaring the pin of the LED

void setup() {
  Serial.begin(9600); // turning on the serial monitor 
  SPI.begin(); // initializing the spi
  radio.begin(); // initializing the radio object 
  network.begin(90, LED); // initializing the channel and the node address 
}

void loop() {
  network.update(); // updating the network
    if(network.available()){ // checking for any data
      RF24NetworkHeader header; // dclaring a netwrok header 
      unsigned long incomingdata; // declaring where the data will be stored
        network.read(header, &incomingdata, sizeof(incomingdata)); // reading the data 
          analogWrite(red, incomingdata); // Using the data to adjust the brightness of the LED
            Serial.println("GOT DATA");
}       
    else{
      Serial.println("NO DATA!!!");
    }
}
