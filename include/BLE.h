#ifndef BLE_H
#define BLE_H

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

String texte;

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class MyCallbacks: public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) {
      std::string value = pCharacteristic->getValue().c_str();
     
	  if (value.length() > 0) {
        texte = "";
        for (int i = 0; i < value.length(); i++){
          texte = texte + value[i];
        }
        Serial.print("texte = ");
        Serial.println(texte); 
      }
    }
};

void setup_BLE() {
  Serial.begin(115200);

  BLEDevice::init("ESP32-S3");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
                                         CHARACTERISTIC_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristic->setCallbacks(new MyCallbacks());
  pCharacteristic->setValue("Initialisation.");
  pService->start();

  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
}

#endif