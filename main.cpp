#include <iostream>
#include <regex>

void sortowanieBabelkowe(int *tab, int n, bool tryb);

void sortowaniePrzezWybor(int *tab, int n, bool tryb);

void sortowaniePrzezWstawianie(int *tab, int n, bool tryb);

void sortowanieBabelkowe2D(int **tab, int w, int k, bool tryb, int nrKol);

int main() {
    int tab[5] = {9, 11, 3, 17, 5};
    // sortowanieBabelkowe(tab, 5, 0);
    // sortowaniePrzezWybor(tab, 5, 1);
    // for (int i = 0; i < 5; i++) {
    //     std::cout << tab[i] << " ";
    // }
    int **tab2;
    tab2 = new int *[5];
    for (int i = 0; i < 5; i++) {
        tab2[i] = new int[5];
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tab2[i][j] = (i + 1) * (j + 1);
        }
    }

    // sortowanieBabelkowe2D(tab2, 5, 5, 1, 3);

    int i = 0;
    while (i < 5) {
        for (int j = 0; j < 5 - 1; j++) {
                if (tab[3][j] > tab[3][j + 1]) {
                    for (int c = 0; c < 5; c++) { std::swap(tab[c][3], tab[c][3]); }
                }
            }
        }
        i++;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << tab2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
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

void sortowaniePrzezWybor(int *tab, int n, int tryb) {
    int tab2[5];
    for (int i = 0; i < n; i++) {
        int min = tab[i];
        for (int j = i + 1; j < n; j++) {
            if (tryb) {
                if (tab[j] < min) {
                    std::swap(min, tab[j]);
                }
            } else {
                if (tab[j] > min) {
                    std::swap(min, tab[j]);
                }
            }
        }
        tab2[i] = min;
    }
    for (int i = 0; i < 5; i++) {
        tab[i] = tab2[i];
    }
}

void sortowaniePrzezWstawianie(int *tab, int n, int tryb) {
}

void sortowanieBabelkowe2D(int **tab, int w, int k, int tryb, int nrKol) {
    int i = 0;
    while (i < k) {
        for (int j = 0; j < k - 1; j++) {
            if (tryb) {
                if (tab[nrKol][j] > tab[nrKol][j + 1]) {
                    for (int c = 0; c < w; c++) { std::swap(tab[c][nrKol], tab[c][nrKol]); }
                }
            } else {
                if (tab[j] < tab[j + 1]) {
                    for (int c = 0; c < w; c++) { std::swap(tab[c][nrKol], tab[c][nrKol]); }
                }
            }
        }
        i++;
    }
}
