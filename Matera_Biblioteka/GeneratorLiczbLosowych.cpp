#include "GeneratorLiczbLosowych.h"

    GeneratorLiczbLosowych::GeneratorLiczbLosowych() : generator(std::random_device{}()) {}

    int GeneratorLiczbLosowych::losujLiczbeCalkowita(int min, int max) {
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(generator);
    }

    double GeneratorLiczbLosowych::losujLiczbeZmiennoprzecinkowa(double min, double max) {
        std::uniform_real_distribution<double> distribution(min, max);
        return distribution(generator);
    }

    double GeneratorLiczbLosowych::losujZNormalnegoRozkladu(double srednia, double odchylenie) {
        std::normal_distribution<double> distribution(srednia, odchylenie);
        return distribution(generator);
    }
