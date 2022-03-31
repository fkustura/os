#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>

FILE *fp;

/* funkcije za obradu signala */
void obradi_dogadjaj(int sig);
void obradi_sigterm(int sig);
void obradi_sigint(int sig);

int nije_kraj = 1;

/* globalne varijable */
int broj;
const char* status = "status.txt";
const char* obrada = "obrada.txt";

int main()
{
    struct sigaction act;

    /* 1. maskiranje signala SIGUSR1 */
    act.sa_handler = obradi_dogadjaj; /* funkcija kojom se signal obradjuje */
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGTERM); /* blokirati i SIGTERM za vrijeme obrade */
    act.sa_flags = 0; /* naprednije mogucnosti preskocene */
    sigaction(SIGUSR1, &act, NULL); /* maskiranje signala preko sucelja OS-a */

    /* 2. maskiranje signala SIGTERM */
    act.sa_handler = obradi_sigterm;
    sigemptyset(&act.sa_mask);
    sigaction(SIGTERM, &act, NULL);

    /* 3. maskiranje signala SIGINT */
    act.sa_handler = obradi_sigint;
    sigaction(SIGINT, &act, NULL);

    fp = fopen(status, "r");  /* postoji li datoteka status.txt? */
    if (fp == NULL) {   /* datoteka status.txt ne postoji */
        fp = fopen(status, "w");  /* kreiraj novu datoteku status.txt */
        if (fp == NULL) {
            printf("Greska!\n");
            exit(0);
        }
        fprintf(fp, "1 ");  /* inicijaliziraj datoteku status.txt */
        fclose(fp);
    }
    else fclose(fp);    /* datoteka status.txt postoji od prije, ovo nije prvo pokretanje programa */

    fp = fopen(obrada, "r");  /* postoji li datoteka obrada.txt? */
    if (fp == NULL) {   /* datoteka obrada.txt ne postoji */
        fp = fopen(obrada, "w");  /* kreiraj novu datoteku obrada.txt */
        if (fp == NULL) {
            printf("Greska!\n");
            exit(0);
        }
        fprintf(fp, "1 ");  /* inicijaliziraj datoteku obrada.txt */
        fclose(fp);
    }
    else fclose(fp);    /* datoteka obrada.txt postoji od prije, ovo nije prvo pokretanje programa */

    printf("Program s PID=%ld krenuo s radom\n", (long) getpid());
    
    /* broj = procitaj broj iz status.txt */
    fp = fopen(status, "r");
    if (fp == NULL) {
        printf("Greska!\n");
        exit(0);
    }
    fscanf(fp, "%d", &broj);
    fclose(fp);

    int kvadrat;
    /* ako je broj == 0 onda citaj brojeve iz obrada.txt dok ne dodjes do kraja datoteke */
    /* broj = zadnji procitani broj */
    if (broj == 0) {
        fp = fopen(obrada, "r");
        if (fp == NULL) {
            printf("Greska!\n");
            exit(0);
        }
        fscanf(fp, "%d", &kvadrat);
        while (!feof(fp)) fscanf(fp, "%d", &kvadrat);
        fclose(fp);

        broj = (int)sqrt(kvadrat);
    }

    /* prije nastavka rada u status.txt upisi 0 umjesto prijasnjeg broja */
    fp = fopen(status, "w");
    if (fp == NULL) {
        printf("Greska!\n");
        exit(0);
    }
    fprintf(fp, "0");
    fclose(fp);

    int x;
    /* ako je broj > 0, program nastavlja s proracunom */
    if (broj > 0) {
        /* beskonacna petlja */
        while(nije_kraj) {
            broj = broj + 1;
            printf("Program: kvadriranje broja %d\n", broj);
            x = broj * broj;
            
            /* dodaj x u obrada.txt */
            fp = fopen(obrada, "a");
            if (fp == NULL) {
                printf("Greska!\n");
                exit(0);
            }
            fprintf(fp, "%d ", x);
            fclose(fp);
            sleep(5);   /* odgodi(5) */
        }
    }

    printf("Program s PID=%ld zavrsio s radom\n", (long) getpid());

    return 0;
}
void obradi_dogadjaj(int sig)
{
    printf("Primio signal SIGUSR1\n");
    
    /* suvisan komad koda */
    /*
    fp = fopen(obrada, "r");
    if (fp == NULL) {
        printf("Greska!\n");
        exit(0);
    }
    fscanf(fp, "%d", &broj);
    while (!feof(fp)) fscanf(fp, "%d", &broj);
    fclose(fp);
    */

    /* ispisi broj */
    printf("Trenutni broj koji se koristi u obradi: %d\n", broj);
}
void obradi_sigterm(int sig)
{
    printf("Primio signal SIGTERM\n");

    /* zapisi broj u status.txt */
    fp = fopen(status, "w");
    if (fp == NULL) {
        printf("Greska!\n");
        exit(0);
    }
    fprintf(fp, "%d", broj);
    fclose(fp);

    nije_kraj = 0;
}
void obradi_sigint(int sig)
{
    printf("Primio signal SIGINT, prekidam rad\n");

    exit(1);    /* make takodjer vraca error s kodom 1 */
}