#include <M5Stack.h>
#include <HCSR04.h>

// triggerPinをpin2につなぎます
// echoPinをpin5につなぎます
UltraSonicDistanceSensor distanceSensor(2, 5);

// the setup routine runs once when M5Stack starts up
void setup(){
  // Initialize the M5Stack object
  M5.begin();
  Wire.begin();
  // LCD display
  M5.Lcd.printf("hello world");
}

// the loop routine runs over and over again forever
void loop() {
  M5.Lcd.println(distanceSensor.measureDistanceCm());
  Serial.println("Testing DHT12 lib:");
  delay(500);
}
