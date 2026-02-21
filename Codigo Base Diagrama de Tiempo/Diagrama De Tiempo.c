#include <stdio.h>
#include "Compuertas Logicas Y Mas/LogicGates.h"
#include "WaveDrom Format/FormatoWaveDrom.h"

#define MAX_TIEMPO 140


int main(void) {
    int clk[MAX_TIEMPO] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                     1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                     1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                     1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                     1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                     1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                     1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};

    int clr[MAX_TIEMPO] = {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    int pre[MAX_TIEMPO] = {0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,
                     1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,
                     0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,
                     1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,
                     0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,
                     1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,
                     0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1};

    int q0[MAX_TIEMPO], q1[MAX_TIEMPO], q2[MAX_TIEMPO], q3[MAX_TIEMPO];
    int qs[MAX_TIEMPO], G[MAX_TIEMPO], P[MAX_TIEMPO];

    for (int i = 0; i < MAX_TIEMPO; i++) {
        q0[i] = q1[i] = q2[i] = q3[i] = qs[i] = G[i] = P[i] = 0;
    }

    int Q3 = 0, Q2 = 0, Q1 = 0, Q0 = 0;
    int QS = 1;

    // Guardar estados iniciales en t=0 (para que WaveDrom arranque coherente)
    q0[0] = Q0; q1[0] = Q1; q2[0] = Q2; q3[0] = Q3; qs[0] = QS;

    G[0] = XOR_Gate(Q0, QS);
    P[0] = AND_Gate(Q0, QS);

    for (int i = 1; i < MAX_TIEMPO; i++) {
        def_flip_flop(&Q3, clk[i-1], clk[i], clr[i], 1, 1, G[i-1], &q3[i]);
        def_flip_flop(&Q2, clk[i-1], clk[i], clr[i], 1, 1, G[i-1], &q2[i]);
        def_flip_flop(&Q1, clk[i-1], clk[i], clr[i], 1, 1, G[i-1], &q1[i]);
        def_flip_flop(&Q0, clk[i-1], clk[i], clr[i], 1, 1, G[i-1], &q0[i]);
        def_flip_flop(&QS, clk[i-1], clk[i], 1, pre[i-1], 1, P[i-1], &qs[i]);

        G[i] = XOR_Gate(q0[i], qs[i]);
        P[i] = AND_Gate(q0[i], qs[i]);
    }

    // ========= WaveDrom JSON =========
    printf("{ \"signal\": [\n");

    //Formato solo de clock
    print_clock("clk", MAX_TIEMPO, 0);

    //Señales a imprimir para el diagrama.
    print_wave("clr", MAX_TIEMPO,clr, 0);
    print_wave("pre",MAX_TIEMPO, pre,  0);
    print_wave("Q0",MAX_TIEMPO, q0,  0);
    print_wave("Q1",MAX_TIEMPO, q1,  0);
    print_wave("Q2",MAX_TIEMPO, q2,  0);
    print_wave("Q3",MAX_TIEMPO, q3,  0);
    print_wave("QS",MAX_TIEMPO, qs, 0);
    print_wave("G",MAX_TIEMPO,  G,  0);
    print_wave("P",MAX_TIEMPO,  P, 1);

    printf("] }\n");

    return 0;
}