#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX pins for HC-05
int sensorVal;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(8, OUTPUT); // Piezo buzzer output pin
  pinMode(13, OUTPUT); // LED output pin
  tone(8, 360, 50);
  tone(13, 720, 100);
}

void loop() {
  if (BTSerial.available()) {
    sensorVal = BTSerial.parseInt(); // Read sensor value from master over Bluetooth
    Serial.println(sensorVal);

    /*if (sensorVal == 0) {
      noTone(8); // Stop tone on pin 8
    } else {
      tone(13, 80, 160); // Play tone on pin 8
    }*/

    if(sensorVal==0)
    noTone(8);//,18,50);
  else
    digitalWrite(8,1);
  
  if(sensorVal!=1)  
    tone(13,80,160);

    delay(100);
  }
}
