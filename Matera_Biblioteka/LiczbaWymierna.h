#pragma once
#include <ostream>
namespace Matematyka {
    class LiczbaWymierna
    {
        int licznik;
        int mianownik;
    public:
        LiczbaWymierna(int licznik = 0, int mianownik = 1);
        void skroc();
        LiczbaWymierna operator+(const LiczbaWymierna& other) const;
        LiczbaWymierna operator-(const LiczbaWymierna& other) const;
        LiczbaWymierna operator*(const LiczbaWymierna& other) const;
        LiczbaWymierna operator/(const LiczbaWymierna& other) const;
        friend std::ostream& operator<<(std::ostream& out, const LiczbaWymierna& liczba);
    };

}