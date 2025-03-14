#ifndef TABLICE_H
#define TABLICE_H

void przydzielPamiec1D(int *&tab, int n);

void przydzielPamiec2D(int **&tab, int w, int k);

void wypelnijTablice1D(int *tab, int n, int a, int b);

void wypelnijTablice2D(int **tab, int w, int k, int a, int b);

void usunTablice1D(int *&tab);

void usunTablice2D(int **&tab, int w);

void wyswietl1D(int *tab, int n);

void wyswietl2D(int **tab, int w, int k);

int najmniejszy1D(int *tab, int n);

int najwiekszy2D(int **tab, int w, int k);

void czyPierwszy(int a);

void zliczanie1D(int *tab, int n);

void sumaCyfr(int a);

void srednia(int **tab, int w, int k);

#endif //TABLICE_H
