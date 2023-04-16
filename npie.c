#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <mpfr.h>

int menu(void){
    char input[15];
    int out;
    printf("Pi to n digits.\nn = ");
    fflush(stdout);
    fgets(input, 15, stdin);
    sscanf(input, "%i", &out);
    return out;
}

int main(void){
    int b = 10;
    int in = 1+menu();
    mpfr_prec_t x = 4*in;
    mpfr_t y;
    mpfr_init2(y, x);
    mpfr_const_pi(y, MPFR_RNDF);
    printf("\n");
    mpfr_out_str (stdout, b, in, y, MPFR_RNDF);
    printf("\n\n");
    mpfr_clear(y);
    mpfr_mp_memory_cleanup();
}
