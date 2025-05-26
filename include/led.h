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
    const RGBColor RED = {255, 0, 0};
    const RGBColor GREEN = {0, 255, 0};
    const RGBColor BLUE = {0, 0, 255};
    const RGBColor WHITE = {255, 255, 255};
    const RGBColor BLACK = {0, 0, 0};  // LED éteinte
    const RGBColor YELLOW = {255, 255, 0};
    const RGBColor CYAN = {0, 255, 255};
    const RGBColor MAGENTA = {255, 0, 255};
    const RGBColor ORANGE = {255, 128, 0};
    const RGBColor PURPLE = {128, 0, 128};
    const RGBColor PINK = {255, 192, 203};
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

// Configuration initiale des broches de la LED
void setup_LED() {
    pinMode(RGB::RED, OUTPUT);
    pinMode(RGB::GREEN, OUTPUT);
    pinMode(RGB::BLUE, OUTPUT);

    // Initialiser la LED à éteinte
    setLEDColor(Colors::BLACK);

    Serial.println("LED setup complete");
}


