//NAMA  : DEOVIE LENTERA H
//NIM   : 18320037

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFF_LEN 255
#define MAX_STRLEN 30
typedef struct {
	char* nama;
	int no;
	int nik;
	char* tl;
	int tgl;
	int umur;
	char* sex;
	char* darah;
	char* status;
	char* pekerjaan;
	int total;
} data;

data loadFile(char filename[MAX_STRLEN]);
void processOutput (data person);

int main()
{
    char filename[MAX_STRLEN];
    printf("SISTEM PENCATATAN DATA BERBASIS KOMPUTER\n");
    data* data_orang = malloc (sizeof(*data_orang));
    printf("Input nama file: ");
    scanf("%s", filename);

    FILE* openfile = fopen(filename, "r");






    free(data_orang);
    return 0;
}

void processOutput (data person){                               //DEFAULT
		printf("Prajurit %s\nBahan bakar awal: %d\nKonsumsi bahan bakar: %s km/liter\n", person.nama, person.nik, person.tl);
		printf("Jarak tempuh: %d km\nSisa bahan bakar: %s liter\n\n", person.umur, person.sex);
}

void addPenduduk(char nama, int nik, char tl, int tgl, int umur, char sex, char darah, char status, char pekerjaan, data* data_orang){
    int total = *(data_orang->total);
        data_orang = (data*) realloc(data_orang, ((total+1)*(sizeof(data))));
        //printf("\nrealloc berhasil\nncount : %d %p", *count, *ptr);
        //printf("checkpoint loop 1");
        (data_orang + 1)->nama = nama;
        (data_orang + 1)->nik = nik;
        (data_orang + 1)->tl = tl;
        (data_orang + 1)->tgl = tgl;
        (data_orang + 1)->umur = umur;
        (data_orang + 1)->sex = sex;
        (data_orang + 1)->darah = darah;
        (data_orang + 1)->status = status;
        (data_orang + 1)->pekerjaan = pekerjaan;




        //printf("\npenambahan berhasil");
        //printf("checkpoint loop 2");

    ++*data_orang->total;

}


data loadFile(char filename[MAX_STRLEN]){

	FILE *fp;
	char buff[BUFF_LEN];
	data data_orang;

	int index = 0;

	fp = fopen(filename, "r");

	//inisialisasi array koordinat
	data *ptr_data_orang;
	ptr_data_orang = &data_orang;



    //printf("\ncheckpoint 3");

	while (!feof(fp)){
		char* token;
		fgets(buff, BUFF_LEN, (FILE*)fp);

		if (index == 0){
                index++;
            continue;
		}
		else{
            while(fgets(buff, MAX_STRLEN, fp)) {
                token = strtok(buff, ";");
                char* str = (char*)malloc(sizeof(char)*(strlen(token)+1));
                strcpy(str, token);
                ptr_data_orang->no = atoi(str);

                token = strtok(buff, ";");
                strcpy(str, token);
                ptr_data_orang->nik = atoi(str);

                token = strtok(buff, ";");
                strcpy(str, token);
                ptr_data_orang->nama = str;

                token = strtok(buff, ";");
                strcpy(str, token);
                ptr_data_orang->tl = str;

                token = strtok(buff, ";");
                strcpy(str, token);
                ptr_data_orang->tgl = atoi(str);

                token = strtok(buff, ";");
                strcpy(str, token);
                ptr_data_orang->umur = atoi(str);

                token = strtok(buff, ";");
                strcpy(str, token);
                ptr_data_orang->sex = str;

                token = strtok(buff, ";");
                strcpy(str, token);
                ptr_data_orang->darah = str;

                token = strtok(buff, ";");
                strcpy(str, token);
                ptr_data_orang->status = str;

                token = strtok(buff, "\n");
                strcpy(str, token);
                ptr_data_orang->pekerjaan = str;


                ptr_data_orang = realloc(ptr_data_orang, 2*(sizeof(data)));

                free(str);
            }

		}
        index = index + 1;
	}
	fclose(fp);
    return data_orang;
}
