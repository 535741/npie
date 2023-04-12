#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <mpfr.h>

int menu(void){
    char input[100];
    int out;
    printf("Pi to n=\n");
    fflush(stdout);
    fgets(input, 100, stdin);
    sscanf(input, "%i", &out);
    return out;
}

int main(void){
    unsigned int p;
    unsigned int g;
    int b;
    p = 1;
    int in = menu();
    mpfr_prec_t x = 4*in;
    b = 10;
    mpfr_t y;
    mpfr_init2(y, x);
    mpfr_const_pi(y, MPFR_RNDF);
    mpfr_out_str (stdout, b, in, y, MPFR_RNDF);
    printf("\n");
    mpfr_clear(y);
    mpfr_mp_memory_cleanup();
}

