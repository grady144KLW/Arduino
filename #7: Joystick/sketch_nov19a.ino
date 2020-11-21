int red = 3; // declaring red LED
int red_value; // delaring the calculation of red LED

int yellow = 5; // declaring yellow LED
int yellow_value;// delaring the calculation of yellow LED

int green = 12; // declaring Green LED

int x = A0; // declaring the x-axis of the joystick
int x_value; // declaring the value of the x-axis
int y = A1; // declaring the y-axis of the joystick
int y_value; // declaring the value of the y-axis
int sw = 2; // delcaring the integrated button of the joystick 
int sw_value; // declaring the value of the button 

void setup() {
Serial.begin(9600); // turning on the serial monitor   
pinMode(red, OUTPUT); 
pinMode(yellow, OUTPUT);
pinMode(green, OUTPUT);
pinMode(x, INPUT);
pinMode(y, INPUT);
pinMode(sw, INPUT);
digitalWrite(sw, HIGH); // declaring a internal pull up resistor to the button 
}

void loop() {
x_value = analogRead(x); // reading the value of the x-axis
y_value = analogRead(y);  // reading the value of the y-axis 
sw_value = digitalRead(sw); // reading the value of the button 

red_value = 255./1023.*x_value; // mapping the values of the x-axis to the values of the red LED 
yellow_value = 255./1023.*y_value; // mapping the values of the x-axis to the values of the red LED 

analogWrite(red, red_value); // adjusting the brightness of the red LED aaccording to the joystick
analogWrite(yellow, yellow_value); // adjusting the brightness of the yellow LED aaccording to the joystick

if (sw_value == 0){ // if the joystick is pressed 
digitalWrite(green, HIGH); // turn on the green LED
}
else { // if the joystick has not been pressed 
digitalWrite(green,LOW); // turn off the green LED 
}

Serial.print(" red brightness: ");
Serial.print(x_value); // printing the values of the x-axis 
Serial.print(" yellow brightness: ");
Serial.print(y_value); // printing the values of the y-axis 
Serial.print(" Green Light: ");
Serial.println(sw_value); // printing the values of the button
}
