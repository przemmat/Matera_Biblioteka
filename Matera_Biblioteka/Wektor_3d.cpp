#include "Wektor_3d.h"
#include <math.h>
#include <string>

	Wektor_3d::Wektor_3d() :Wektor(), z(0)
	{

	}
	Wektor_3d::Wektor_3d(double wartosc_x, double wartosc_y, double wartosc_z) :Wektor(wartosc_x, wartosc_y), z(wartosc_z)
	{

	}
	Wektor_3d::Wektor_3d(Wektor w, double wartosc_z) :Wektor(w), z(wartosc_z)
	{

	}
	Wektor_3d Wektor_3d::dodawanie(Wektor_3d w1, Wektor_3d w2)
	{

		Wektor_3d wynik(Wektor::dodawanie(w1, w2), (w1.z + w2.z));
		return wynik;

	}
	Wektor_3d Wektor_3d::odejmowanie(Wektor_3d w1, Wektor_3d w2)
	{
		Wektor_3d wynik(Wektor::odejmowanie(w1, w2), (w1.z - w2.z));
		return wynik;
	}
	Wektor_3d Wektor_3d::mnozenie_przez_liczbe(double a, Wektor_3d w)
	{
		Wektor_3d wynik(Wektor::mnozenie_przez_liczbe(a, w), (w.z * a));
		return wynik;
	}
	double Wektor_3d::mnozenie_skalarne(Wektor_3d w1, Wektor_3d w2)
	{
		double a = dlugosc_wektora(w1) * dlugosc_wektora(w2) * cosinus_wektorow(w1, w2);
		return a;
	}
	Wektor_3d Wektor_3d::mnozenie_wektorowe(Wektor_3d w1, Wektor_3d w2)
	{
		Wektor_3d wynik((w1.y * w2.z - w1.z * w2.y), (w1.z * w2.x - w1.x * w2.z), (w1.x * w2.y - w1.y * w2.x));
		return wynik;
	}
	double Wektor_3d::dlugosc_wektora(Wektor_3d w)
	{
		return sqrt(w.x * w.x + w.y * w.y + w.z * w.z);
	}
	std::string Wektor_3d::pisz()
	{
		std::string s = Wektor::pisz();
		s += " z: " + std::to_string(z);
		return s;
	}
	std::ostream& operator<<(std::ostream& os, Wektor_3d& w)
	{
		
		os << w.pisz();
		return os;
	}
	 double Wektor_3d::cosinus_wektorow(Wektor_3d w1, Wektor_3d w2)
	{
		 double top = w1.x * w2.x + w1.y * w2.y + w1.z * w2.z;
		 double bot = (sqrt(w1.x * w1.x + w1.y * w1.y + w1.z * w1.z) * sqrt(w2.x * w2.x + w2.y * w2.y + w2.z * w2.z));
		 return top / bot;
	}

	 void Wektor_3d::setZ(double wartosc_z)
	 {
		 z = wartosc_z;
	 }
	 double Wektor_3d::getZ()
	 {
		 return z;
	 }
	  Wektor_3d Wektor_3d::operator+(Wektor_3d w)
	 {
		 return dodawanie(*this, w);
	 }
	  Wektor_3d Wektor_3d::operator-(Wektor_3d w)
	 {
		 return odejmowanie(*this, w);
	 }
	  double Wektor_3d::operator*(Wektor_3d w)
	 {
		 return mnozenie_skalarne(*this, w);
	 }
	  Wektor_3d Wektor_3d::operator*(double a)
	 {
		 return mnozenie_przez_liczbe(a, *this);
	 }
	  double Wektor_3d::dlugosc()
	 {
		 return dlugosc_wektora(*this);
	 }
	 Wektor_3d Wektor_3d::mnozenie_wektor(Wektor_3d w1)
	 {
		 return mnozenie_wektorowe(*this, w1);
	 }