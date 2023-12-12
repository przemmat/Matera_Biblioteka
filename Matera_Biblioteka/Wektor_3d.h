#pragma once
#include "Wektor.h"
namespace Matematyka {
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
		void setZ(double wartosc_z)
		{
			z = wartosc_z;
		}
		double getZ()
		{
			return z;
		}
		virtual Wektor_3d operator+(Wektor_3d w)
		{
			return dodawanie(*this, w);
		}
		virtual Wektor_3d operator-(Wektor_3d w)
		{
			return odejmowanie(*this, w);
		}
		virtual double operator*(Wektor_3d w)
		{
			return mnozenie_skalarne(*this, w);
		}
		virtual Wektor_3d operator*(double a)
		{
			return mnozenie_przez_liczbe(a, *this);
		}
		virtual double dlugosc()
		{
			return dlugosc_wektora(*this);
		}
		Wektor_3d mnozenie_wektor(Wektor_3d w1)
		{
			return mnozenie_wektorowe(*this, w1);
		}
	};
    };


