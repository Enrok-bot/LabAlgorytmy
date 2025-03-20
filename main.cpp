#include <iostream>
#include <fstream>

struct student {
    std::string imie;
    std::string nazwisko;
    int punkty{};
};

void wczytajStudentow(student *&tab, int n);

void usunTabliceStudentow(student *&tab);

void wyswietlStudentow(student *tab, int n);

void wyswietlStudentow2(student *tab, int n, int granica);

void wyswietlStudentow3(student *tab, int n, int granica1, int granica2);

int sortowanieFlagaPolski(student *&tab, int n);

int sortowanieFlagaWloch(student *&tab, int n);

int main() {
    std::ifstream data("studenci.csv");
    std::string line;
    std::getline(data, line);
    const int liczbaStudentow = std::stoi(line);
    data.close();

    student *studenci = nullptr;
    wczytajStudentow(studenci, liczbaStudentow);

    wyswietlStudentow(studenci, liczbaStudentow);

    std::cout << std::endl;

    wyswietlStudentow2(studenci, liczbaStudentow, sortowanieFlagaPolski(studenci, liczbaStudentow));

    int granice = sortowanieFlagaWloch(studenci, liczbaStudentow);

    wyswietlStudentow3(studenci, liczbaStudentow, granice % liczbaStudentow, granice / liczbaStudentow);

    usunTabliceStudentow(studenci);
    return 0;
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
        tab[i].punkty = std::stoi(punkty);
    }
    data.close();
}

void usunTabliceStudentow(student *&tab) {
    delete[] tab;
    tab = nullptr;
}

void wyswietlStudentow(student *tab, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << std::endl;
    }
}

void wyswietlStudentow2(student *tab, int n, int granica) {
    int i = 0;
    std::cout << std::endl << "Studenci, ktorzy otrzymali <=10 punktow:" << std::endl;
    for (; i < granica; i++) {
        std::cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << std::endl;
    }
    std::cout << std::endl << "Studenci, ktorzy otrzymali >10 punktow:" << std::endl;
    for (; i < n; i++) {
        std::cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << std::endl;
    }
}

void wyswietlStudentow3(student *tab, int n, int granica1, int granica2) {
    int i = 0;
    std::cout << std::endl << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3:" << std::endl;
    for (; i < granica1; i++) {
        std::cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << std::endl;
    }
    std::cout << std::endl << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 1:" << std::endl;

    for (; i < granica2; i++) {
        std::cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << std::endl;
    }
    std::cout << std::endl << "Studenci, ktorzy otrzymali liczbe punktow podzielnych przez 3 z reszta 2:" << std::endl;
    for (; i < n; i++) {
        std::cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << std::endl;
    }
}

int sortowanieFlagaPolski(student *&tab, int n) {
    int l = 0, p = n - 1;

    while (l <= p) {
        while (l < n && tab[l].punkty <= 10) {
            l++;
        }
        while (p >= 0 && tab[p].punkty > 10) {
            p--;
        }
        if (p > l) {
            std::swap(tab[l], tab[p]);
        }
    }
    return l;
}

int sortowanieFlagaWloch(student *&tab, int n) {
    int l = 0, m = 0, p = n - 1;
    while (m <= p) {
        if (tab[m].punkty % 3 == 0) {
            std::swap(tab[l], tab[m]);
            l++;
            m++;
        } else if (tab[m].punkty % 3 == 1) {
            m++;
        } else {
            std::swap(tab[m], tab[p]);
            p--;
        }
    }
    return m * n + l;
}
