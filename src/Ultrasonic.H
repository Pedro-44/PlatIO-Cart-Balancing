#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

void ultrasonic_init(uint8_t trigPin, uint8_t echoPin);
float ultrasonic_getDistanceCM();

#endif