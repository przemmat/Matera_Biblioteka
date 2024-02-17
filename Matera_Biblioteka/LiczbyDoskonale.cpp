#include "LiczbyDoskonale.h"

    LiczbyDoskonale::LiczbyDoskonale(int max) {
        doskonaleTablica.resize(max + 1, false);
        for (int i = 2; i <= max; ++i) {
            if (czyDoskonala(i)) {
                doskonaleTablica[i] = true;
            }
        }
    }

    bool LiczbyDoskonale::czyDoskonala(int n) {
        int sum = 1;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                sum += i;
                if (i * i != n) {
                    sum += n / i;
                }
            }
        }
        return sum == n && n != 1;
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
