#include "PAMIBOARD.h"

#define LED_COMMON_ANODE false  // true pour anode commune, false pour cathode commune

// Structure pour représenter une couleur RGB
struct RGBColor {
    uint8_t r;  // Rouge (0-255)
    uint8_t g;  // Vert (0-255)
    uint8_t b;  // Bleu (0-255)
};

// Définition de couleurs prédéfinies
namespace Colors {
    const RGBColor _RED = {255, 0, 0};
    const RGBColor _GREEN = {0, 255, 0};
    const RGBColor _BLUE = {0, 0, 255};
    const RGBColor _WHITE = {255, 255, 255};
    const RGBColor _BLACK = {0, 0, 0};  // LED éteinte
    const RGBColor _YELLOW = {255, 255, 0};
    const RGBColor _CYAN = {0, 255, 255};
    const RGBColor _MAGENTA = {255, 0, 255};
    const RGBColor _ORANGE = {255, 128, 0};
    const RGBColor _PURPLE = {128, 0, 128};
    const RGBColor _PINK = {255, 192, 203};
}


// Configuration initiale des broches de la LED
void setup_LED() {
    pinMode(RGB::RED, OUTPUT);
    pinMode(RGB::GREEN, OUTPUT);
    pinMode(RGB::BLUE, OUTPUT);
}

// Définir la couleur de la LED
void setLEDColor(const RGBColor& color) {
    // Pour une LED à anode commune, la logique est inversée (0 = allumé, 255 = éteint)
    if (LED_COMMON_ANODE) {
        analogWrite(RGB::RED, 255 - color.r);
        analogWrite(RGB::GREEN, 255 - color.g);
        analogWrite(RGB::BLUE, 255 - color.b);
    } else {
        analogWrite(RGB::RED, color.r);
        analogWrite(RGB::GREEN, color.g);
        analogWrite(RGB::BLUE, color.b);
    }
}
