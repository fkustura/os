#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <signal.h>
#include <math.h>
#include <pthread.h>
//#include "signali.h"
#include "datoteke.h"
#include <stdbool.h>

#define MAX_BROJ_DRETVI 9   // bez racunanja "main" dretve
#define ms 2000  // konstanta za "spavanje", funkciju usleep()

pthread_mutex_t m;  // monitor
pthread_cond_t red; // red uvjeta

int radi;   // 0-kad niti jedna dretva ne radi, id-dretve kad ona radi

int postavljeni_broj_dretvi = 5;    // bez racunanja "main" dretve
int broj_dretvi = 0;    // bez racunanja "main" dretve
bool dostupnost[MAX_BROJ_DRETVI];   // polje koje ce oznacavati je li pojedini ID dostupan za pthread_create naredbu

FILE *fp;

char *dat_status, *dat_obrada;
int nije_kraj = 1;
int broj;   // 1, 2, ...

void *obrada (void *p); // utjecat ce na izracun (moci ce promijeniti broj)

int main (int argc, char* argv[])
{
    if (postavljeni_broj_dretvi > MAX_BROJ_DRETVI) {
        printf("Postavljeni broj dretvi veci je od maksimalnog broja dretvi definiranog makro-naredbom! "
               "Potrebno je nanovo inicijalizirati globalnu varijablu postavljeni_broj_dretvi u kodu kako bi bila <= MAX_BROJ_DRETVI.\n");
        exit(3);
    }    

    if (argc < 3) {
        fprintf(stderr, "Koristenje: %s <status-datoteka> "
        "<datoteka-s-podacima>\n", argv[0]);
        exit(2);
    }

    dat_status = argv[1];
	dat_obrada = argv[2];

    fp = fopen(dat_status, "r");    // postoji li status-datoteka s danim nazivom?
    if (fp == NULL) {   // status-datoteka s danim nazivom ne postoji
        fp = fopen(dat_status, "w");    // kreiraj novu status-datoteku s danim nazivom
        if (fp == NULL) {   // greska prilikom fopen
            printf("Greska!\n");
            exit(0);
        }
        fprintf(fp, "1 ");  // inicijaliziraj status_datoteku s danim nazivom
        fclose(fp);
    }
    else fclose(fp);    // status-datoteka s danim nazivom postoji od prije

    fp = fopen(dat_obrada, "r");    // postoji li datoteka s podacima koja ima ovaj naziv?
    if (fp == NULL) {   // datoteka s podacima koja ima ovaj naziv ne postoji
        fp = fopen(dat_obrada, "w");    // kreiraj novu datoteku s podacima koja ima ovaj naziv
        if (fp == NULL) {   // greska prilikom fopen
            printf("Greska!\n");
            exit(0);
        }
        fprintf(fp, "1 ");  // inicijaliziraj datoteku s podacima koja ima ovaj naziv
        fclose(fp);
    }
    else fclose(fp);    // datoteka s podacima koja ima ovaj naziv postoji od prije

    // dohvati prvi broj i zapisi 0 u status
    // broj = dohvati broj iz status-datoteke
    broj = procitaj_status();
    int kvadrat;    // broj koji cemo pronaci je potpun kvadrat i bit ce potrebno korjenovati ga za nastavak
    // ako je broj == 0 onda citaj brojeve iz datoteke s podacima dok ne dodjes do kraja datoteke
    // broj = korijen zadnjeg procitanog broja
    if (broj == 0) {
        kvadrat = pronadji_zadnji_broj();
        broj = (int)sqrt(kvadrat);
    }
    // prije nastavka rada u status-datoteku upisi 0 umjesto prijasnjeg broja
    zapisi_status(0);

    // stvori dretve koje ce utjecati na izracun (moci ce promijeniti broj)
    pthread_t opisnik[MAX_BROJ_DRETVI];
    int i, id[MAX_BROJ_DRETVI];
    for (i = 0; i < MAX_BROJ_DRETVI; i++) dostupnost[i] = true;  // inicijalizacija polja dostupnost
    pthread_mutex_init (&m, NULL);
    pthread_cond_init (&red, NULL);
    radi = 0;
    for (i = 0; i < postavljeni_broj_dretvi; i++) { // stvaranje dretvi koje ce utjecati na izracun (moci ce promijeniti broj)
        id[i] = i + 1;
        dostupnost[i] = false;
        if (pthread_create(&opisnik[i], NULL, obrada, &id[i])) {
            fprintf(stderr, "Ne mogu stvoriti novu dretvu, id = %d!\n", i + 1);
            exit(1);
        }
        broj_dretvi++;
    }
    
    int j, x;
    while (nije_kraj) {
		// procitaj integer iz konzole, npr. sa scanf
		// ako je > 0 onda ga postavi kao novi broj radnih dretvi
		// inace prekini s radom => postavi nije_kraj = 0
        sleep(1);
        scanf("%d", &x);
        if (x > 0) {
            if (x <= MAX_BROJ_DRETVI) {
                postavljeni_broj_dretvi = x;
                if (postavljeni_broj_dretvi > broj_dretvi) {
                    int razlika = postavljeni_broj_dretvi - broj_dretvi;    // koliko novih dretvi moramo stvoriti
                    for (i = 0; i < razlika; i++) { // stvaranje novih dretvi koje ce utjecati na izracun (moci ce promijeniti broj)
                        for (j = 0; j < MAX_BROJ_DRETVI; j++) { // trazimo dostupan ID
                            if (dostupnost[j]) break;   // pronasli smo dostupan ID
                        }
                        id[j] = j + 1;  // + 1 iz prakticnih razloga, kako bi prva vrijednost bila 1, a ne 0
                        dostupnost[j] = false;  // sada vise nije dostupan jer cemo pomocu njega izvrsiti pthread_create
                        if (pthread_create(&opisnik[j], NULL, obrada, &id[j])) {
                            fprintf(stderr, "Ne mogu stvoriti novu dretvu, id = %d!\n", j + 1);
                            exit(1);
                        }
                        broj_dretvi++;
                    }
                }
            }
            else {  // x > MAX_BROJ_DRETVI
                printf("Ponoviti unos! Novi broj radnih dretvi mora biti <= %d.\n", MAX_BROJ_DRETVI);
            }
        }       
        else nije_kraj = 0; // jedan od nacina kako zavrsiti program
	}

    printf("Uneseni broj nije prirodan; obustavljam rad, a prije toga cu malo pricekati (zbog pthread_join).\n\n");

    for (i = 0; i < MAX_BROJ_DRETVI; i++)
        if (!dostupnost[i]) pthread_join (opisnik[i], NULL);    // cekanje na dretve koje jos rade

    pthread_mutex_destroy (&m);
    pthread_cond_destroy (&red);
    
    return 0;
}

void *obrada (void *p)
{
    int id = *((int *) p);

    if (id < 1 || id > MAX_BROJ_DRETVI) return NULL;

    while (nije_kraj) {
        pthread_mutex_lock (&m);
        while (radi || (broj + 1) % id != 0)
            pthread_cond_wait (&red, &m);
        radi = id;
        pthread_mutex_unlock (&m);

        // ako je broj dretvi veci od postavljenog broja dretvi, onda treba zavrsiti s radom
        // prva dretva (s ID-jem 1) osigurava da program ne zaglavi u beskonacnoj while petlji
        // iz tog razloga, prvu dretvu nikad necemo prisiliti da zavrsi s radom
        if (broj_dretvi > postavljeni_broj_dretvi && id != 1) {
            dostupnost[id - 1] = true;  // podesavamo dostupnost
            broj_dretvi--;  // smanjujemo broj dretvi
            radi = 0;   // osiguravamo da neka druga dretva zapocne s radom
            pthread_exit(NULL); // u redu je, nismo unutar monitora
        }

        printf ("\nDretva %d krece s radom (broj=%d):\n", id, broj + 1);
        int y;
        pthread_mutex_lock (&m);
        broj = broj + 1;
        printf("Dretva %d upravo kvadrira broj %d...\n", id, broj);
        usleep(1000 * ms);
        y = broj * broj;
        dodaj_broj(y);  // operacija nad datotekom, ostvarena je unutar monitora
        pthread_mutex_unlock (&m);
        printf ("Dretva %d je kvadrirala broj %d; staje s radom.\n", id, broj);

        pthread_mutex_lock (&m);
        radi = 0;
        pthread_mutex_unlock (&m);
        pthread_cond_broadcast (&red);
        sleep(1);
    }

    return NULL;
}