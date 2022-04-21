#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>
#include <pthread.h>
#include "signali.h"
#include "datoteke.h"

int A = 1; /* broj radnih dretvi */
int B = 1; /* broj neradnih dretvi */

FILE *fp;

char *dat_status, *dat_obrada, *dat_mreza;
int nije_kraj = 1;
int broj;

/* funkcije koje rade dretve */
void *obrada(void *);
void *mreza(void *);

int main(int argc, char* argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Koristenje: %s <status-datoteka> "
        "<datoteka-s-podacima> <cjevovod>\n", argv[0]);
        exit(2);
    }

    dat_status = argv[1];
	dat_obrada = argv[2];
	dat_mreza = argv[3];

    postavi_signale();  /* maskiranje signala? */

    fp = fopen(dat_status, "r");  /* postoji li status-datoteka s danim nazivom? */
    if (fp == NULL) {   /* status-datoteka s danim nazivom ne postoji */
        fp = fopen(dat_status, "w");  /* kreiraj novu status-datoteku s danim nazivom */
        if (fp == NULL) {
            printf("Greska!\n");
            exit(0);
        }
        fprintf(fp, "1 ");  /* inicijaliziraj status_datoteku s danim nazivom */
        fclose(fp);
    }
    else fclose(fp);    /* status-datoteka s danim nazivom postoji od prije, ovo nije prvo pokretanje programa */

    fp = fopen(dat_obrada, "r");  /* postoji li datoteka s podacima koja ima ovaj naziv? */
    if (fp == NULL) {   /* datoteka s podacima koja ima ovaj naziv ne postoji */
        fp = fopen(dat_obrada, "w");  /* kreiraj novu datoteku s podacima koja ima ovaj naziv */
        if (fp == NULL) {
            printf("Greska!\n");
            exit(0);
        }
        fprintf(fp, "1 ");  /* inicijaliziraj datoteku s podacima koja ima ovaj naziv */
        fclose(fp);
    }
    else fclose(fp);    /* datoteka s podacima koja ima ovaj naziv postoji od prije, ovo nije prvo pokretanje programa */

    fp = fopen(dat_mreza, "r");  /* postoji li mreza s danim nazivom? */
    if (fp == NULL) {   /* mreza s danim nazivom ne postoji */
        fp = fopen(dat_mreza, "w");  /* kreiraj novu mrezu s danim nazivom */
        if (fp == NULL) {
            printf("Greska!\n");
            exit(0);
        }
        fclose(fp);
    }
    else fclose(fp);    /* mreza s danim nazivom postoji od prije, ovo nije prvo pokretanje programa */

    printf("Program s PID=%ld krenuo s radom\n", (long) getpid());

    /* dohvati prvi broj i zapisi 0 u status */
    /* broj = dohvati broj iz status-datoteke */
    broj = procitaj_status();
    int kvadrat;    /* broj koji cemo pronaci je potpun kvadrat i bit ce potrebno korjenovati ga za nastavak */
    /* ako je broj == 0 onda citaj brojeve iz datoteke s podacima dok ne dodjes do kraja datoteke */
    /* broj = korijen zadnjeg procitanog broja */
    if (broj == 0) {
        kvadrat = pronadji_zadnji_broj();
        broj = (int)sqrt(kvadrat);
    }
    /* prije nastavka rada u status-datoteku upisi 0 umjesto prijasnjeg broja */
    zapisi_status(0);

    /* stvori dretve: radnu i mreznu */
	/* todo */
    pthread_t opisnik[A + B];
    int i, j, id[A + B];
    for (i = 0; i < A; i++) {   /* stvaranje radnih dretvi */
        id[i] = i;
        if (pthread_create(&opisnik[i], NULL, obrada, &id[i])) {
            fprintf(stderr, "Ne mogu stvoriti novu dretvu, id = %d!\n", i);
            exit(0);
        }
    }
    for (i = 0; i < B; i++) {   /* stvaranje neradnih dretvi */
        id[A + i] = i;
        if (pthread_create(&opisnik[A + i], NULL, mreza, &id[i])) {
            fprintf(stderr, "Ne mogu stvoriti novu dretvu, id = %d!\n", i);
            exit(0);
        }
    }
    
    int x;
    while(nije_kraj) {
		//procitaj broj iz konzole, npr. sa scanf
		//ako je > 0 onda ga postavi kao broj
		//inace prekidni s radom => postavi nije_kraj = 0
        sleep(1);
        scanf("%d", &x);
        if (x > 0) broj = x - 1;
        else nije_kraj = 0;
	}

	//cekaj na kraj dretve obrada, ali ne i one druge mrezne
    for (j = 0; j < A; j++)
        pthread_join(opisnik[j], NULL);

    printf("Program s PID=%ld zavrsio s radom\n", (long) getpid());

    return 0;
}

void *obrada(void *p)
{
    /* ako je broj > 0, program nastavlja s proracunom */
    if (broj > 0) {
        int x;
        /* beskonacna petlja */
        while(nije_kraj) {
            broj = broj + 1;
            printf("Program: kvadriranje broja %d\n", broj);
            x = broj * broj;
            
            /* dodaj x u datoteku s podacima */
            dodaj_broj(x);
            sleep(5);   /* odgodi(5) */
        }
    }

	return NULL;
}

void *mreza(void *p)
{
	//u petlji cekaj da se nesto pojavi u cijevi
	//ako je procitano > 0 onda ga postavi u broj
    int x = 0;
    while(nije_kraj) {
        sleep(1);
        // je li se nesto pojavilo u cijevi?
        // ako jest, dohvati i spremi u x koristeci funkciju dohvati_iz_cijevi()
        x = dohvati_iz_cijevi();
        if (x > 0) broj = x - 1;
    }

	return NULL;
}