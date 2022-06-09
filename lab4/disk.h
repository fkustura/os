/* Zaglavlje s definicijom sučelja diska te veličinom i brojem blokova */

#pragma once

#define BLOCKS 16
#define BLOCK_SIZE 512
#define MAX_DULJINA BLOCKS * BLOCK_SIZE

int dohvati_blok(int id, char* p);
int pohrani_blok(int id, char* p);