#include <Arduino.h>
//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_AHTX0.h>
#include <Fonts/FreeSans9pt7b.h>


LiquidCrystal_I2C lcd =  LiquidCrystal_I2C(0x3F,20,4);
Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(115200);
  //while (!Serial);
    
    lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("                                                                                                                    ");
  Serial.println("Display humedad y temp.");
  if (aht.begin()) {
    Serial.println("Found AHT20");
  } else {
    Serial.println("Didn't find AHT20");
  }  


}

void loop() {
  //display.clearDisplay();
  sensors_event_t humidity, temp;
  
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data

  lcd.setCursor(7,0);
  lcd.print("AHT10");
  lcd.setCursor(3,1);
  lcd.print("Temp: "); 
  lcd.print(String(temp.temperature)); 
  lcd.print(" C");
  lcd.setCursor(4,2);
  lcd.print("Hum: "); 
  lcd.print(String(humidity.relative_humidity)); 
  lcd.print(" %");
  Serial.print("Temperature: ");Serial.print(temp.temperature);Serial.println(" degrees C");
  Serial.print("Pressure: ");Serial.print(humidity.relative_humidity);Serial.println(" RH %");
  
  delay(1000);
}
