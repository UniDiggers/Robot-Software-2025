Bienvenue sur la documentation des robots PAMI de l'équipe RATP Unimakers ! 🤖

# Qu’est-ce qu’un robot PAMI ?

PAMI ou Petit Actionneur Mobile Indépendant, est un petit robot autonome qui vient collaborer avec le robot principal. Il est possible d’en posséder plusieurs tant qu’ils rentrent dans une zone de 45 cm et 15cm.

# Quel est l’objectif ?

Cette année, le thème est Show must go on, ce qui impose 2 rôles :

Le PAMI Rockstar, qui va monter sur la scène via une rampe. C’est un robot qui doit être différent des autres et doit être seul sur scène. Plus il s’avance sur scène, plus il gagne de point en faisant attention de ne pas tomber.

Le PAMI Groupie, lui, doit se positionner en fosse pour valider des zones et gagner des points. Un robot PAMI ne peut valider qu' une seule zone.

Tous les robots PAMI, à la fin de la partie, doivent faire la fête pour gagner des points supplémentaires.

Les difficultés de ces parties sont de monter la rampe, de s’avancer sur la scène sans tomber et de valider des zones sans se faire bloquer par l'équipe adverse qui a exactement le même objectif.

# Les objectifs pour l'édition 2025

Création d’une carte électronique ESP32-S3 pour contrôler les moteurs et les différents composants.

Utilisation du moteur pas à pas NEMA 17.

Nouveau type de capteur de distance, capteur ToF (Time Of Flight).

Placement d’un écran OLED pour afficher des informations.

Capable de jouer des fichiers audio.

Instaurer une connectivité entre les robots via BLE (Bluetooth Low Energy) et créer un protocole de communication standardisé.

Utilisation d’actionneurs de type servomoteur SG90 pour effectuer des mouvements.

Code structuré et standardisé avec celui du robot principal. Utilisation des classes et de librairies personnalisées.

Placement automatique sur la table.

# En cours 

## Mécanique

Le Robot PAMI possède de grosses roues pour gagner en adhérence et monter facilement à la rampe de la scène.

Il est optimisé pour utiliser le moins possible de vis et gagner du temps dans les changements ou les réparations.

Il est robuste, c'est à dire capable d'encaisser plusieurs contacts sans casser.


## Carte électronique 

La carte est presque terminée, une première version a été essayée mais n’était pas ergonomique. Une seconde plus adaptée au robot a été fabriquée et fonctionne parfaitement pour les objectifs fixés mais ne possède aucune sécurité dans le circuit et manque de polyvalence. Une troisième est en cours de conception avec toutes les protections adaptées et une meilleure polyvalence pour les utilisations futures.


![Image](assets/Doc/schema_pcb.png)

Alimentation via une batterie externe pour téléphone permettant une tension de 5V et un courant de 3A.

Fonctionnalités :
- Buzzer
- UART x2
- Built-in RGB LED
- Contrôle I²C : capteur ToF / écran OLED
- Contrôle de 2 moteurs pas à pas (NEMA 17)
- Contrôle jusqu'à 7 servomoteurs (SG90)
- Boutons BOOT/RESET
- Bouton d'arrêt d'urgence (BAU)
- Protection ESD
- Protection contre court-circuits (Fusible réarmable)
- Contrôle DFPlayer mini

Réalisation de la carte électronique avec KiCad.
https://github.com/TiTooom/PCBetes

## Code

Tous les composants évoqués précédemment sont déjà codés dans des librairies personnalisées sauf la lecture des fichiers audio qui est en cours de programmation. Mais rien n’est encore utilisé car le déroulement d’une partie n’a pas été pensé pour le moment.

La stratégie doit encore être pensée puis les fonctions seront appelées au bon moment afin de suivre les étapes de la stratégie.

Standardisation du code entre le robot principal et les PAMIs. Afin de corriger les problèmes facilement sur tous les robots en même temps.

<p align="center">
    <img src="assets/Screen/home.png" alt="Image">
</p>
Affichage des informations essentielles pendant le match, telles que :

- La distance de l'obstacle
- Le timer
- L'équipe actuelle
- et d'autres informations pour du debug

### Buzzer

Contrôle des sons.

### DFPlayer (MP3)

Capacité de jouer des audios.

### Movement

Possibilité de contrôler les moteurs. 
De manière indépendante ou non. 
Contrôle des trajectoires en fonction de la direction l'angle et la vitesse.

### Screen

Affichage d'informations sur l'écran en temps réel. 

### Servo

Contrôle des actionneurs via les servomoteurs (ici SG90).

### Strategy

Rédaction d'un stratégie sous forme de liste qui sera executé tout au long de la partie

### Timer

Respect des temps clés de la partie, mise en place des interruptions. Repère temporel

### TOF

Récupération des distances via un capteur ToF (Time Of Flight).
Plusieurs modes de fonctionnement à ajuster en fonction des besoins de la partie.

### BLE (Bluetooth Low Energy)

Contrôle du robot à distance avec un smartphone.

### ESPNow

Protocole de communication inter-PAMI/Robot pour s'échanger des informations comme quand démarrer les robots, l'équipe actuelle ou les obstacles détectés.


## Stratégie

Il y aura 4 robots PAMI, nommés respectivement :
Blue, Delta, Echo et Charlie. 

Chacun possède un rôle précis dans la partie :

# Blue

C'est le PAMI Rockstar, son objectif est de monter sur scène en empruntant une rampe et s'avance le plus possible sur scène afin de remporter le plus de point. Il fait bouger des actionneurs pour entrainer la foule.

# Charlie

C'est un robot PAMI de provocation, il consiste à se diriger très rapidement vers l'équipe adverse en emprunter des courbes optimisées. Son rôle est de gagner des points dans la zone la plus éloignée en empêchant l'adversaire d'avancer. Il s'arrête dès qu'il détecte un ennemi pour éviter les dégats et pour respecter les règles.

# Delta & Echo

Ce sont des PAMIs de type "suiveur", leur objectif va être de suivre "Charlie" de manière sécurisée en s'assurant de valider les zones les plus proches. Ils sont plus dans la précision que dans la vitesse.

Ces 4 robots vont possèder rigoureusement le même code. Le début de celui-ci vient récupérer l'adresse MAC de chaque robot pour s'adpater au rôle de chacun.

A la fin, tous les robots PAMIs vont faire bouger des actionneurs pour valider d'autres points et ainsi augmenter le score de l'équipe.

## A faire 

Terminer la 3eme version de la carte et l’envoyer en production.
Élaborer une stratégie et composer le code en fonction de celle-ci.
Terminer la mécanique du robot pour la rendre plus belle et plus facile à monter/démonter.
Faire 3 autres fois le même robot.
Si le temps, faire des boîtes de transport.
