#include "screen.h"

// Fonction pour afficher un bitmap sur l'écran
// Ensure the u8g2 object is properly initialized
void Screen::displayBitmap(const uint8_t *bitmap) {
    u8g2.firstPage();
    do {
        u8g2.drawXBMP(0, 0, ScreenWidth, ScreenHeight, bitmap); // Affiche l'image à partir de (0, 0)
    } while (u8g2.nextPage());
}

// Fonction d'initialisation de l'écran
bool Screen::setup() {
    if (!u8g2.begin()) { // Initialisation de l'écran
        Serial.println("Screen not detected.");
        return false; // Si l'écran n'est pas détecté, on retourne false
    } else {
        u8g2.clearBuffer(); // Efface le buffer
        u8g2.setFont(u8g2_font_ncenB08_tr); // Définit une police (optionnel)
        displayBitmap(home); // Affiche le bitmap
        u8g2.sendBuffer(); // Envoie le contenu au buffer
        return true;
    }
}



