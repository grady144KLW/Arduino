int phr = A4; // declaring the pin of the photodetecter 
int phr_val; // delcaring the value of the photodetecter 

int redLED = 4; // initalize the red pin 
int greenLED = 2; // initalize the green pin

void setup() {
pinMode(phr, INPUT);
pinMode(redLED, OUTPUT);
pinMode(greenLED, OUTPUT);
Serial.begin(9600);
}

void loop() {
phr_val = analogRead(phr); // reading the value from the photodetecter
Serial.println(phr_val); // printing the value on the serial monitor
delay(250);

if (phr_val <= 80){ // if the value is less then or equal to 80
digitalWrite(redLED, HIGH); // turn on the red LED 
}
else { // if the value isn't less than or equal to 80
digitalWrite(redLED, LOW); // turn off the red LED 
}
if (phr_val > 365){ // if the value is greater than 365 
digitalWrite(greenLED, HIGH); // turn on the green LED 
}
else { // if the value isn't greater than 365
digitalWrite(greenLED, LOW); // turn off the green LED 
}
}
