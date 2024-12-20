#include "variables.h"

//collision bubbles

int checklengthbbl(){
  if (((xproj+dbubble)>=(xbubble))&&((xproj)<=(xbubble+dbubble))){
    return 1;
  }  else {return 0;}
}

int checkheightbbl(){
   if (((yproj+dbubble)>=(ybubble+15))&&((yproj)<=(ybubble+dbubble-15))){
    return 1;
  }  else {return 0;}
}

int checktopbbl(){ //collision proj top bubble
  if (((yproj+dbubble)>=(ybubble))&&(vy>=0)
    &&
  (yproj<=(ybubble))
  ){
    return 1;
  }  else {return 0;}
}

int checkbottombbl(){ //collision proj bottom bubble
    if ((yproj<=(ybubble+dbubble))&&(vy<=0)
      &&
    ((yproj+dbubble)>=(ybubble+dbubble))
    ){
    return 1;
  }  else {return 0;}
}

int checkleftbbl(){ //collision proj left bubble
    if (((xproj+dbubble)>=xbubble)&&(vx>=0)
      &&
    (xproj<=(xbubble))
    ){
    return 1;
  }  else {return 0;}
}

int checkrightbbl(){ //collision proj right bubble
    if ((xproj)<=(xbubble+dbubble)&&(vx<=0)
      &&
    ((xproj+dbubble)>=(xbubble+dbubble))
    ){
    return 1;
  }  else {return 0;}
}

int checkangleHGbbl(){ //collision proj angle top left bubble
    if (
    ((xproj+radius)>=(xbubble))&&((yproj+radius)>=(ybubble))
        &&(vx>0)&&(vy>0)){
    return 1;
  }  else {return 0;}
}

int checkangleHDRbbl(){ //collision proj angle top droit bubble
    if (
    ((xproj+radius)<=(xbubble+dbubble))&&((yproj+radius)>=(ybubble))
        &&(vx<0)&&(vy>0)){
    return 1;
  }  else {return 0;}
}

int checkangleBGbbl(){ //collision proj angle bottom left bubble
    if (
    ((xproj+radius)>=(xbubble))&&((yproj+radius)<=(ybubble+dbubble))
        &&(vx>0)&&(vy<0)){
    return 1;
  }  else {return 0;}
}

int checkangleBDRbbl(){ //collision proj angle bottom droit bubble
    if (
    ((xproj+radius)<=(xbubble+dbubble))&&((yproj+radius)<=(ybubble+dbubble))
        &&(vx<0)&&(vy<0)){
    return 1;
  }  else {return 0;}
}

//collision paddle
//yproj=ypad+radius-1 = empêche effet tube d'après Tom
int checklengthpad(){ //si bord droit proj plus à right que bord left raquette et que bord left proj plus à left bord droit raquette
  if (((xproj+dbubble)>=xpad)&&((xproj)<=(xpad+lpad))){
    return 1;
  }  else {return 0;}
}

int checkheightpad(){ //si bottom proj plus bottom top raquette et que top proj plus top bottom raquette
   if (((yproj+dbubble)>=ypad)&&((yproj)<=(ypad+hpad))){
    return 1;
  }  else {return 0;}
}

int checkangleHGpad(){ //collision proj angle top left pad
    if (((xproj)>=(xpad-dbubble))
  &&
    ((xproj+dbubble)<=(xpad+dbubble-1))
  &&
    ((yproj)>=(ypad-dbubble))
  &&
    ((yproj+dbubble-1)<=ypad)
  &&
    (vy>0)
  &&
    (vx>0)
    ){//=va vers le bottom et la right
    return 1;
    }  else {return 0;}
}

int checkangleHDRpad(){ //collision proj angle top droit pad
    if (((xproj)>=(xpad+lpad-dbubble+1))
  &&
    ((xproj+dbubble)<=(xpad+lpad+dbubble))
  &&
    ((yproj)>=(ypad-dbubble))
  &&
    ((yproj+dbubble-1)<=ypad)
  &&
    (vy>0)
  &&
    (vx<0)
    ){//=va vers le bottom et la left
    return 1;
  }  else {return 0;}
}

int checktoppad(){ //collision proj top pad
    if (((yproj+dbubble)>=(ypad))//si bottom projectile est plus bottom ou égal à top raquette
  &&
    (yproj<=ypad)
  &&
    (vy>0)){//=descend
    return 1;
  }  else {return 0;}

}

int checkbottompad(){ //collision proj bottom pad
     if (((yproj)<=(ypad+hpad)) //si top projectile est plus top ou égal à bottom raquette
  &&
     ((yproj+dbubble)>=(ypad+hpad))//et que bottom projectile plus bottom que raquette
  &&
    (vy<0)){//=remonte
    return 1;
  }  else {return 0;}
}

int checkleftpad(){ //collision proj left pad
if (((xproj+dbubble)>=xpad) //si bord left projectile égal ou plus à left face left
  &&
(xproj<=xpad)
  &&
    (vx>0)){//=va vers la right
    return 1;
  }  else {return 0;}
}

int checkrightpad(){ //collision proj right pad
  if (((xproj)<=(xpad+lpad)) //si bord right projectile égal ou plus à right bord droit de la raquette
  &&
  ((xproj+dbubble)>=(xpad+lpad))
  &&
    (vx<0)){//=va vers la left
    return 1;
  }  else {return 0;}
}

int checkangleBGpad(){ //collision proj angle bottom left pad
    //est-ce vraiment utile ?
     /* if ((check==0)&&
    ((xproj+dbubble)>=xpad) //== ne marche pas car si dépasse vitesse va traverser
  &&
    (yproj>=(ypad+hpad))
  &&
    (vy<0))//=va vers le top
  {  else {return 0;}*/
}

int checkangleBDRpad(){ //collision proj angle bottom droit pad
    //est-ce vraiment utile ?
}
