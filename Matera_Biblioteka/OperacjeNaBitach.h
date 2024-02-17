#pragma once
#include <vector>

    class OperacjeNaBitach
    {
    public:
        static bool getBit(int liczba , int pozycja);
        static void setBit(int& liczba, int pozycja, bool wartosc);
        static void toggleBit(int& liczba, int pozycja);
        static void clearBit(int& liczba, int pozycja);
        static int countSetBits(int liczba);
        static std::vector<int> getSetBitPositions(int liczba);
    };

