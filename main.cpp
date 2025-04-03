#include <cmath>
#include <fstream>
#include <iostream>

void przydzielPamiec1D(char *&tab, int n);

void usunTablice1D(char *&tab);

void wypelnijTablice1D(char *tab, int n);

void wyswietl1D(int *tab, int n);

int naiwny(char *tekst, char *wzorzec, int dlt, int dlw);

void zbudujTabliceDostosowan(char *wzorzec, int dlw, int *p);

int kmp(char *wzorzec, char *tekst, int dlw, int dlt, int *p);

int wczytajWzorzec(char *&tab);

int tworzenieHash(std::string *wzorzec, int off, int dlw);


int main() {
    std::string *wzorzec = nullptr;
    int dlw = wczytajWzorzec(wzorzec);

    std::cout << wzorzec << std::endl;
    std::cout << dlw << std::endl;



    std::cout << tworzenieHash(wzorzec,65,dlw) << std::endl;
}

int wczytajWzorzec(char *&tab) {
    std::string dlw;
    std::ifstream data("tekst.txt");
    std::getline(data, dlw);
    int n = dlw.length();
    tab = dlw.c_str();
    data.close();
    return n;
}

void wczytajTekst(char *&tekst) {
    std::string linia;
    std::ifstream data("tekst.txt");
    while (std::getline(data, linia)) {

    }
}

// char *tekst, *wzorzec;
// przydzielPamiec1D(tekst,15);
// przydzielPamiec1D(wzorzec,3);
// std::cout << "Podaj tekst: ";
// wypelnijTablice1D(tekst,15);
// std::cout << "Podaj wzorzec: ";
// wypelnijTablice1D(wzorzec,3);
//
// std::cout << "Tekst: " << tekst << std::endl;
// std::cout << "Wzorzec: " << wzorzec << std::endl;
//
// // std::cout << naiwny(tekst,wzorzec,15,3) << std::endl;
// return 0;

int tworzenieHash(char *wzorzec, int off, int dlw) {
    int hash = 0;
    for (int i = 0; i < dlw; i++) {
        hash += ((int) wzorzec[i] - off) * pow(256-off, dlw - 1 + i - dlw);
    }
    return hash;
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

int kmp(char *wzorzec, char *tekst, int dlw, int dlt, int *p) {
    //Do dokończenia :)
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

void BM() {
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
