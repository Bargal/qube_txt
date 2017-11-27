#pragma once
//inicjacja i wprowadzanie danych do tablicy struktur planszy gry
void defineQ(gdata *p_allData, qube **p_p_matrix, int, int);

//realizacja wysokiej trudnosci gry
void hardmode(gdata *p_allData, qube **p_p_matrix, int, int);

//inicjacja HP i Time
void hpTimeInit(gdata *p_allData);