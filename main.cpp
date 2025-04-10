#include <fstream>
#include <iostream>
#include <bits/fs_path.h>

struct student {
    std::string imie;
    std::string nazwisko;
    int ocena{};
};

void wyswietl1D(int *tab, int n);

void wczytajStudentow(student *&tab, int n);

void wypelnijTablice1D(int *tab, int n);

void przydzielPamiec1D(int *&tab, int n);

int wyszukiwanieLiniowe(int *tab, int n, int wartosc);

int wyszukiwanieBisekcyjne(student *tab, int prawy, int watrosc, int lewy = 0);

void sortowanieStudentow(student *&tab, int n);

int liczbaPunktow(student *&tab, int n, int wartosc);


int main() {
    std::ifstream data("studenci.csv");
    std::string line;
    std::getline(data, line);
    const int liczbaStudentow = std::stoi(line);
    data.close();

    student *studenci = nullptr;
    wczytajStudentow(studenci, liczbaStudentow);

    sortowanieStudentow(studenci, liczbaStudentow);

    student *tab = nullptr;

    int punkty = 5;
    int liczbaPunktow1 = liczbaPunktow(studenci, liczbaStudentow, punkty);
    tab = new student[liczbaPunktow1];

    sortowanieStudentow(studenci, liczbaStudentow);

    for (int i = 0; i < liczbaPunktow1; i++) {
        tab[i] = studenci[wyszukiwanieBisekcyjne(studenci, liczbaStudentow, punkty)];
    }

    std::cout << tab[0].imie << std::endl;
    std::cout << wyszukiwanieBisekcyjne(tab, liczbaStudentow, 5);

    std::ofstream zapis;
    std::string sciezkaDoZapisu = "wyniki.csv";
    zapis.open(sciezkaDoZapisu);
    zapis << liczbaStudentow << std::endl;
    for (int i = 0; i < liczbaStudentow; i++) {
        zapis << tab[i].imie << ";" << tab[i].nazwisko << ";";
        zapis << tab[i].ocena << std::endl;
    }
    zapis.close();
}

int liczbaPunktow(student *&tab, int n, int wartosc) {
    int ile = 0;
    for (int i = 0; i < n; i++) {
        if (tab[i].ocena == wartosc) ile++;
    }
    return ile;
}

int wyszukiwanieBisekcyjne(student *tab, int prawy, int watrosc, int lewy) {
    int srodek = (lewy + prawy) / 2;
    if (lewy > prawy) return -1;
    if (tab[srodek].ocena == watrosc) {
        tab[srodek].ocena = -1;
        return srodek;
    }
    if (watrosc < tab[srodek].ocena) return wyszukiwanieBisekcyjne(tab, srodek - 1, watrosc, lewy);
    return wyszukiwanieBisekcyjne(tab, prawy, watrosc, srodek + 1);
}

int wyszukiwanieLiniowe(int *tab, int n, int wartosc) {
    n--;
    while (n >= 0) {
        if (tab[n] == wartosc) return n;
        n--;
    }
    return -1;
}

void przydzielPamiec1D(int *&tab, int n) {
    tab = new int[n];
}

void wczytajStudentow(student *&tab, int n) {
    std::string imie, nazwisko, punkty;
    std::ifstream data("studenci.csv");
    std::getline(data, imie);
    tab = new student[n];
    for (int i = 0; i < n; i++) {
        std::getline(data, imie, ';');
        tab[i].imie = imie;
        std::getline(data, nazwisko, ';');
        tab[i].nazwisko = nazwisko;
        std::getline(data, punkty);
        tab[i].ocena = std::stoi(punkty);
    }
    data.close();
}

void wypelnijTablice1D(int *tab, int n) {
    for (int i = 0; i < n; i++) {
        tab[i] = i * 2;
    }
}

void wyswietl1D(int *tab, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << tab[i] << " ";
    }
}

void sortowanieStudentow(student *&tab, int n) {
    bool sort = true;
    while (sort) {
        sort = false;
        for (int i = 0; i < n - 1; i++) {
            if (tab[i].ocena > tab[i + 1].ocena) {
                sort = true;
                std::swap(tab[i], tab[i + 1]);
            }
        }
    }
}
