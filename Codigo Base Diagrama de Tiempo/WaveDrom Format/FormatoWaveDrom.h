//
// Created by Juan Andres Sanchez on 20/02/2026.
//

#ifndef DISPRO_FORMATOWAVEDROM_H
#define DISPRO_FORMATOWAVEDROM_H


void print_wave(const char *signal_name,const int max,const int *signal_values,int is_last_signal);

void print_clock(const char *name,const int max, int is_last);

void find_replace(const int *input_values, int input_size, int *output_size);

#endif //DISPRO_FORMATOWAVEDROM_H