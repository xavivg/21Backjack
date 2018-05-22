cmake_minimum_required(VERSION 3.10)
project(21Blackjack C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES main.c baraja.c baraja.h partida.c partida.h jugador.c jugador.h gestionFicheros.c gestionFicheros.h listaFichas.c listaFichas.h)
add_executable(21Blackjack ${SOURCE_FILES})