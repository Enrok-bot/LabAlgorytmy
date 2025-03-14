#include <iostream>
#include <regex>
#include "tablice.h"

void sortowanieBabelkowe(int *tab, int n, bool tryb);

void sortowaniePrzezWybor(int *tab, int n, bool tryb);

void sortowaniePrzezWstawianie(int *tab, int n, bool tryb);

void sortowanieBabelkowe2D(int **tab, int w, int k, bool tryb, int nrKol);

int main() {
    int *tab1D, **tab2D;

    przydzielPamiec1D(tab1D, 10);
    wypelnijTablice1D(tab1D, 10, -8, 24);

    wyswietl1D(tab1D, 10);

    sortowanieBabelkowe(tab1D, 5, false);
    // sortowaniePrzezWybor(tab1D, 5, 0);
    // sortowaniePrzezWstawianie(tab1D, 5, true);

    wyswietl1D(tab1D, 10);
    usunTablice1D(tab1D);

    przydzielPamiec2D(tab2D, 10, 10);
    wypelnijTablice2D(tab2D, 10, 10, -7, 38);

    wyswietl2D(tab2D, 10, 10);
    sortowanieBabelkowe2D(tab2D, 10, 10, true, 3);
    wyswietl2D(tab2D, 10, 10);

    usunTablice2D(tab2D,10);
}

void sortowanieBabelkowe(int *tab, int n, bool tryb) {
    int i = 0;
    while (i < n) {
        for (int j = 0; j < n - 1; j++) {
            if (tryb) {
                if (tab[j] > tab[j + 1]) {
                    std::swap(tab[j], tab[j + 1]);
                }
            } else {
                if (tab[j] < tab[j + 1]) {
                    std::swap(tab[j], tab[j + 1]);
                }
            }
        }
        i++;
    }
}

void sortowaniePrzezWybor(int *tab, int n, bool tryb) {
    int min, i, j, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (tab[j] < tab[min] && tryb) min = j;
            if (tab[j] > tab[min] && !tryb) min = j;
        }
        temp = tab[min];
        tab[min] = tab[i];
        tab[i] = temp;
    }
}

void sortowaniePrzezWstawianie(int *tab, int n, bool tryb) {
    int x, k;
    for (int i = 1; i < n; i++) {
        x = tab[i];
        for (k = i - 1; k >= 0; k--) {
            if ((tryb && x < tab[k]) || (!tryb && x > tab[k])) {
                tab[k + 1] = tab[k];
            } else
                break;
        }
        tab[k + 1] = x;
    }
}

void sortowanieBabelkowe2D(int **tab, int w, int k, bool tryb, int nrKol) {
    for (int i = 0; i < w - 1; i++) {
        for (int j = 0; j < w - 1 - i; j++) {
            if ((tryb && tab[j][nrKol] > tab[j + 1][nrKol]) ||
                (!tryb && tab[j][nrKol] < tab[j + 1][nrKol])) {
                for (int c = 0; c < k; c++) {
                    std::swap(tab[j][c], tab[j + 1][c]);
                }
            }
        }
    }
}
