#include "ultrasonic.h"

// Static variables to store pin configuration
static uint8_t _trigPin;
static uint8_t _echoPin;

void ultrasonic_init(uint8_t trigPin, uint8_t echoPin) {
    _trigPin = trigPin;
    _echoPin = echoPin;

    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}

float ultrasonic_getDistanceCM() {
    // Ensure trigger LOW
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);

    // Send 10us pulse
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);

    // Measure echo time
    long duration = pulseIn(_echoPin, HIGH);

    // Convert to cm
    float distance = duration * 0.0343 / 2.0;  // duration times speed of sound in cm per microsecond

    return distance;
}