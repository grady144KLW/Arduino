#include <LiquidCrystal.h>

#include <DHT.h>
#include <DHT_U.h>

// declaring the pins on the lcd display
  int rs = 7;
  int e = 8;
  int d4 = 9;
  int d5 = 10;
  int d6 = 11;
  int d7 = 12;

  LiquidCrystal lcd (rs,e,d4,d5,d6,d7); // declaring the lcd object

  #define Type  DHT11 // declaring what type the dht sensor is
  int dht_11 = 2; // delcaring the pin on the dht 
  DHT dht(dht_11, Type); // declaring the dht object

// declaring the humidity & temp variables
  float humidity;
  float temperature;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  dht.begin();
  lcd.clear();
}

void loop() {

  // reading the humidity & temp values and assigning it to the variables  
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

    lcd.setCursor(0,0); // setting the cursor at the top

    // printing the humidity values on the lcd
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print("%");

    lcd.setCursor(0,1); // setting the cursor at the bottom
    
    // printing the temperature values on the lcd
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print("C");

    //printing the temp & humidity values on serial monitor, used for troubleshooting 
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("  Temp: ");
    Serial.println(temperature);
}
