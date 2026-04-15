#include <Arduino.h>
#include "ultrasonic.h"

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  ultrasonic_init(8, 9); // trig, echo
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);

  float distance = ultrasonic_getDistanceCM();

  Serial.print("Distance in cm: "); Serial.println(distance);
}