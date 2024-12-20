#include "variables.h"

const int posXleft=250;
const int posXright=950;
const int radius=20;
const int dbubble=40;
const int lpad=150;
const int hpad=25;
const int ldragon=63;
//positions différents éléments
float xproj;
float yproj;
int xpad;
int ypad;
int speedpad=25;
int xbubble;
int ybubble;
int xlife;
int ylife;
int xmouse;
int ymouse;
int xlevel;
int ylevel;
int xdragon;
int ydragon;
// souris et touches
int aBall=2;
int aMenu=1;
int aExit=0;
int aStart=0;
int aLevel=0;
int aBorder=0;
int aMusic=4;
int aSound=0;
int aDragon;
int goleft=0;
int goright=0;
// génération briques, couleurs, vies, niveau
int level;
int colorproj;
int tabbubbles[14][16];
int lineBbl=15;
int colBbl=4;
int nbbubbles;
int savenbbubbles;
int colorbbl;
int colorlvltwo;
int stuckbbl;
int check;
int nblives;
int fpsmusic;
int fpsline;
int linedelay;
int addline; //index nb lignes bubbles (0 pour 1 et 2, 9-- pour 3)
int saveaddline;
int switchrow; //décalage bulles lvl 3
int m;
int linecounter;
int seconds;
int secondsmenu;
int secondslevel;

//calcul vitesse et angle proj
float speedproj=1;
float vx;
float vy;

