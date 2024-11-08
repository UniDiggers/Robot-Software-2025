#ifndef STEPPER_H
#define STEPPER_H

#include <AccelStepper.h>
#include <Arduino.h>

// Définition des pins du moteur
#define STEP1 13
#define DIR1 14
#define STEP2 12
#define DIR2 16
#define STEP3 11
#define DIR3 15

// Création des objets AccelStepper
AccelStepper stepper1(1, STEP1, DIR1);
AccelStepper stepper2(1, STEP2, DIR2);
AccelStepper stepper3(1, STEP3, DIR3);

void nema_setup(AccelStepper &stepper, int SPEED, int MAX_SPEED, int ACCELERATION){
  // Initialisation du moteur
  stepper.setSpeed(SPEED); // Vitesse du moteur en pas par seconde
  stepper.setMaxSpeed(MAX_SPEED);   // Vitesse maximale du moteur en pas par seconde
  stepper.setAcceleration(ACCELERATION); // Accélération du moteur en pas par seconde²
}

void nema_position(AccelStepper &stepper, int POSITION){
  // Déplacement du moteur vers l'avant
  //stepper.moveTo(POSITION);
  stepper.move(POSITION);
}

void nema_start(AccelStepper &stepper, AccelStepper &stepper1){
  // Lancement des moteurs 
  while(stepper.distanceToGo() != 0 || stepper1.distanceToGo() != 0){
    delay(10);
    stepper.run();
    stepper1.run();
  }
}

#endif