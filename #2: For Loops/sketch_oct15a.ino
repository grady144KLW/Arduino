/*
Declaring the pins of the LEDs
 */
 
int w1 = 5;
int w2 = 8; 
int wait_on_time = 500; // Declaring how long the LEDs should stop flashing
int wait_off_time = 500;

void setup() {

/*  
Declaring whether the LEDs are input or output
 */

pinMode(w1, OUTPUT);
pinMode(w2, OUTPUT);
}

void loop() {
  
/*  
declaring a counter integer
then checking whether is greater or less than the number (5)
incrementing the counting integer 
*/

for (int a = 1; a<=5; a++){
digitalWrite(w1, HIGH);
delay(wait_on_time);
digitalWrite(w1, LOW);
delay(wait_off_time);  
}

/*
This would blink the LEDs five times due to the counter integer
 */

for (int b = 1; b<=5; b++){
digitalWrite(w2, HIGH);
delay(wait_on_time);
digitalWrite(w2, LOW);
delay(wait_off_time);  
}

}
