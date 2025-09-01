#include <Arduino.h>

bool initializer(const char *name, bool (*initee)())
{
    if (!initee())
    {
        Serial.printf("%s init FAILED!\n", name);
        return false;
    }
    Serial.printf("%s init OK!\n", name);
    return true;
}