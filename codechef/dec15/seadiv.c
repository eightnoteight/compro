#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <gmp.h>

int main(int argc, char const *argv[]) {
    mpz_t a, b, c, q, sevenpow;
    char *sa, *sb;
    unsigned int t, l;
        printf("\n");fflush(stdout);
    mpz_inits(a, b, c, q, sevenpow);
    sa = (char*)malloc(10000001*sizeof(char));
    sb = (char*)malloc(10000001*sizeof(char));
    scanf("%u", &t);
    while(t--) {
        scanf("%s%s%u", sa, sb, &l);
        mpz_set_str(a, sa, 7);
        mpz_set_str(b, sb, 7);
        mpz_fdiv_q(q, a, b);
        mpz_ui_pow_ui(sevenpow, 7, l);
        mpz_mod(a, q, sevenpow);
        printf("%s\n", mpz_get_str(NULL, 7, a));
    }
    return 0;
}
