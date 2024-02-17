#include "LiczbyPierwsze.h"

LiczbyPierwsze::LiczbyPierwsze(int max )
{
    pierwszeTablica.resize(max + 1, true);
    pierwszeTablica[0] = pierwszeTablica[1] = false;
    for (int i = 2; i * i <= max; ++i) {
        if (pierwszeTablica[i]) {
            for (int j = i * i; j <= max; j += i) {
                pierwszeTablica[j] = false;
            }
        }
    }
}
bool LiczbyPierwsze::czyPierwsza(int n) {
    if (n < 0 || n >= pierwszeTablica.size()) return false;
    return pierwszeTablica[n];
}
std::vector<int> LiczbyPierwsze::liczbyPierwszeDo(int max) {
    std::vector<int> wynik;
    for (int i = 2; i <= max; ++i) {
        if (pierwszeTablica[i]) {
            wynik.push_back(i);
        }
    }
    return wynik;
}