#include <M5Stack.h>
#include <HCSR04.h> // 2～400cmまで取れる

// triggerPinをpin2につなぎます
// echoPinをpin5につなぎます
UltraSonicDistanceSensor distanceSensor(2, 5);

int lcdDisplayCount = 0;

bool lcdDisplayMax(){
  if(lcdDisplayCount >= 30){ 
    return true;
  }else{
    return false;
  }
}

void lcdDisplayReset(){
  M5.Lcd.fillScreen(0x0);
  M5.Lcd.setCursor(0, 0);
  lcdDisplayCount = 0;
  return;
}



// the setup routine runs once when M5Stack starts up
void setup(){
  // Initialize the M5Stack object
  M5.begin();
  Serial.begin(9600);
  Wire.begin();
}

// the loop routine runs over and over again forever
void loop() {
  double distance = distanceSensor.measureDistanceCm();
  if( distance >= 0.0){
    if(lcdDisplayMax()==true){
      lcdDisplayReset();
    }
    M5.Lcd.println(distance);
    Serial.println(distance);
    lcdDisplayCount++;
  }
  delay(1000);
}
