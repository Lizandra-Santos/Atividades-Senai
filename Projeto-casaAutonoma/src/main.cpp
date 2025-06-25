#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>

WiFiClientSecure espClient;
PubSubClient mqtt(espClient);
LiquidCrystal_I2C lcd (0x27,20,4);
Adafruit_NeoPixel led(1,48,NEO_GBR);
JsonDocument doc;



void setup() 
{
 
}

void loop() 
{
 

}
