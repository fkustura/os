/* Operacije nad signalima */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "signali.h"

/* implementacija funkcija vec opisanih u lab1 + dohvati_iz_cijevi */
void postavi_signale(); /* maskiranje signala? */
void obradi_dogadjaj(int sig);
void obradi_sigterm(int sig);
void obradi_sigint(int sig);

void postavi_signale()
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

    FILE *fp;

    /* zapisi broj u status-datoteku */
    fp = fopen(dat_status, "w");
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