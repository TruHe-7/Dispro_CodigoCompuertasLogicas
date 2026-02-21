cmake_minimum_required(VERSION 3.20)
project(Dispro C)

set(CMAKE_C_STANDARD 11)

add_executable(Dispro
        "Codigo Base Diagrama de Tiempo/Diagrama De Tiempo.c"
        "Codigo Base Diagrama de Tiempo/Compuertas Logicas Y Mas/AND_gate.c"
        "Codigo Base Diagrama de Tiempo/Compuertas Logicas Y Mas/XOR_gate.c"
        "Codigo Base Diagrama de Tiempo/Compuertas Logicas Y Mas/FlipFlop_gate.c"
        "Codigo Base Diagrama de Tiempo/Compuertas Logicas Y Mas/Clocks.c"
        "Codigo Base Diagrama de Tiempo/WaveDrom Format/FormatoWaveDrom.c"
        "Codigo Base Diagrama de Tiempo/WaveDrom Format/FormatoWaveDrom.h"
)
