#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <Adafruit_SSD1306.h>
#include <splash.h>

#define reset 4 // declaring the reset pin 
Adafruit_SSD1306 display(reset); // declaring the oled display object

#include <DS3231.h> // ds3231 rtc library
DS3231 rtc(SDA, SCL); //declaring the ds3231 object


#include <Wire.h> // i2c library

int bu1 = 7; // up button pin
int bu2 = 3; // middle button pin
int bu3 = 2; // down button pin
int upbu; // up button variable
int selectbu; // middle button variable
int downbu; // down button variable
bool up = false; // changing the button states if a button was pressed
bool middle = false; // changing the button states if a button was pressed
bool down = false; // changing the button states if a button was pressed
int up_old = 1; // previous button state for the up button
int select_old = 1; // previous button state for the select button
int down_old = 1; // previous button state for the down button

int hold = 1; // to keep the page to where its at

int i = 1; // for moving the option menu
int j = 1; // secondary counter for moving the option menu

int bleep = 9; // buzzer pin 
int tone_ = 5; // the tone of the buzzer

void setup() {
  Serial.begin(9600);  
  Wire.begin(); // begin the i2c
  display.begin(SSD1306_SWITCHCAPVCC, 0X3C); // begin the oled
  display.clearDisplay(); // clear the display immediately 
  pinMode(bu1, INPUT); // declare the up button as input
  pinMode(bu2, INPUT); // declare the middle button as input
  pinMode(bu3, INPUT); // declare the down button as input
  pinMode(bleep, OUTPUT);
  rtc.begin(); // begin the real time clock 
//  rtc.setTime(18, 04, 0); // setting the time
//  rtc.setDate(15, 06, 2021); // setting the date

}

void loop() {
  selectbu = digitalRead(bu2); // reading the values of the middle button
  middlesel();
  homescreen();
  switching();
}

void homescreen(){
  display.clearDisplay();
  display.setTextColor(WHITE); // sets the colour of the text
  display.setTextSize(1);
  display.setCursor(0,0); // set the cursor at the top left
  display.print(rtc.getDateStr()); // print the date

  display.setCursor(80,0); // set the cursor at the top right 
  display.print(rtc.getTemp()); // print the temperature
  display.print("'C"); // print the celsius
  
  display.setTextSize(2); // increase the size of the text
  display.setCursor(20,15); // set the cursor at the middle 
  display.print(rtc.getTimeStr()); // print the time
  display.display(); // show the whole text on the oled

}


void switching(){
  if (middle){ // if the middle button was pushed within the homescreen 
    middle = false; // change the status to false
    menu(); // move to the menu page
  }
}

void menu(){
  int counter = 0;
  while (counter < 50){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(50,0); // set the cursor at the top left
    display.print("menu");
     
    display.setCursor(0,10);
      if (i == 1){ // if the counter is at the first option
        display.setTextColor(BLACK, WHITE); // sets the colour of the text
 //       counter = ;
  }
      else{
        display.setTextColor(WHITE); // sets the colour of the text
    }
    
      display.print("mute buzzer");
      display.setCursor(0,20);
      if (i == 2){// if the counter is at the second option
        display.setTextColor(BLACK, WHITE); // sets the colour of the text
//        counter = ;
  }
      else{
        display.setTextColor(WHITE); // sets the colour of the text
    }
      display.print("reset");
      display.display();
      counter++;
      within_menu();
      Serial.print("Counter: ");
      Serial.print(counter);
      Serial.print(" ");
      Serial.print("i: ");
      Serial.println(i);
  }
}

void within_menu(){
    upbu = digitalRead(bu1); // reading the values of the up button
    selectbu = digitalRead(bu2); // reading the values of the middle button
    downbu = digitalRead(bu3); // reading the values of the down button
    upsel();
    middlesel();
    downsel();
    if (down && hold == 1){ // if the down button has been pressed while on the first page
    down = false; // switch the value of the down button
    i++; // increase the menu variable by 1 (when the down button is pressed, the menu variable is increasing)  
  }
  if (i == 2){ // if the menu reached at 2
    i = 2; //  go to the second option (reset option)
  }
  if (i == 3){ //if the menu is 3
    i = 1; // go back to the third option (text size option)
  }

  if (i == 1 && hold == 1){ // if the couter is at the first menu
    if(middle){ // once the select button has been pressed for the first option
      middle = false;
      mute_buzzer(); // display the new options within the first menu option
    }
  }
 
  if (up & hold == 1){ // if the up button is pressed 
    up = false; // switch the value of the up button 
    i--; // (when the up button is pressed, the menu variable is decreasing) 
  }

  if(i == 1){ // if the menu reached one
    i = 1; // go to the first menu 
  }
  
  if (i == 0){ // the menu only has two options, so if the menu is 0
    i = 2; // then go to the reset option 
  }
}

void mute_buzzer(){
        if (j == 1){
          display.setTextSize(1);
          display.setCursor(0,10);
      if (i == 1){ // if the counter is at the first option
        display.setTextColor(BLACK, WHITE); // sets the colour of the text
  }
      else{
        display.setTextColor(WHITE); // sets the colour of the text
    }
    
      display.print("unmute buzzer");
      display.setCursor(0,20);
      if (i == 2){// if the counter is at the second option
        display.setTextColor(BLACK, WHITE); // sets the colour of the text
  }
      else{
        display.setTextColor(WHITE); // sets the colour of the text
    }
      display.print("reset");
      display.display();
  }
        }
      
void upsel(){ // i didn't change this part at the momment 
  if (up_old == 0 && upbu == 1){ // if the up button has not been pressed 
    if(up == false){ // if the status reads false
      up = true; // change the up status to true (in other words, switch the values of the buttons)
      analogWrite(bleep, tone_);
      delay(30);
      analogWrite(bleep, 0);
    }
    else{
      up = false; // switch back the values of the buttons
    }
    delay(50); // to remove the bouncing 
}
  up_old = upbu; // the old value of the button will equal to the current value of the button 
}

void middlesel(){
  if (select_old == 0 && selectbu == 1){
    if(middle == false){
      middle = true;
      analogWrite(bleep, tone_);
      delay(30);
      analogWrite(bleep, 0);
    }
    else{
      middle = false;
    }
    delay(50);
}
  select_old = selectbu;  
}

void downsel(){
  if (down_old == 0 && downbu == 1){
    if(down == false){
      down = true;
      analogWrite(bleep, tone_);
      delay(30);
      analogWrite(bleep, 0);
    }
    else{
      down = false;
    }
    delay(50);
}
  down_old = downbu;
}
