#ifndef LOGIC_GATES_H
#define LOGIC_GATES_H

//Firma  de compuertas logicas.
int AND_Gate(int A, int B);
int XOR_Gate(int A, int B);


//Flip Flops
int def_flip_flop(int *state, int prev_clk, int clk, int clear, int pre, int ena, int d, int *q );


#endif