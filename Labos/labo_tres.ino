
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int pinLM35 = A0;     
const float Vref = 5.0;     

void setup() {
  Serial.begin(9600);

  delay(250);
  display.begin(i2c_Address, true);
  display.clearDisplay();
  display.display();
}

void loop() {
  int lectura = analogRead(pinLM35);            
  float voltaje = lectura * (Vref / 1023.0);    
  float tempC   = voltaje * 100.0;              

  Serial.print("Temperatura: ");
  Serial.print(tempC, 2);
  Serial.println(" °C");

  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);

  display.setCursor(0, 28);
  display.println("Temperatura:");

  display.setTextSize(2);           
  display.setCursor(0, 42);
  display.print(tempC, 1);
  display.println(" C");

  display.display();     
  display.clearDisplay();

  delay(1000);