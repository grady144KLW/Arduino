#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Wire.h>
#include <DS3231.h>

#define reset 4 // declaring the reset pin 
Adafruit_SSD1306 display(reset); // declaring the oled display object

DS3231 rtc(SDA, SCL); //declaring the ds3231 object 

void setup() {
  Wire.begin(); // initialising the i2c 
  display.begin(SSD1306_SWITCHCAPVCC ,0X3C); // initialising the oled display
  rtc.begin(); // // initialising the ds3231
//    rtc.setDOW(THURSDAY); // setting the day of the week 
//    rtc.setTime(18, 25, 0); // setting the time
//    rtc.setDate(20, 5, 2021); // setting the date
}

void loop() {
  display.clearDisplay(); // clears everything on the display 
  display.setTextColor(WHITE); // sets the colour of the text
  display.setTextSize(1); // sets the size of the text
  
  display.setCursor(0,0); // settting the cursor to at the top left
  display.print(rtc.getDOWStr()); // printing the day of the week 

  display.setCursor(0,10); // setting the cursor at the middle 
  display.print(rtc.getDateStr()); // printing the date

  display.setCursor(0, 20); // setting the cursor to the bottom left 
  display.print(rtc.getTimeStr()); // printing the time

  display.display(); // displaying the prints 
}
