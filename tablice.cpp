#include <iostream>

void przydzielPamiec1D(char *&tab, int n);

void usunTablice1D(char *&tab);

void wypelnijTablice1D(char *tab, int n);

void wyswietl1D(int *tab, int n);

int naiwny(char *tekst, char *wzorzec, int dlt, int dlw);

void zudujTabliceDostosowan(char *wzorzec, int dlw, int *p);

int kmp(char *wzorzec, char *tekst, int dlw, int dlt, int *p);

int main() {
    char *tekst, *wzorzec;
    przydzielPamiec1D(tekst,15);
    przydzielPamiec1D(wzorzec,3);
    std::cout << "Podaj tekst: ";
    wypelnijTablice1D(tekst,15);
    std::cout << "Podaj wzorzec: ";
    wypelnijTablice1D(wzorzec,3);

    std::cout << "Tekst: " << tekst << std::endl;
    std::cout << "Wzorzec: " << wzorzec << std::endl;

    // std::cout << naiwny(tekst,wzorzec,15,3) << std::endl;
    return 0;
}

int naiwny(char *tekst, char *wzorzec, int dlt, int dlw) {
    int i = 0;
    while (i < dlt - dlw) {
        int j = 0;
        while (j < dlw && wzorzec[i] == tekst[i + j]) {
            j++;
        }
        if (j == dlw) {
            return i;
        }
        i++;
    }
    return NULL;
}

void zudujTabliceDostosowan(char *wzorzec, int dlw, int *p) {
    p[0] = 0;
    p[1] = 0;
    int t = 0, i = 1;
    while (i < dlw) {
        while (t > 0 && (wzorzec[i] != wzorzec[t])) {
            t = p[t];
        }
        if (wzorzec[i] == wzorzec[t]) {
            t++;
            p[++i] = t;
            i++;
        }
    }
}

int kmp(char *wzorzec, char *tekst, int dlw, int dlt, int *p) { // dokończyć :)
    int j = 0, i = 1;
    while (i < dlt - dlw + 1) {
        while (wzorzec[i] != tekst[i + j] && j < dlw) {
            j++;
        }
        if (j == dlw) {
            return i;
        }
        i = i + std::max(1, j - p[j]);
        j = p[j];
    }
    return NULL;
}

void przydzielPamiec1D(char *&tab, int n) {
    tab = new char[n];
}

void usunTablice1D(char *&tab) {
    delete[] tab;
}

void wypelnijTablice1D(char *tab, int n) {
    for (int i = 0; i < n; i++) {
        std::cin >> tab[i];
    }
    std::cin.clear();
}

void wyswietl1D(int *tab, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << tab[i] << " ";
    }
}
