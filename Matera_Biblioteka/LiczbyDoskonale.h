#pragma once
#include <vector>

    class LiczbyDoskonale
    {
        std::vector<bool> doskonaleTablica;
    public:
        LiczbyDoskonale(int max = 1000000);
        bool czyDoskonala(int n);
        std::vector<int> liczbyDoskonaleDo(int max);
    };

