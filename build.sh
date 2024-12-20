#!/usr/bin/env bash

if [ -z "${1}" ]
then
        FICHIER_SORTIE="bbb.out"
else
        FICHIER_SORTIE=${1}
fi
echo "Fichier de sortie : ${FICHIER_SORTIE}"


gcc bbb.c variables.c game.c check.c sdl_helper/audio_functions.c sdl_helper/constants.c sdl_helper/function.c sdl_helper/text_functions.c -o bbb.out -lSDL2main -lSDL2 -lm -lSDL2_mixer -lSDL2_ttf
