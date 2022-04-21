/* Zaglavlje za sucelja s operacijama nad signalima */

#pragma once /* kako se ovo zaglavlje ne bi ukljucivalo vise puta u istu datoteku */

extern int broj, nije_kraj;
extern char* dat_status; /* potrebno jer sigterm uzrokuje zapisivanje tekuceg broja u status-datoteku */
/* funkcije za obradu signala */
void postavi_signale(); /* maskiranje signala? */
void obradi_dogadjaj(int sig); 
void obradi_sigterm(int sig);
void obradi_sigint(int sig);