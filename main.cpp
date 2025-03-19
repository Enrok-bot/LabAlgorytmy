#include <iostream>
#include <fstream>

struct student {
    std::string imie;
    std::string nazwisko;
    int punkty{};
};

void sortowanieQuickSort(student *tab, int n, int tryb);

void quickSort(student *tab, int n, int tryb);

void wczytajStudentow(student *&tab, int n);

void usunTabliceStudentow(student *&tab);

void wyswietlStudentow(student *tab, int n);

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

    sortowanieQuickSort(studenci, liczbaStudentow, 1);

    wyswietlStudentow(studenci, liczbaStudentow);

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
void quickSort(student *tab, int left, int right, int tryb) {
    int i = left, j = right;
    int pivot = tab[(left + right) / 2].punkty;

    while (i <= j) {
        if (tryb == 0) { // Rosnąco
            while (tab[i].punkty < pivot) i++;
            while (tab[j].punkty > pivot) j--;
        } else { // Malejąco
            while (tab[i].punkty > pivot) i++;
            while (tab[j].punkty < pivot) j--;
        }

        if (i <= j) {
            std::swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(tab, left, j, tryb);
    if (i < right) quickSort(tab, i, right, tryb);
}
void sortowanieQuickSort(student *tab, int n, int tryb) {
    quickSort(tab, 0, n - 1, tryb);
}