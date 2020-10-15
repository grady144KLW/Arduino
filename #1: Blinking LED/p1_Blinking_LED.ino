int White_led = 5; // Initializing what pin the LED is connected to 
int wait_on = 500; // Declaring how long the LED to stop flashing 
int wait_off = 500;

void setup() {
pinMode(White_led, OUTPUT); // Declaring whether the LED is an input or output

}

void loop() {
digitalWrite(White_led, HIGH); // Turning on the LED
delay(wait_on); // waiting for the led to stop flashing
digitalWrite(White_led, LOW); // Turning off the LED
delay(wait_off); // waiting for the led to stop flashing

}
