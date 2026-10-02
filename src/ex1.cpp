


#include "Arduino.h"

#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN 14

const int chasePins[] = {
    RED_LED_PIN,
    GREEN_LED_PIN,
    YELLOW_LED_PIN,
    BLUE_LED_PIN,
    YELLOW_LED_PIN,
    GREEN_LED_PIN
};

const char *chaseNames[] = {
    "RED",
    "GREEN",
    "YELLOW",
    "BLUE",
    "YELLOW",
    "GREEN"
};

const uint8_t CHASE_STEP_COUNT = sizeof(chasePins) / sizeof(chasePins[0]);
uint8_t stepIndex = 0;

void setup(void)
{
    Serial.begin(115200);

    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);

    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
}

void loop(void)
{
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);

    digitalWrite(chasePins[stepIndex], HIGH);
    Serial.print("chase=");
    Serial.println(chaseNames[stepIndex]);

    stepIndex = (stepIndex + 1) % CHASE_STEP_COUNT;
    delay(150);
}
