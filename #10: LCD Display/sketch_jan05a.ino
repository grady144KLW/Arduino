#include <LiquidCrystal.h>
// Declaring the pins of the LCD Display
int rs = 7;
int e = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

// Declaring the object of the LCD display
LiquidCrystal lcd(rs,e,d4,d5,d6,d7);

void setup() {
lcd.begin(16,2);

}

void loop() {
lcd.setCursor(0,0); // Setting the cursor to the top 
lcd.print("Hello World"); // Printing hello world in that specified cursor 
lcd.setCursor(0,1); // Setting the cursor to the bottom
lcd.print("LCD Test"); // Printing LCD test in that specified cursor 

}
