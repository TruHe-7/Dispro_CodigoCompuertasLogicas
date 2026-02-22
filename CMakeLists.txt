cmake_minimum_required(VERSION 3.20)
project(Dispro C)

set(CMAKE_C_STANDARD 11)

# ==========================
# Archivos compartidos
# ==========================
set(COMMON_SOURCES
        "Codigo Base Diagrama de Tiempo/Compuertas Logicas Y Mas/AND_gate.c"
        "Codigo Base Diagrama de Tiempo/Compuertas Logicas Y Mas/XOR_gate.c"
        "Codigo Base Diagrama de Tiempo/Compuertas Logicas Y Mas/FlipFlop_gate.c"
        "Codigo Base Diagrama de Tiempo/Compuertas Logicas Y Mas/Clocks.c"
        "Codigo Base Diagrama de Tiempo/WaveDrom Format/FormatoWaveDrom.c"
        "Codigo Base Diagrama de Tiempo/Compuertas Logicas Y Mas/OR_gate.c"
        "Codigo Base Diagrama de Tiempo/CambiosDeBase/CambioDeBases.h"
        "Codigo Base Diagrama de Tiempo/CambiosDeBase/8Bus_Hexa.c"
)

# ==========================
# Ejecutable V2
# ==========================
add_executable(Diagrama_Version2
        "Codigo Base Diagrama de Tiempo/Diagrama de Tiempo V2/Diagrama De Tiempo V2.c"
        ${COMMON_SOURCES}
)

# ==========================
# Ejecutable Punto14
# ==========================
add_executable(Punto14
        "Codigo Base Diagrama de Tiempo/X-Punto14/Diagrama De Tiempo Punto14.c"
        ${COMMON_SOURCES}
)

# ==========================
# Ejecutable Punto15
# ==========================
add_executable(Punto15
        "Codigo Base Diagrama de Tiempo/X-Punto15/Diagrama De Tiempo Punto15.c"
        ${COMMON_SOURCES}
)