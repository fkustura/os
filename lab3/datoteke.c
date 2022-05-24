/* Operacije nad datotekama */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "datoteke.h"

/* implementacija funkcija vec opisanih u lab1 + dohvati_iz_cijevi */

int procitaj_status();  /* cita status iz status-datoteke */
void zapisi_status(int broj);   /* zapisuje status u status-datoteku */
void dodaj_broj(int broj);  /* dodaje broj u datoteku s podacima */
int pronadji_zadnji_broj(); /* pronalazi posljednji zapisani kvadrat u datoteci s podacima */
//int dohvati_iz_cijevi();

int procitaj_status()
{
    int broj;
    FILE *fp;
    
    /* broj = procitaj broj iz status-datoteke */
    fp = fopen(dat_status, "r");
    if (!fp) {
        printf("Greska! Ne mogu otvoriti %s\n", dat_status);
        exit(0);
    }
    if (fscanf(fp, "%d", &broj) != 1) {
		printf("Greska! Nije procitan broj iz %s!\n", dat_status);
		exit(0);
	}
    fclose(fp);

    return broj;    /* procitani broj iz status-datoteke */
}

void zapisi_status(int broj)
{
    FILE *fp;
    
    /* zapisi broj u status-datoteku */
    fp = fopen(dat_status, "w");
    if (!fp) {
        printf("Greska! Ne mogu otvoriti %s\n", dat_status);
        exit(0);
    }
    if (fprintf(fp, "%d\n", broj) < 1) {
		printf("Greska! Nije upisan broj u %s!\n", dat_status);
		exit(0);
    }
    fclose(fp);
}

void dodaj_broj(int broj)
{
    FILE *fp;
    
    /* dodaj broj u datoteku s podacima */
    fp = fopen(dat_obrada, "a");
    if (!fp) {
        printf("Greska! Ne mogu otvoriti %s\n", dat_obrada);
        exit(0);
    }
    if (fprintf(fp, "%d ", broj) < 1) {
		printf("Greska! Nije upisan broj u %s!\n", dat_obrada);
		exit(0);
	}
    fclose(fp);
}

int pronadji_zadnji_broj()  /* pronalazi posljednji zapisani kvadrat u datoteci s podacima */
{
    FILE *fp;
    
    int kvadrat;    /* broj koji cemo pronaci je potpun kvadrat */
    /* citaj brojeve iz datoteke s podacima dok ne dodjes do kraja datoteke */
    /* kvadrat = zadnji procitani broj */
    fp = fopen(dat_obrada, "r");
    if (!fp) {
        printf("Greska! Ne mogu otvoriti %s\n", dat_obrada);;
        exit(0);
    }
    while (!feof(fp)) 
        if (fscanf(fp, "%d", &kvadrat) != 1)
            break;
    fclose(fp);

    return kvadrat;
}

/*int dohvati_iz_cijevi()
{
	FILE *fp;
	int x, y = -1;

	fp = fopen(dat_mreza, "r");
	if (!fp) {
		fprintf(stderr, "Ne mogu otvoriti cijev %s\n", dat_mreza);
		exit(1);
	}
	if (fscanf(fp, "%d", &x) > 0)
		y = x;
	fclose(fp);

	return y;
}*/