int pot = A1; //declaring the pin of the potentiometer
int potvalue; // reading the values from 0-1023
int led = 3; // declaring the pin of the led
int ledvalue; // calculating the value of the led with the potentiometer

void setup() {
Serial.begin(9600); 
pinMode(pot, INPUT); // reading the potentiometer 
pinMode(led, OUTPUT);
}

void loop() {

potvalue = analogRead(pot); // reading the value from the potentiometer
Serial.print(" LED Brightness: "); // printing the brightness of the led
Serial.println(potvalue); // printing the value of the potentiometer (0-1023)

 
ledvalue = 255./1023.*potvalue; // calculating the value of the led with the potentiometer
analogWrite(led, ledvalue); // adding the calculated value to the led

}
