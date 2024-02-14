#include "OperacjeNaBitach.h"
namespace Matematyka {

    bool OperacjeNaBitach::getBit(int liczba, int pozycja) {
        return (liczba & (1 << pozycja)) != 0;
    }
    void OperacjeNaBitach::setBit(int& liczba, int pozycja, bool value) {
        if (value) {
            liczba |= (1 << pozycja);
        }
        else {
            liczba &= ~(1 << pozycja);
        }
    }
    void OperacjeNaBitach::toggleBit(int& liczba, int pozycja) {
        liczba ^= (1 << pozycja);
    }
    void OperacjeNaBitach::clearBit(int& liczba, int pozycja) {
        liczba &= ~(1 << pozycja);
    }
    int OperacjeNaBitach::countSetBits(int liczba) {
        int count = 0;
        while (liczba) {
            count += liczba & 1;
            liczba >>= 1;
        }
        return count;
    }
    std::vector<int> OperacjeNaBitach::getSetBitPositions(int liczba) {
        std::vector<int> pozycje;
        int position = 0;
        while (liczba) {
            if (liczba & 1) {
                pozycje.push_back(position);
            }
            liczba >>= 1;
            ++position;
        }
        return pozycje;
    }
}