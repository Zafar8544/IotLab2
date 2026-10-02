
#include "Arduino.h"

#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN 14
#define BUTTON_PIN 25

const int ledPins[] = {
    RED_LED_PIN,
    GREEN_LED_PIN,
    YELLOW_LED_PIN,
    BLUE_LED_PIN
};

bool lastButtonState = LOW;
uint8_t counter = 0;

void updateLeds(void)
{
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);

    for (uint8_t i = 0; i < counter; ++i)
    {
        digitalWrite(ledPins[i], HIGH);
    }
}

void setup(void)
{
    Serial.begin(115200);

    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);

    updateLeds();
}

void loop(void)
{
    bool currentButtonState = digitalRead(BUTTON_PIN);

    if (currentButtonState == HIGH && lastButtonState == LOW)
    {
        counter = (counter + 1) % 5;
        updateLeds();
        Serial.print("count=");
        Serial.println(counter);
    }

    lastButtonState = currentButtonState;
}
