#ifndef QUENTBINKSBOARD_H
#define QUENTBINKSBOARD_H

namespace PIN
{
    namespace Steppers
    {
        constexpr int
            STEP1 = 13,
            STEP2 = 12,
            STEP3 = 11,

            DIR1 = 14,
            DIR2 = 16,
            DIR3 = 15;
    }

    namespace I2C
    {
        constexpr int
            SDA = 1,
            SCL = 2;
    }

    constexpr int
        BUZZER = 5,
        TIR = 6,
        TEAM = 7;
}

#endif