/* Zaglavlje za sucelja s operacijama nad datotekama */

#pragma once /* kako se ovo zaglavlje ne bi ukljucivalo vise puta u istu datoteku */

extern char *dat_status, *dat_obrada, *dat_mreza;
/* funkcije za rad s datotekama */
int procitaj_status();  /* cita status iz status-datoteke */
void zapisi_status(int broj);   /* zapisuje status u status-datoteku */
void dodaj_broj(int broj);  /* dodaje broj u datoteku s podacima */
int pronadji_zadnji_broj(); /* pronalazi posljednji zapisani kvadrat u datoteci s podacima */
int dohvati_iz_cijevi();