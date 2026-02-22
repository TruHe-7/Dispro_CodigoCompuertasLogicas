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
        "Codigo Base Diagrama de Tiempo/CambiosDeBase_Bus/CambioDeBases.h"
        "Codigo Base Diagrama de Tiempo/CambiosDeBase_Bus/Bus_Hexa.c"
        "Codigo Base Diagrama de Tiempo/Contadores Bits/Contadores_4Bit.c"
        "Codigo Base Diagrama de Tiempo/Contadores Bits/Contadores_Bits.h"
        "Codigo Base Diagrama de Tiempo/Compuertas Logicas Y Mas/NOT_gate.c"
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


# ==========================
# Ejecutable Punto3
# ==========================
add_executable(Punto3
        "Codigo Base Diagrama de Tiempo/X-Punto3/Diagrama De Tiempo Punto3.c"
        ${COMMON_SOURCES}
)

add_executable(Punto2
        "Codigo Base Diagrama de Tiempo/X-Punto2/Diagrama De Tiempo Punto2.c"
        ${COMMON_SOURCES}
)
