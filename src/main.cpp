#include <Arduino.h>

#define MOTOR1_PIN1 2
#define MOTOR1_PIN2 3

#define MOTOR2_PIN1 4
#define MOTOR2_PIN2 5

void setup() {
    Serial.begin(9600);
    
    pinMode(MOTOR1_PIN1, OUTPUT);
    pinMode(MOTOR1_PIN2, OUTPUT);

    pinMode(MOTOR2_PIN1, OUTPUT);
    pinMode(MOTOR2_PIN2, OUTPUT);
}

void loop() {
    digitalWrite(MOTOR1_PIN1, HIGH);
    digitalWrite(MOTOR1_PIN2, LOW);

    digitalWrite(MOTOR2_PIN1, HIGH);
    digitalWrite(MOTOR2_PIN2, LOW);
}