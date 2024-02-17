#pragma once
#include "Wektor.h"

    class Wektor_3d :
        public Wektor
    {
    protected: double z;
    public:
		static Wektor_3d dodawanie(Wektor_3d w1, Wektor_3d w2);
		static Wektor_3d odejmowanie(Wektor_3d w1, Wektor_3d w2);
		static Wektor_3d mnozenie_przez_liczbe(double a, Wektor_3d w);
		static double mnozenie_skalarne(Wektor_3d w1, Wektor_3d w2);
		static Wektor_3d mnozenie_wektorowe(Wektor_3d w1, Wektor_3d w2);
		static double dlugosc_wektora(Wektor_3d w1);
		static double cosinus_wektorow(Wektor_3d w1, Wektor_3d w2);
		Wektor_3d();
		Wektor_3d(double wartosc_x, double wartosc_y, double wartosc_z);
		Wektor_3d(Wektor w, double wartosc_z);
		virtual std::string pisz();
		friend std::ostream& operator<<(std::ostream& os, Wektor_3d& w);
		void setZ(double wartosc_z);
		double getZ();
		Wektor_3d operator+(Wektor_3d w);
		Wektor_3d operator-(Wektor_3d w);
		double operator*(Wektor_3d w);
		Wektor_3d operator*(double a);
		virtual double dlugosc();
		Wektor_3d mnozenie_wektor(Wektor_3d w1);
	};
    