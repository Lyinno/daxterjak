#include "bigint.h"
#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS/8]

/* Atribuição (com extensão) */
void big_val (BigInt res, long val){
    unsigned char* p1 = (unsigned char*)(&val);
    int n = sizeof(long);
    for(int i = 0;i<n;i++){
        *(res+i) = *p1;
        p1++;
        if(i==n-1){
            p1--;
            i++;
            int lastBitValue = (*p1)&0x80;
            char valSignal = (lastBitValue == 1 ? 0xff : 0x00);
            for(int i; i<2*n;i++){
                *(res+i) = valSignal;
            };
        };
    };
};

/* Operações Aritméticas */

/* res = -a */
void big_comp2(BigInt res, BigInt a);

/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b);

/* res = a - b */
void big_sub(BigInt res, BigInt a, BigInt b);

/* res = a * b */
void big_mul(BigInt res, BigInt a, BigInt b);

/* Operações de Deslocamento */

/* res = a << n */
void big_shl(BigInt res, BigInt a, int n);

/* res = a >> n (lógico)*/
void big_shr(BigInt res, BigInt a, int n);

/* res = a >> n (aritmético)*/
void big_sar(BigInt res, BigInt a, int n);
