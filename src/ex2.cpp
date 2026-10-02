
#include "Arduino.h"

#define LIGHT_PIN 33

const uint8_t SAMPLE_COUNT = 10;
unsigned long lastSampleTime = 0;

void setup(void)
{
    Serial.begin(115200);
}

void loop(void)
{
    unsigned long currentTime = millis();

    if (currentTime - lastSampleTime >= 1000UL)
    {
        lastSampleTime = currentTime;

        int minValue = 4095;
        int maxValue = 0;
        long sum = 0;

        for (uint8_t i = 0; i < SAMPLE_COUNT; ++i)
        {
            int sample = analogRead(LIGHT_PIN);
            if (sample < minValue)
            {
                minValue = sample;
            }
            if (sample > maxValue)
            {
                maxValue = sample;
            }
            sum += sample;
        }

        int average = static_cast<int>(sum / SAMPLE_COUNT);

        Serial.print("min=");
        Serial.print(minValue);
        Serial.print(" max=");
        Serial.print(maxValue);
        Serial.print(" avg=");
        Serial.println(average);
    }
}
