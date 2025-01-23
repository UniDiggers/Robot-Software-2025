#include "buzzer.h"

Buzzer::Buzzer(int _buzzerPin)
{
    buzzerPin = _buzzerPin;
    pinMode(_buzzerPin, OUTPUT);
}

void Buzzer::ringtoneBLE()
{
    bip(ringtoneBip, 100);
}

void Buzzer::notifBLE()
{
    bip(ringtoneBip, 50);
}

void Buzzer::bip(int bipNbr, int _delay)
{
    for (int i = 0; i < bipNbr; i++)
    {
        digitalWrite(buzzerPin, HIGH);
        delay(_delay);
        digitalWrite(buzzerPin, LOW);
        delay(_delay);
    }
}