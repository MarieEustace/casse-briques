#include <SDL2/SDL.h>
#include "sdl_helper/function.h"
#include "sdl_helper/text_functions.h"
#include "sdl_helper/audio_functions.h"
#include "sdl_helper/constants.h"
#include <unistd.h>
#include <time.h>
#include "game.h"
#include "variables.h"
#include <math.h>
#include "check.h"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 700
#define FPS 60

void drawGame(){
    /* Ici je dessine mon jeu
     * exemple position x, y modifiés dans KeyPressed() et utilisés pour
     * pouvoir deplacer la figure à chaque boucle de gameLoop()
     */
    clear();
    music();
    menu();
    selectLevel();
    start();
    end();
    actualize();
    usleep(1000000 / FPS); // 60 images par seconde | 1000000 = 1 seconde
}

void KeyDown(SDL_Keycode touche){ //touche appuyée
    /** @brief event.key.keysym.sym renvoie la touche appuyée
     *
     */
    switch (touche) {
        case SDLK_SPACE:
            //touche espace appuyée
            if (aBall==1){
               aBall=3;
            }
            else {
                aBall=1;
            }
            break;
        case SDLK_LEFT :
            //touche left appuyée
                goleft=1;
            break;
        case SDLK_RIGHT :
            //touche right appuyée
                goright=1;
            break;
        case SDLK_q:
            //touche q appuyée
                goleft=1;
            break;
        case SDLK_d:
            //touche d appuyée
                goright=1;
            break;
          case SDLK_p:
            //touche p appuyée
                if (speedproj<10){
                    speedproj*=1.5;
                }
            break;
          case SDLK_m:
            //touche m appuyée
                if (speedproj>1){
                    speedproj/=1.5;
                }
            break; 
            case SDLK_c:
            //touche c appuyée = change couleur projectile
                colorProj();
            break;
            case SDLK_s:
            //touche s appuyée = start -> sélection niveau
                aSound=1;
                aLevel=1;
                aMenu=0;
            break;
            case SDLK_b:
            //touche b appuyée = retour au menu
                aSound=1;
                init_game();
                aLevel=0;
                level=0;
                aStart=0;
                aMenu=1;
            break;
            case SDLK_t:
            //touche t appuyée = try again
                resetlvl();
            break;
            case SDLK_KP_1:
            //touche 1 appuyée
                level=1;
            break;
            case SDLK_KP_2:
            //touche 2 appuyée
                level=2;
            break;
            case SDLK_KP_3 :
            //touche 3 appuyée
                level=3;
            break;
            case SDLK_ESCAPE:
            freeAndTerminate();
            break;
        default:
            break;
    }
}
void KeyUp(SDL_Keycode touche){ //touche relâchée
    /** @brief event.key.keysym.sym renvoie la touche appuyée
     *
     */
    switch (touche) {
        case SDLK_LEFT :
            //touche left appuyée
                goleft=0;
            break;
        case SDLK_RIGHT :
            //touche right appuyée
                goright=0;
            break;
        case SDLK_q:
            //touche q appuyé
                goleft=0;
            break;
        case SDLK_d:
            //touche d appuyé
                goright=0;
            break;
        case SDLK_ESCAPE:
                freeAndTerminate();
            break;
        default:
            break;
    }
}

void joyButtonPressed(){
}

void gameLoop() {
    int programLaunched = 1;
    while (programLaunched == 1) {
        // Boucle pour garder le programme ouvert
        // lorsque programLaunched est different de 1
        // on sort de la boucle, donc de la fonction
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // boucle pour la gestion d'évenement
            switch (event.type) {
                /** event.type renvoi le type d'evenement qui se passe
                 * (si on appuie sur une touche, clique de souris...)
                 * en fonction du type d'évènement on à alors
                 * différentes information accessibles
                 * voir doc pour plus d'event https://wiki.libsdl.org/SDL_EventType
                 */
                case SDL_QUIT:
                    // quand on clique sur fermer la fénêtre en haut à right
                    programLaunched = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN :
                    xmouse=event.motion.x;
                    ymouse=event.motion.y;
                  if (aLevel==1){
                    xlevel=event.motion.x;
                    ylevel=event.motion.y;
                    xmouse=2000;
                    ymouse=2000;
                  }
                    break;
                case SDL_MOUSEBUTTONUP:
                    /* clique de la souris
                     * event.motion.y | event.motion.x pour les positions de la souris
                     */
                    //printf("position de la souris x : %d , y : %d\n", event.motion.x, event.motion.y);
                     xmouse=2000;
                     ymouse=2000;
                    break;
                case SDL_KEYDOWN:
                    KeyDown(event.key.keysym.sym);
                    break;
                case SDL_KEYUP:
                    KeyUp(event.key.keysym.sym);
                    break;
                case SDL_JOYBUTTONDOWN:
                    break;
                default:
                    break;
            }
        }
        /* coder ici pour que le code s'execute après chaque évenement
         * exemple dessiner un carré avec position int x, int y qu'on peut
         * deplacer lorsqu'on appuie sur une touche
         */
        drawGame();

    }
}

int main(){
    /** @description 3 fonctions dans le main qui permettent de créer l'application et la maintenir ouverte :
     *  init(...) : initialiser la SDL/ fenêtre
     *  gameLoop() : boucle de jeu dans laquelle l'application reste ouverte
     *  freeAndTerminate() : quitte le programme proprement
     */
    srand (time(NULL));
    init(WINDOW_WIDTH, WINDOW_HEIGHT);
    init_game();
    gameLoop();
    printf("Fin du programme\n");
    freeAndTerminate();
}
