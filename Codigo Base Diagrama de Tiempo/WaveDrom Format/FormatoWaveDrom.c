#include <stdio.h>
#include "FormatoWaveDrom.h"

void print_wave(const char *signal_name,const int max,const int *signal_values,int is_last_signal){
    printf("  { \"name\": \"%s\", \"wave\": \"", signal_name);

    int previous_value;
    if (signal_values[0] != 0)
        previous_value = 1;
    else
        previous_value = 0;

    printf("%d", previous_value);

    for (int time_index = 1; time_index < max; time_index++) {

        int current_value;

        if (signal_values[time_index] != 0)
            current_value = 1;
        else
            current_value = 0;


        if (current_value == previous_value) {
            printf(".");
        } else {
            printf("%d", current_value);
            previous_value = current_value;
        }
    }

    printf("\" }%s\n", is_last_signal ? "" : ",");
}

void print_clock(const char *name,const int max, int is_last) {
    printf("  { \"name\": \"%s\", \"wave\": \"P", name);
    for (int i = 1; i < max; i++) printf(".");
    printf("\" }%s\n", is_last ? "" : ",");
}