
#include "Arduino.h"

#define LIGHT_PIN 33

bool alertActive = false;
unsigned long lastCheckTime = 0;

void setup(void)
{
    Serial.begin(115200);
}

void loop(void)
{
    unsigned long currentTime = millis();

    if (currentTime - lastCheckTime >= 300UL)
    {
        lastCheckTime = currentTime;

        int reading = analogRead(LIGHT_PIN);

        if (!alertActive && reading > 3000)
        {
            alertActive = true;
            Serial.println("ALERT=1");
        }
        else if (alertActive && reading < 2500)
        {
            alertActive = false;
            Serial.println("ALERT=0");
        }
    }
}
