//NAMA  : DEOVIE LENTERA H
//NIM   : 18320037

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define init_list 1
#define limit 1024

void digit(int n, int *pointer);

int main()
{
    int nim, i;
    int digits[8] = {0,0,0,0,0,0,0,0};
    printf("Input NIM: ");
    scanf("%d", &nim);
    printf("\nNIM: %d\n", nim);

    int* ptrDigits = &digits;

    digit(nim, ptrDigits);

    int r = (digits[3]*10 + digits[4])*1000;
    float c = (digits[0]*100000 + digits[1]*10000 + digits[2]*1000 + digits[5]*100 + digits[6]*10 + digits[7])* pow(10, -12);
    int vin = 5;
    int vo = 0;
    double tau = r*c;
    printf("\nVin: %d\nResistance: %d\nCapacitance: %e\nTime constant: %f\n", vin, r, c, tau);

    printf("\nV(t) = Vin + (V0 - Vin)*e^(-t/RC)\nV0 = 0\n");



    float v[limit];
    double temp;


    for (i = 0; i<limit; i++){
        temp = -(i*0.001/(tau));
        //printf("\n temp : %e", temp);
        v[i] = vin + ((vo - vin) * exp(temp));
    }
    printf("\n");
    for (int j = 0; j<i; j++){
        printf("v(%d): %e\n", j, v[j]);
    }
    return 0;
}

void digit(int n, int *pointer)
{
    int i;
    int j = 7;
    for (int i = 0; n>0; i++){
        i = n%10;
        n = n/10;
        pointer[j] = i;
        j--;
    }
}
