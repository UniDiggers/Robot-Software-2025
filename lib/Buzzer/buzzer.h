#include <Arduino.h>

#include "QuentbinksBoard.h"

static const int ringtoneBip = 3;
static const int notifBip = 2;

class Buzzer
{
private:
    int buzzerPin = PIN::BUZZER;

public:
    Buzzer(int buzzerPin = PIN::BUZZER);
    void ringtoneBLE();
    void notifBLE();
    void bip(int bipNbr, int _delay);
};