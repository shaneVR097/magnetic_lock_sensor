#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX pins for HC-05

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(2, INPUT); // Assuming sensor is connected to pin 2
}

void loop() {
  int sensorVal = digitalRead(2);
  BTSerial.println(sensorVal); // Send sensor value over Bluetooth
  delay(100);
}
