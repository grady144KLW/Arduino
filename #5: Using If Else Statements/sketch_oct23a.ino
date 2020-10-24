/*
 Delaring the pins of the LED 
 */
int w1 = 3;
int w2 = 2;

void setup() {
Serial.begin(9600); // Turning on the serial monitor 
pinMode(w1, OUTPUT);
pinMode(w2, OUTPUT);

}

void loop() {
for (int a = 0; a<=10; a++) { // declaring a counter variable 
Serial.println(a); // printing the counter variable
delay(500); // slowing down the counter 

if (a == 1){ // if the counter reaches 1
digitalWrite(w1, HIGH); // turn on the first LED
}
else { // if the counter doesn't reach to 1
digitalWrite(w1, LOW); // turn off the first LED     
}


if (a==10){ // If the counter reaches 10
digitalWrite(w2, HIGH); // turn on the second LED 
}
else{ // if the counter doesn't reach to 10
digitalWrite(w2, LOW); // turn off the second LED   
}
}
}
