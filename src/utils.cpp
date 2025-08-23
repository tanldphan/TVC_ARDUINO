#include <Arduino.h>

bool initializer(const char *name, bool (*initee)())
{
    if (!initee())
    {
        Serial.printf("%s failed to start./n", name);
        return false;
    }
    Serial.printf("%s started successfully", name);
    return true;
}