#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define RADIO_1 7
#define RADIO_2 8

#define MOTOR1_PIN1 2
#define MOTOR1_PIN2 3
#define MOTOR2_PIN1 4
#define MOTOR2_PIN2 5

#define SPEED_PIN_1 9
#define SPEED_PIN_2 10

#define BUTTON 8

RF24 radio(RADIO_1, RADIO_2); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
boolean buttonState = 0;

void setup() {
    Serial.begin(9600);
    
    pinMode(MOTOR1_PIN1, OUTPUT);
    pinMode(MOTOR1_PIN2, OUTPUT);
    pinMode(MOTOR2_PIN1, OUTPUT);
    pinMode(MOTOR2_PIN2, OUTPUT);
    pinMode(SPEED_PIN_1, OUTPUT);
    pinMode(SPEED_PIN_2, OUTPUT);
    pinMode(BUTTON, INPUT);

    radio.begin();
    radio.openWritingPipe(addresses[0]); // 00001
    radio.openReadingPipe(1, addresses[1]); // 00002
    radio.setPALevel(RF24_PA_MIN);
}

void loop() {

    digitalWrite(MOTOR1_PIN1, HIGH);
    digitalWrite(MOTOR1_PIN2, LOW);

    digitalWrite(MOTOR2_PIN1, HIGH);
    digitalWrite(MOTOR2_PIN2, LOW);

    delay(5);

    // radio.startListening();

    // if ( radio.available()) {
    //     while (radio.available()) {
    //         int angleV = 0;
    //         radio.read(&angleV, sizeof(angleV));
    //         // TODO: output to speed pins instead.

    //         digitalWrite(MOTOR1_PIN1, HIGH);
    //         digitalWrite(MOTOR1_PIN2, LOW);

    //         digitalWrite(MOTOR2_PIN1, HIGH);
    //         digitalWrite(MOTOR2_PIN2, LOW);
    //     }

    //     delay(5);

    //     radio.stopListening();
    //     buttonState = digitalRead(BUTTON);
    //     radio.write(&buttonState, sizeof(buttonState));
    // }
}