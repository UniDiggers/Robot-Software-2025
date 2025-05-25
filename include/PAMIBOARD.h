#ifndef PAMIBOARD_H
#define PAMIBOARD_H

namespace Steppers
{
    constexpr uint8_t
        EN = 21, // 0 = EN / 1 = DISABLE

        STEP1 = 35,
        STEP2 = 37,

        DIR1 = 36,
        DIR2 = 38;
}

namespace UART
{
    constexpr uint8_t
        RX_0 = 44,
        TX_0 = 43,
        
        RX_1 = 18,
        TX_1 = 19;
        
}

namespace I2C
{
    constexpr uint8_t
        SDA = 1,
        SCL = 2;
}

namespace ToF
{
    constexpr uint8_t
        XSHUT1 = 47,
        READY1 = 10, // ready to make a mesure
        
        XSHUT2 = 48,
        READY2 = 8, // ready to make a mesure

        XSHUT[] = {XSHUT1, XSHUT2},
        READY[] = {READY1, READY2};
}

namespace SERVOS
{
    constexpr uint8_t
        SERVO1 = 5,
        SERVO2 = 9,
        SERVO3 = 4,
        SERVO4 = 16, //PWM
        SERVO5 = 15, //PWM
        SERVOS[] = {SERVO1, SERVO2, SERVO3, SERVO4, SERVO5};
}


namespace RGB // wrong order with colors
{
    constexpr uint8_t
        BLUE= 11,
        GREEN = 13,
        RED = 12;
        
}

namespace EYES
{
    constexpr uint8_t
        EYES = 14; //PWM
}

namespace STATE
{
    constexpr uint8_t
        TIR = 6,
        TEAM = 7;
}


#endif