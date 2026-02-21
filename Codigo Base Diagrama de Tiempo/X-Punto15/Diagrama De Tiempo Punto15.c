#include <stdio.h>
#include "../Compuertas Logicas Y Mas/LogicGates.h"
#include "../WaveDrom Format/FormatoWaveDrom.h"

#define MAX_TIEMPO 140

int main(void) {

    /* ================== SEÑALES ================== */
    int clk[MAX_TIEMPO] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                     1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                     1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                     1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                     1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                     1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                     1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};

    int clr[MAX_TIEMPO] = {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    int pre[MAX_TIEMPO] = {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};


    int a0[MAX_TIEMPO], a1[MAX_TIEMPO], a2[MAX_TIEMPO], a3[MAX_TIEMPO], a4[MAX_TIEMPO], a5[MAX_TIEMPO], a6[MAX_TIEMPO], a7[MAX_TIEMPO];
    int b0[MAX_TIEMPO], b1[MAX_TIEMPO], b2[MAX_TIEMPO], b3[MAX_TIEMPO], b4[MAX_TIEMPO], b5[MAX_TIEMPO], b6[MAX_TIEMPO], b7[MAX_TIEMPO];

    int qs[MAX_TIEMPO], c[MAX_TIEMPO];

    int G0[MAX_TIEMPO], P0[MAX_TIEMPO], G1[MAX_TIEMPO], P1[MAX_TIEMPO];

    for (int i = 0; i < MAX_TIEMPO; i++) {
        a0[i] = a1[i] = a2[i] = a3[i] = a4[i] = a5[i] = a6[i] = a7[i] = 0;
        b0[i] = b1[i] = b2[i] = b3[i] = b4[i] = b5[i] = b6[i] = b7[i] = 0;

        qs[i] = c[i] = 0;
        G0[i] = P0[i] = G1[i] = P1[i] = 0;
    }

    //Grupo B
    int B0 = 0, B1 = 0, B2 = 0, B3 = 0, B4 = 0, B5 = 0, B6 = 0, B7 = 0, QS = 0, C = 0;

    //Grupo A
    int A0 = 1, A1 = 1, A2 = 1, A3 = 1, A4 = 1, A5 = 1, A6 = 1, A7 = 1;

    a0[0] = A0;
    a1[0] = A1;
    a2[0] = A2;
    a3[0] = A3;
    a4[0] = A4;
    a5[0] = A5;
    a6[0] = A6;
    a7[0] = A7;

    b0[0] = B0;
    b1[0] = B1;
    b2[0] = B2;
    b3[0] = B3;
    b4[0] = B4;
    b5[0] = B5;
    b6[0] = B6;
    b7[0] = B7;

    qs[0] = 0;

    G0[0] = XOR_Gate(A0, B0);
    P0[0] = AND_Gate(A0, B0);

    G1[0] = XOR_Gate(QS,G0[0]);
    P1[0] = AND_Gate(QS,G0[0]);

    c[0] = OR_Gate(P0[0],P1[0]);

    for (int i = 1; i < MAX_TIEMPO; i++) {
        def_flip_flop(&Q3, clk[i-1], clk[i], clr[i], 1, 1, G[i-1], &q3[i]);
        def_flip_flop(&Q2, clk[i-1], clk[i], clr[i], 1, 1, q3[i-1], &q2[i]);
        def_flip_flop(&Q1, clk[i-1], clk[i], clr[i], 1, 1, q2[i-1], &q1[i]);
        def_flip_flop(&Q0, clk[i-1], clk[i], clr[i], 1, 1, q1[i-1], &q0[i]);
        def_flip_flop(&QS, clk[i-1], clk[i], 1, pre[i], 1, P[i-1], &qs[i]);

        G0[0] = XOR_Gate(a0[i], b0[i]);
        P0[0] = AND_Gate(a0[i], b0[i]);

        G1[0] = XOR_Gate(qs[i],G0[i]);
        P1[0] = AND_Gate(qs[i],G0[i]);
    }

    /* ================== FIND & REPLACE ================== */

    const int REDUCED_SIZE = MAX_TIEMPO / 2;

    int clk_red[REDUCED_SIZE];
    int clr_red[REDUCED_SIZE];
    int pre_red[REDUCED_SIZE];

    int q0_red[REDUCED_SIZE];
    int q1_red[REDUCED_SIZE];
    int q2_red[REDUCED_SIZE];
    int q3_red[REDUCED_SIZE];

    int qs_red[REDUCED_SIZE];
    int g_red[REDUCED_SIZE];
    int p_red[REDUCED_SIZE];

    find_replace(clk, MAX_TIEMPO, clk_red);
    find_replace(clr, MAX_TIEMPO, clr_red);
    find_replace(pre, MAX_TIEMPO, pre_red);

    find_replace(q0, MAX_TIEMPO, q0_red);
    find_replace(q1, MAX_TIEMPO, q1_red);
    find_replace(q2, MAX_TIEMPO, q2_red);
    find_replace(q3, MAX_TIEMPO, q3_red);

    find_replace(qs, MAX_TIEMPO, qs_red);
    find_replace(G, MAX_TIEMPO, g_red);
    find_replace(P, MAX_TIEMPO, p_red);

    /* ================== WaveDrom JSON ================== */

    printf("{ \"signal\": [\n");

    print_clock("clk", REDUCED_SIZE, 0);

    print_wave("clr", REDUCED_SIZE, clr_red, 0);
    print_wave("pre", REDUCED_SIZE, pre_red, 0);

    print_wave("Q0", REDUCED_SIZE, q0_red, 0);
    print_wave("Q1", REDUCED_SIZE, q1_red, 0);
    print_wave("Q2", REDUCED_SIZE, q2_red, 0);
    print_wave("Q3", REDUCED_SIZE, q3_red, 0);

    print_wave("QS", REDUCED_SIZE, qs_red, 0);
    print_wave("G", REDUCED_SIZE, g_red, 0);
    print_wave("P", REDUCED_SIZE, p_red, 1);

    printf("] }\n");

    return 0;
}

