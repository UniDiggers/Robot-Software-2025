#ifndef PATHFINDING_H
#define PATHFINDING_H

#include <Arduino.h>

//Minimalist path finding algorithm (experimentation)

/*
Logic to go through the enemy :
- Create a matrix which represent the map
- One case of the matrix must be the size of the robot 
- Put the robots position in the matrix
- Fill the matrix with the obstacles
- Get sensor data to update the matrix
- Use the A* algorithm to find the path
*/


//Dimensions of the map (mm) 
#define TABLE_WIDTH 3000
#define TABLE_HEIGHT 2000

//Dimensions of the robot (mm)
#define ROBOT_WIDTH 150
#define ROBOT_HEIGHT 150

//Dimension of the matrix
#define MATRIX_WIDTH TABLE_WIDTH/ROBOT_WIDTH
#define MATRIX_HEIGHT TABLE_HEIGHT/ROBOT_HEIGHT

//Amount of obstacles
#define OBSTACLES 10

//Create the matrix
char matrix[MATRIX_WIDTH][MATRIX_HEIGHT];

void matrix_fill(char matrix[MATRIX_WIDTH][MATRIX_HEIGHT], int obstacles_x[OBSTACLES],int obstacles_y[OBSTACLES], char robot, char enemy, char obstacle, char path,char zone, int robot_x, int robot_y, int enemy_x, int enemy_y){
    
    //Fil with zone
    for(int i = 0; i < MATRIX_WIDTH; i++){
        for(int j = 0; j < MATRIX_HEIGHT; j++){
            matrix[i][j] = '-';
        }
    }
    //Fill the matrix with the obstacles
    for(int i = 0; i < OBSTACLES; i++){
        matrix[obstacles_x[i]][obstacles_y[i]] = obstacle;
    }
    //Fill the matrix with the robot
    matrix[robot_x][robot_y] = robot;

    //Fill the matrix with the enemy
    matrix[enemy_x][enemy_y] = enemy;
}

void matrix_setup(){
    
    //Position of the robot
    int robot_x = 0;
    int robot_y = 0;

    //Position of the enemy (unknown)
    int enemy_x = -1;
    int enemy_y = -1;

    //Symbol of elements in the matrix
    char robot = 'R';
    char enemy = 'E';
    char obstacle = 'X';
    char path = 'P';
    char zone = '-';

    //Position of the obstacles
    int obstacles_x[OBSTACLES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int obstacles_y[OBSTACLES] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //Fill the matrix with the obstacles
    matrix_fill(matrix, obstacles_x, obstacles_y, robot, enemy, obstacle,zone, path, robot_x, robot_y, enemy_x, enemy_y);
}



void matrice_print(char matrix[MATRIX_WIDTH][MATRIX_HEIGHT]){
    //Print the matrix
    Serial.println("\n");
    for(int i = 0; i < MATRIX_WIDTH; i++){
        for(int j = 0; j < MATRIX_HEIGHT; j++){
            Serial.print(matrix[i][j]);
        }
        Serial.println();
    }
}



#endif