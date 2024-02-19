#include "LiczbyDoskonale.h"

    LiczbyDoskonale::LiczbyDoskonale(int max) {
        doskonaleTablica.resize(max + 1, false);
        for (int i = 2; i <= max; ++i) {
            int sum = 1;
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    sum += j;
                    if (j * j != i) {
                        sum += i / j;
                    }
                }
            }
            doskonaleTablica[i]= sum == i && i != 1;
            }
        }
    

    bool LiczbyDoskonale::czyDoskonala(int n) {
        if(n < 0 || n >= doskonaleTablica.size()) return false;
        return doskonaleTablica[n];
    }

    std::vector<int> LiczbyDoskonale::liczbyDoskonaleDo(int max) {
        std::vector<int> wynik;
        for (int i = 2; i <= max; ++i) {
            if (doskonaleTablica[i]) {
                wynik.push_back(i);
            }
        }
        return wynik;
    }
