#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>

#pragma once //lis une seule fois le fichier au début

void init_game();

int genbubbles ();
void colorProj();

void background();
void initdragon();
void dragon();
int spritesheet();
void paddle();
void lives ();
void proj();
void bubbles ();

void speed ();
void collisionborders();
int collisionpad();
int collisionbbl();
int supprbbl();

void timer();
void music();
void menu();
void selectLevel();
void levelLauncher();
void start();
int lost();
void end();
void resetlvl();
