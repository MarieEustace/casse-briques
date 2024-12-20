#include "game.h"
#include <time.h>
#include "variables.h"
#include "sdl_helper/function.h"
#include "sdl_helper/text_functions.h"
#include "sdl_helper/audio_functions.h"
#include "sdl_helper/constants.h"
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "check.h"
SDL_Texture *texturedragon;


void init_game(){ //initialisation variables
 nblives=5;
 nbbubbles=1;
 aBall=2;
 xproj=585;
 yproj=570;
 xpad=550;
 ypad=620;
 xmouse=2000;
 ymouse=2000;
 seconds=1;
 fpsline=0;
 fpsmusic=0;
 vx=0;
 vy=3;
 speedproj=1;
 m=0;
 aDragon=0;
 fpsmusic=0;
 fpsline=0;
 linecounter=0;
 switchrow=0;
 //initdragon();
}

int genbubbles(){ //generated bubbles depending on level
 printf ("\n");
    switch (level) {
      case 1 :
        colBbl=12;
        lineBbl=5;
        nbbubbles=78;
        savenbbubbles=nbbubbles;
        addline=0;
        saveaddline=addline;
          if (aMusic!=0){
            aMusic=1;
          }
      break;
      case 2 :
        colBbl=15;
        lineBbl=4;
        nbbubbles=80;
        savenbbubbles=nbbubbles;
        addline=0;
        saveaddline=addline;
          if (aMusic!=0){
            aMusic=2;
          }
      break;
      case 3 :
        colBbl=15;
        lineBbl=13;
        nbbubbles=80;
        savenbbubbles=nbbubbles;
        addline=9;
        saveaddline=addline;
        linedelay=400;
        saveaddline=addline;
        switchrow=0;
          if (aMusic!=0){
            aMusic=3;
          }
      break;
    }

  for (int j=0;j<=lineBbl;j++){
   for (int i=0;i<=colBbl;i++){
    if (level==1){
   colorbbl=3;
   }
    if (level==2){
    colorbbl=colorlvltwo;
        colorlvltwo+=1;
          if (colorlvltwo==4){
            colorlvltwo=0;
          }
    }
   if (level==3){
    colorbbl=rand()%4;
   }
   if (colorbbl==0){
    tabbubbles[j][i]=0;
    }
   else if (colorbbl==1){
    tabbubbles[j][i]=1;
    }
   else if (colorbbl==2){
    tabbubbles[j][i]=2;
    }
   else if (colorbbl==3){
    tabbubbles[j][i]=3;
    }
   }
  }
  for (int n=0;n<=lineBbl;n++){
   for (int o=0;o<=colBbl;o++){
    printf ("%d ", tabbubbles[n][o]);
   }
   printf ("\n");
  }
}

void colorProj(){ //random color projectile
  switch (level) {
      case 1 :
        colorproj=3;
      break;
      case 2 :
        colorproj=rand()%4;
      break;
      case 3 :
        colorproj=rand()%4;
      break;
    }
}

void background(){
  switch (level) {
      case 1 :
        sprite (0, 0, "background1.bmp");
          if (seconds%115==0){
           aMusic=1;
          }
      break;
      case 2 :
        sprite (0, 0, "background2.bmp");
          if (seconds%99==0){
           aMusic=2;
          }
      break;
      case 3 :
        sprite (0, 0, "background3.bmp");
          if (seconds%182==0){
           aMusic=3;
          }
      break;
    }
sprite (30, 20, "title.bmp");
  if (aBall==2){
       sprite (275, 300, "space.bmp");
  }
  //dragon();
}

void initdragon(){
    SDL_Surface *surfacedragon = SDL_LoadBMP("dragon.bmp");
    SDL_Texture *texturedragon = SDL_CreateTextureFromSurface(renderer,surfacedragon);
    SDL_FreeSurface(surfacedragon);
}

void dragon(){
  //sprite sheet 1120x1128 14x16
  changeColor(0,0,0, 255);
 // drawRect(75,500,100,100);
 switch (aDragon){
  case 1 : //x 4-13 + 1 y 12-13
    xdragon=280;
    ydragon=780;
    for (int i=0;i<=10;i++){
      spritesheet(xdragon, ydragon);
      if (fpsmusic%5==0){
        xdragon+=70;
          if (xdragon>=1120){
            ydragon+=70;
            xdragon=0;
          }
      }
    }
    xdragon=280;
    ydragon=780;
    break;
  case 2 : // x 2-7 y 13
    xdragon=130;
    ydragon=845;
    for (int i=0;i<=5;i++){
      spritesheet(xdragon, ydragon);
      if (fpsmusic%5==0){
        xdragon+=70;
      }
    }
    aDragon=1;
    break;
  case 3 : //x 13-16 + 1 y 8-9
    xdragon=910;
    ydragon=560;
    for (int i=0;i<=4;i++){
      spritesheet(xdragon, ydragon);
      if (fpsmusic%5==0){
        xdragon+=70;
          if (xdragon>=980){
            ydragon+=70;
            xdragon=0;
          }
      }
    }
    aDragon=1;
    break;
  case 4 : //x 2-10 (7-10 non-stop) y 7
    xdragon=140;
    ydragon=490;
    for (int i=0;i<=8;i++){
      spritesheet(xdragon, ydragon);
      if (fpsmusic%5==0){
        xdragon+=70;
          if (i==8){
            xdragon-=280;
            i-=4;
          }
      }
    }
    break;
 }
 freedragon(texturedragon);
}

int spritesheet(int xdragon, int ydragon){
    SDL_Rect src = {xdragon, ydragon, 70, 70};
    SDL_Rect dst = {80, 510, 70, 70};
    SDL_RenderCopy(renderer, texturedragon, &src, &dst);
    return 0;
}

void paddle(){
 sprite (xpad, ypad, "pad.bmp");
  if (goleft==1){
      if (xpad>=(posXleft+speedpad)){
        xpad=xpad-speedpad;
      }
  }
  else if(goright==1){
      if (xpad<=(posXright-(lpad+speedpad))){
        xpad=xpad+speedpad;
      }
  }
}

void lives(){
  int xlife=985;
  int ylife=625;
  changeColor(0,0,0, 255);
  drawRect ((xlife-6),(ylife-6),(34*5+28),(33+12));
  changeColor(229,217,214,255);
  drawRect ((xlife-4),(ylife-4),(34*5+24),(33+8));
    for (int i=0;i<=(nblives-1);i++){
      //drawSquare (xlife, ylife, 33);
      sprite (xlife, ylife, "life.bmp");
      xlife+=38;
    }
}

void proj(){ //projectile
 for (int j=0;j<=lineBbl;j++){
  for (int i=0;i<=colBbl;i++){
   if ((colorproj==1)&&(tabbubbles[j][i]==1)){
    sprite (xproj, yproj, "ylw.bmp");
   }
   if ((colorproj==2)&&(tabbubbles[j][i]==2)){
     sprite (xproj, yproj, "grn.bmp");
   }
   if ((colorproj==3)&&(tabbubbles[j][i]==3)){
     sprite (xproj, yproj, "blu.bmp");
   }
   if ((colorproj==0)&&(tabbubbles[j][i]==0)){
   sprite (xproj, yproj, "red.bmp");
   }
  }
 }
  if (aBall==3){
       sprite (500, 300, "pause.bmp");
  }
}

void bubbles(){ //bubbles spawning
 ybubble = 15;
    switch (level) {
      case 1 :
        xbubble=posXleft+80;
      break;
      case 2 :
        xbubble=posXleft;
      break;
      case 3 :
        xbubble=posXleft;
    if (m<linecounter){
      if (addline>=0){
        addline-=1;
        switchrow+=1;
        saveaddline=addline;
      }
    m+=1;
    }
      break;
    }

  for (addline;addline<=lineBbl;addline++){
    switch (level) {
      case 2 :
        if (addline%2==0){
          xbubble+=30;
        }
      break;
      case 3 :
        if ((switchrow%2==1)&&(addline%2==0)){
          xbubble+=30;
        }
        else if ((switchrow%2==0)&&(addline%2==0)){
          xbubble+=30;
        }
      break;
    }
    for (int i=0;i<=colBbl;i++){
      switch (tabbubbles[addline][i]){
        case 0 :
          sprite (xbubble, ybubble, "red.bmp");
        break;
        case 1 :
          sprite (xbubble, ybubble, "ylw.bmp");
        break;
        case 2 :
          sprite (xbubble, ybubble, "grn.bmp");
        break;
        case 3 :
          sprite (xbubble, ybubble, "blu.bmp");
        break;
      }
    xbubble=(dbubble+xbubble+2);
    }
    if (level==1){
      xbubble = posXleft+80;
    }
    else{
     xbubble=posXleft;
    }
   ybubble=(dbubble+ybubble+2);
  }
addline=saveaddline;

}

void speed(){ //movement projectile
   if (aBall==1){
      xproj+=(vx*speedproj);
      yproj+=(vy*speedproj);
      collisionpad();
      collisionbbl();
      collisionborders();
   }
}

void collisionborders(){
 if ((yproj<=0)&&(aBorder!=1)&&(vy<0)){
   vy*=-1;
   aBorder=1;
 }
 if ((xproj<=posXleft)&&(aBorder!=2)&&(vx<0)){
   vx*=-1;
   aBorder=2;
 }
 if ((xproj+dbubble>=posXright)&&(aBorder!=3)&&(vx>0)){
   vx*=-1;
   aBorder=3;
 }
 if (yproj+dbubble>=720){
    lost ();
    //vy*=-1;
  }
}

int collisionpad(){ //collision paddle
//top pad C to G
  if ((checktoppad()==1)&&(checklengthpad()==1)){
   aBorder=0;
   stuckbbl=0;
//C
    if (((xproj+dbubble-11)>=xpad)&&((xproj+1)<=(xpad+25))){
      vx=3;
        vx*=-1;
      vy=3;
        vy*=-1;
  }
//D
    else if (((xproj+dbubble-11)>=(xpad+25))&&((xproj+11)<=(xpad+60))){
      vx=1;
        vx+=(1/3);
        vx*=-1;
      vy=1;
      vy+=3;
      vy*=-1;
  }
//G
    else if (((xproj+dbubble-11)>=(xpad+125))&&((xproj+11)<=(xpad+lpad))){
      vx=-3;
        vx*=-1;
      vy=3;
        vy*=-1;
    }
//F
    else if (((xproj+dbubble-11)>=(xpad+90))&&((xproj+11)<=(xpad+125))){
      vx=1;
        vx+=(1/3);
      vy=1;
      vy+=3;
      vy*=-1;
  }
//E
    else if (((xproj+dbubble-1)>=(xpad+60))&&((xproj+11)<=(xpad+90))){
    vx=0;
    vy=3;
        vy*=-1;
  }
}
//B top left angle pad
  if (checkangleHGpad()==1){
   aBorder=0;
   stuckbbl=0;
      vx=1;
        vx+=3;
        vx*=-1;
      vy=1;
        vy+=(1/3);
        vy*=-1;
}
//H top right angle pad
  if (checkangleHDRpad()==1){
   aBorder=0;
   stuckbbl=0;
      vx=1;
        vx+=3;
      vy=1;
        vy+=(1/3);
        vy*=-1;
}
//A left pad
  if ((checkleftpad()==1)&&(checkheightpad()==1)){
   aBorder=0;
   stuckbbl=0;
      vx=1;
        vx+=3;
        vx*=-1;
      vy=1;
        vy+=(1/3);
        vy*=-1;
  }
//I right pad
  if ((checkrightpad()==1)&&(checkheightpad()==1)){
   aBorder=0;
   stuckbbl=0;
      vx=1;
        vx+=3;
      vy=1;
        vy+=(1/3);
        vy*=-1;
  }
}

int collisionbbl(){ //collision bubbles
 ybubble=15;
 switchrow=0; //inverted row shift lvl 3
    switch (level) {
      case 1 :
        xbubble = posXleft+80;
      break;
      case 2 :
        xbubble = posXleft;
      break;
      case 3 :
        xbubble = posXleft;
          if (m<linecounter){
            if (addline>=0){
              addline-=1;
              switchrow+=1;
              nbbubbles+=16;
              saveaddline=addline;
            }
          m+=1;
          }
      break;
    }

  for (addline;addline<=lineBbl;addline++){
    switch (level) {
      case 2 :
        if (addline%2==0){
          xbubble+=30;
        }
      break;
      case 3 :
        if ((switchrow%2==1)&&(addline%2==0)){
          xbubble+=30;
        }
        else if ((switchrow%2==0)&&(addline%2==0)){
          xbubble+=30;
        }
      break;
    }

  for (int i=0;i<=colBbl;i++){
    if (stuckbbl==10){
      colorProj();
      stuckbbl=0;
      printf ("switch proj color\n");
    }

     if ((checktopbbl()==1)&&(checklengthbbl()==1)){
        aBorder=0;
      if (tabbubbles[addline][i]==colorproj){
        supprbbl ();
        vy*=-1;
        tabbubbles[addline][i]=4;
      }
      else if ((tabbubbles[addline][i]!=colorproj)&&(tabbubbles[addline][i]!=4)){
        vy*=-1;
        stuckbbl+=1;
        printf ("%d", stuckbbl);
      }
     }
     else if ((checkbottombbl()==1)&&(checklengthbbl()==1)){
        aBorder=0;
      if (tabbubbles[addline][i]==colorproj){
        supprbbl ();
        vy*=-1;
        tabbubbles[addline][i]=4;
      }
      else if ((tabbubbles[addline][i]!=colorproj)&&(tabbubbles[addline][i]!=4)){
        vy*=-1;
        stuckbbl+=1;
      }
     }

     else if ((checkleftbbl()==1)&&(checkheightbbl()==1)){
        aBorder=0;
      if (tabbubbles[addline][i]==colorproj){
        supprbbl ();
        vx*=-1;
        tabbubbles[addline][i]=4;
      }
      else if ((tabbubbles[addline][i]!=colorproj)&&(tabbubbles[addline][i]!=4)){
        vx*=-1;
        stuckbbl+=1;
      }
     }
     else if ((checkrightbbl()==1)&&(checkheightbbl()==1)){
        aBorder=0;
      if (tabbubbles[addline][i]==colorproj){
        supprbbl ();
        vx*=-1;
        tabbubbles[addline][i]=4;
      }
      else if ((tabbubbles[addline][i]!=colorproj)&&(tabbubbles[addline][i]!=4)){
        vx*=-1;
        stuckbbl+=1;
        aBorder=0;
      }
     }

   xbubble=(dbubble+xbubble)+2;
  }
    if (level==1){
      xbubble = posXleft+80;
    }
    else{
    xbubble=posXleft;
    }
   ybubble=(dbubble+ybubble)+2;
  }
    addline=saveaddline;
    return nbbubbles;
}

int supprbbl(){ //bubble popped by proj
    aSound=3;
    nbbubbles-=1;
    stuckbbl=0;
    colorProj();
    aDragon=2;
}

void music(){
     switch (aMusic){
      case 1 :
       audioLoadAndPlay("level1.wav", 1);
       aMusic=0;
      break;
      case 2 :
       audioLoadAndPlay("level2.wav", 1);
       aMusic=0;
      break;
      case 3 :
       audioLoadAndPlay("level3.wav", 1);
       aMusic=0;
      break;
      case 4 :
       audioLoadAndPlay("menu.wav", 1);
       aMusic=-2;
      break;
      case 5 :
       audioLoadAndPlay("gameover.wav", 1);
       aMusic=-1;
      break;
      case 6 :
       audioLoadAndPlay("won.wav", 1);
       aMusic=-1;
      break;
   }
    switch (aSound){
      case 1 :
        audioLoadAndPlay("press.wav", 2);
        aSound=0;
        break;
      case 2 :
        audioLoadAndPlay("lost.wav", 2);
        aSound=0;
        break;
      case 3 :
        audioSimpleLoadAndPlay("pop.wav");
        aSound=0;
        break;
    }
}

void timer(){
  if (aStart==1){
      fpsmusic+=1;
    if (fpsmusic%40==0){
        seconds+=1;
    }
  }
  if ((level==3)&&(aBall==1)){
      fpsline+=1;
      if ((fpsline%linedelay==0)&&(linecounter<=8)){
        linecounter+=1;
      }
    }
}

void menu(){
 if(aMenu==1){
    if (aMusic!=-2){
      aMusic=4;
    }
    sprite (0, 0, "backgroundmenu.bmp");
    sprite (180, 20, "titlemenu.bmp");
    sprite (320, 500, "start.bmp");
    sprite (680, 500, "exit.bmp");
  if ((xmouse>=320)&&(xmouse<=550)&&(ymouse>=500)&&(ymouse<=680)){
    audioLoadAndPlay("press.wav", 2);
    aLevel=1;
  }
  if ((xmouse>=680)&&(xmouse<=900)&&(ymouse>=500)&&(ymouse<=680)){
    aExit=1;
  }
  if (aExit==1){
    freeAndTerminate();
  }
 }
}

void selectLevel(){ //level selection screen
  if (aLevel==1){
   sprite (0, 0, "backgroundmenu.bmp");
   sprite (180, 20, "titlemenu.bmp");
   sprite (350, 430, "level.bmp");
   sprite (250, 510, "123.bmp");
  if ((xlevel>=200)&&(xlevel<=300)&&(ylevel>=525)&&(ylevel<=585)){
      level=1;
  }
  if ((xlevel>=500)&&(xlevel<=600)&&(ylevel>=525)&&(ylevel<=585)){
      level=2;
  }
  if ((xlevel>=850)&&(xlevel<=950)&&(ylevel>=525)&&(ylevel<=585)){
      level=3;
  }
  if (level>=1){
    aSound=1;
    levelLauncher();
  }
 }
}

void levelLauncher(){ //level selected
  aStart=1;
  aLevel=0;
  aMenu=0;
  xlevel=2000;
  ylevel=2000;
  aDragon=1;
  colorProj();
  genbubbles();
}

void start(){ //game launched
  if (aStart==1){
     timer();
     background();
     lives();
     proj();
     paddle();
     speed();
     bubbles();
  }
}

int lost(){ //lost life
  nblives-=1;
    if (nblives>=1){
      aSound=2;
    }
  xproj=585;
  yproj=570;
  aBall=0;
  aBorder=0;
  vx=0;
  vy=3;
  aDragon=3;
  return nblives;
}

void end(){ //game ended
 if ((nblives==0)||(nbbubbles==0)){
    background();
    lives();
    aDragon=4;
    //dragon();
    aBall=0;
    sprite (376, 400, "tryagain.bmp");
    sprite (471, 550, "menu.bmp");
   if (nblives==0){
     if (aMusic!=-1){
        aMusic=5;
     }
      sprite (242, 150, "gameover.bmp");
   }
   if (nbbubbles==0){
     if (aMusic!=-1){
       aMusic=6;
     }
      sprite (320, 150, "won.bmp");
   }

  if ((xmouse>=370)&&(xmouse<830)&&(ymouse>=400)&&(ymouse<=480)){
    resetlvl();
  }
  if ((xmouse>=640)&&(xmouse<=900)&&(ymouse>=550)&&(ymouse<=640)){
      aSound=1;
      level=0;
      aMenu=1;
      aStart=0;
      init_game();
  }
 }
}

void resetlvl(){
    aSound=1;
    init_game();
    addline=saveaddline;
    nbbubbles=savenbbubbles;
    levelLauncher();
}
