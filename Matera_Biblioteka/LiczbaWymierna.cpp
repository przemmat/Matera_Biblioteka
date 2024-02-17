#include "LiczbaWymierna.h"
#include <algorithm>

    int NajwiekszyWspolnyDzielnik(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    LiczbaWymierna::LiczbaWymierna(int licznik, int mianownik) : licznik(licznik), mianownik(mianownik) {
        skroc();
    }

    void LiczbaWymierna::skroc() {
        int dziel = NajwiekszyWspolnyDzielnik(abs(licznik), abs(mianownik));
        licznik /= dziel;
        mianownik /= dziel;
    }

    LiczbaWymierna LiczbaWymierna::operator+(const LiczbaWymierna& l2) const {
        int newLicznik = licznik * l2.mianownik + l2.licznik * mianownik;
        int newMianownik = mianownik * l2.mianownik;
        return LiczbaWymierna(newLicznik, newMianownik);
    }

    LiczbaWymierna LiczbaWymierna::operator-(const LiczbaWymierna& l2) const {
        int newLicznik = licznik * l2.mianownik - l2.licznik * mianownik;
        int newMianownik = mianownik * l2.mianownik;
        return LiczbaWymierna(newLicznik, newMianownik);
    }

    LiczbaWymierna LiczbaWymierna::operator*(const LiczbaWymierna& l2) const {
        int newLicznik = licznik * l2.licznik;
        int newMianownik = mianownik * l2.mianownik;
        return LiczbaWymierna(newLicznik, newMianownik);
    }

    LiczbaWymierna LiczbaWymierna::operator/(const LiczbaWymierna& l2) const {
        int newLicznik = licznik * l2.mianownik;
        int newMianownik = mianownik * l2.licznik;
        return LiczbaWymierna(newLicznik, newMianownik);
    }

    std::ostream& operator<<(std::ostream& os, const LiczbaWymierna& liczba) {
        os << liczba.licznik;
        if (liczba.mianownik != 1) {
            os << "/" << liczba.mianownik;
        }
        return os;
    }
