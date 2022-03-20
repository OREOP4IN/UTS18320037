//NAMA  : DEOVIE LENTERA H
//NIM   : 18320037

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFF_LEN 255
#define MAX_STRLEN 30

int main()
{
    char filename[MAX_STRLEN];
    int i = 0;

    float e = 1.602 * pow(10, -19);
    float mo = 9.109 * pow(10, -31);
    float c = 2.9979 * pow(10, 8);

    printf("e   : %.3e\nmo  : %.3e\nc   : %.4e\n", e, mo, c);

    printf("\nInput nama file: ");
    scanf("%s", &filename);

    FILE *openfile;
	openfile = fopen(filename, "r");

    char buff[BUFF_LEN];
    int volt[10] = {0};

    char* token;

    while(fgets(buff, MAX_STRLEN, openfile)) {
        token = strtok(buff, "\n");

        volt[i] = atoi(token);  //konversi str yang didapatkan ke integer
        ++i;
    }

    printf("  ");
    for(i = 0; i<10; i++){
        if (i==9){
            printf("%dV", volt[i]);
            break;
        }
        printf("%dV, ", volt[i]);
        if (i==4){
            printf("\n  ");
        }
    }
    printf("\n\nVe = mc^2 - moc^2\nm/mo = [1 - (v/c)^2]^-1/2\n");


    float m[10] = {0};
    for (i = 0; i<10; i++){
        m[i] = ((volt[i]*e)/(c*c)) + mo;
    }

    float v[10] = {0};
    for (i = 0; i<10; i++){
        v[i] = c*sqrt(1-(mo/m[i]));
    }

    printf("\nm[i]:\n  ");
    for(i = 0; i<10; i++){
        if (i==9){
            printf("%e", m[i]);
            break;
        }
        printf("%e, ", m[i]);
        if (i==4){
            printf("\n  ");
        }
    }

    printf("\n\nv[i]:\n  ");
    for(i = 0; i<10; i++){
        if (i==9){
            printf("%e", v[i]);
            break;
        }
        printf("%e, ", v[i]);
        if (i==4){
            printf("\n  ");
        }
    }


    printf("\n\nv[i]/c:\n  ");
    for(i = 0; i<10; i++){
        if (i==9){
            printf("%e\n", v[i]/c);
            break;
        }
        printf("%e, ", v[i]/c);
        if (i==4){
            printf("\n  ");
        }
    }



    return 0;
}
