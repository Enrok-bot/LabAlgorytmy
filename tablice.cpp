#include "tablice.h"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <time.h>
#include <math.h>

int main() {
    std::cout << std::boolalpha;
};

void przydzielPamiec1D(int *&tab, int n) {
    tab = new int[n];
}

void przydzielPamiec2D(int **&tab, int w, int k) {
    tab = new int *[w];
    for (int i = 0; i < w; i++) {
        tab[i] = new int[k];
    }
}

void wypelnijTablice1D(int *tab, int n, int a, int b) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % (b - a + 1) + a;
    }
}

void wypelnijTablice2D(int **tab, int w, int k, int a, int b) {
    srand(time(NULL));
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            tab[i][j] = rand() % (b - a + 1) + a;
        }
    }
}

void usunTablice1D(int *&tab) {
    delete[] tab;
}

void usunTablice2D(int **&tab, int w) {
    for (int i = 0; i < w; ++i) {
        delete[] tab[i];
    }
    delete[] tab;
}

void wyswietl1D(int *tab, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << tab[i] << " ";
    }
}

void wyswietl2D(int **tab, int w, int k) {
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < k; ++j) {
            std::cout << tab[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int najmniejszy1D(int *tab, int n) {
    int min = tab[0];
    for (int i = 1; i < n; ++i) {
        if (tab[i] < min) {
            min = tab[i];
        }
    }
    return min;
}

int najwiekszy2D(int **tab, int w, int k) {
    int max = tab[0][0];
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < k; ++j) {
            if (tab[i][j] > max) max = tab[i][j];
        }
    }
    return max;
}

void czyPierwszy(int a) {
    bool piewsza = true;
    for (int i = 2; i <= sqrt(a); ++i) {
        if (a % i == 0) piewsza = false;
    }
    if (piewsza) std::cout << "Liczba jest pierwsza" << std::endl;
    else std::cout << "Liczba nie jest pierwsza" << std::endl;
}

void zliczanie1D(int *tab, int n) {
    int liczby[10];
    for (int i = 0; i < 10; i++) {
        liczby[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        liczby[tab[i]]++;
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << "Cyfra " << i << "- " << liczby[i] << " razy" << std::endl;
    }
}

void sumaCyfr(int a) {
    int suma = 0;
    do {
        suma += a % 10;
        a /= 10;
    } while (a != 0);
    printf("%i\n", suma);
}

void srednia(int **tab, int w, int k) {
    int sredniaNad = 0;
    for (int i = 0; i < w; ++i) {
        for (int j = i + 1; j < k; ++j) {
            sredniaNad += tab[i][j];
        }
    }
    printf("%i\n", sredniaNad);
    int sredniaPod = 0;
    for (int i = 1; i < w; ++i) {
        for (int j = 0; j < i; ++j) {
            sredniaPod += tab[i][j];
        }
    }
    printf("%i\n", sredniaPod);
}