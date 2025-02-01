#ifndef BLE_H
#define BLE_H

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <math.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

String texte;

extern Movement movement;
extern Buzzer buzzer1;

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

typedef struct
{
  int position[2];
  int vitesse;
  int acceleration;
  bool reception;
} BLE_param;

BLE_param parameter;

BLE_param transcript(String texte)
{
  // Position M1
  int position = (texte.substring(0, 2)).toInt();
  position = position * pow(10, (texte[2] - '0'));
  Serial.print("Position M1 = ");
  Serial.println(position);
  movement.moveBy(0, position);
  parameter.position[0] = position;

  // Position M2
  position = (texte.substring(3, 5)).toInt();
  position = position * pow(10, (texte[5] - '0'));
  Serial.print("Position M2 = ");
  Serial.println(position);
  movement.moveBy(1, position);
  parameter.position[1] = position;

  // Vitesse
  position = (texte.substring(6, 8)).toInt();
  position = position * pow(10, (texte[8] - '0'));
  Serial.print("Vitesse = ");
  Serial.println(position);
  parameter.vitesse = position;

  // Accélération
  int acceleration = (texte.substring(9, 11)).toInt();
  acceleration = acceleration * pow(10, (texte[11] - '0'));
  Serial.print("Accélération = ");
  Serial.println(acceleration);
  parameter.acceleration = acceleration;

  // Réception
  parameter.reception = true;
  return parameter;
}

class MyCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic)
  {
    std::string value = pCharacteristic->getValue().c_str();

    if (value.length() > 0)
    {
      texte = "";
      for (int i = 0; i < value.length(); i++)
      {
        texte = texte + value[i];
      }
      buzzer1.notifBLE();
      Serial.print("Reçu = ");
      Serial.println(texte);
      transcript(texte);
    }
  }
};

void setup_BLE()
{
  Serial.begin(115200);

  BLEDevice::init("ESP32-S3");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  BLECharacteristic *pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_WRITE);

  pCharacteristic->setCallbacks(new MyCallbacks());
  pCharacteristic->setValue("Initialisation.");
  pService->start();

  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
}

#endif