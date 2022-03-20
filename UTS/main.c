//NAMA  : DEOVIE LENTERA H
//NIM   : 18320037

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define init_list 1
#define twentyBit 20

float power(float x, int y);

void digit(int n, int *pointer);
void decimalBinary(int decimal, int *binary);
void binaryDecimal(int* decimal, int binary[twentyBit]);

int main()
{
    int nim;
    int digits[8] = {0,0,0,0,0,0,0,0};
    printf("Input NIM: ");
    scanf("%d", &nim);
    printf("\nNIM: %d", nim);

    int* ptrDigits = &digits;

    digit(nim, ptrDigits);

    int nimGabung = digits[1]*10000 + digits[2]*1000 + digits[5]*100 + digits[6]*10 + digits[7];
    printf("\nNIM gabung: %d", nimGabung);

    //10100010001011101
     //int A = nimGabung<<4;

    int binaryNIM[twentyBit] = {0};
    int* pointerBinary = &binaryNIM;

    decimalBinary(nimGabung, pointerBinary);

    //int binaryLength = floor(log10(abs(binaryNIM))) + 1;
    printf("\nBinary: ");

    for (int i = 0; i<twentyBit; i++){
        printf("%d", binaryNIM[i]);
    }


    int binaryA[8];
    int j = 0;
    for (int i = 12; i<20; i++){
        binaryA[j] = binaryNIM[i];
        j++;
    }

    //int binaryA = binaryNIM[12]*10000000 + binaryNIM[13]*1000000 + binaryNIM[14]*100000+ binaryNIM[15]*10000+ binaryNIM[16]*1000+ binaryNIM[17]*100+ binaryNIM[18]*10+ binaryNIM[19];

printf("\nLSB: ");
for (int i = 0; i<8;i++){
    printf("%d", binaryA[i]);
}
//    printf

    int A = 0;
    int* ptrA = &A;

    binaryDecimal(ptrA, binaryA);

    printf("\nValue A: %d\n", A);

    int x = 0b10100101, y = 0b11101111;

    printf("\nA: %d\nx: %d\ny: %d\n", A,x,y);
    printf("(A & y) ^ x : %d\n", (A&y)^x);
    printf("\n");

    x = 0b11011011;
    y = 0b11110011;     //0000 && x = 0
    printf("A: %d\nx: %d\ny: %d\n", A,x,y);
    printf("(~(y>>4) && x) + A : %d\n", ((~(y>>4)&&x)+A));
    printf("\n");

    x = 0b00101111;
    y = 0b10100101;
    printf("A: %d\nx: %d\ny: %d\n", A,x,y);
    printf("((x>>2) | x) * A : %d\n", (((x>>2) | x) * A));
    printf("\n");
    //00001011 | 00101111 * 01011101

    printf("\n");
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

void decimalBinary(int decimal, int *binary)
{
    int i;
    for(i=twentyBit-1;decimal>0;i--){
        binary[i]=decimal%2;
        decimal=decimal/2;
    }
    for(i=0;i<twentyBit;i++){
        printf("%d",binary[i]);
    }
}

void binaryDecimal(int* decimal, int binary[twentyBit])
{
    int i, temp;
    int j = 0;
    temp = *decimal;
    for(i=7; i>0; i--){
        temp = temp + (binary[i]) * power(2, j);
        j++;
    }
    *decimal = temp;
}

float power(float x, int y){
	float result = 1.0;
	for (int i = 0; i < y; i++){
		result = result * x;
	}
	return result;
}

