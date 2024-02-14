#pragma once
#include <random>
namespace Matematyka {
    class GeneratorLiczbLosowych
    {
        std::mt19937 generator;
    public:
        GeneratorLiczbLosowych();
        int losujLiczbeCalkowita(int min, int max);
        double losujLiczbeZmiennoprzecinkowa(double min, double max);
        double losujZNormalnegoRozkladu(double srednia, double odchylenie);
    };

}