#include "Wektor.h"
#include <math.h>
#include<string>
namespace Matematyka {
	Wektor::Wektor():x(0),y(0)
	{
		
	}
	Wektor::Wektor(double wartosc_x, double wartosc_y):x(wartosc_x),y(wartosc_y)
	{

	}
	Wektor  Wektor::dodawanie(Wektor w1, Wektor w2)
	{
		Wektor w((w1.x + w2.x), (w1.y + w2.y));
		return w;
	}
	double Wektor::dlugosc_wektora(Wektor w)
	{
		return sqrt(w.x * w.x + w.y * w.y);
	}std::string Wektor::pisz()
	{
		std::string s = "Wektor: ";
		s += " x: " + std::to_string(x) + " y: " + std::to_string(y);
		return s;
	}
	std::ostream& operator<<(std::ostream& os, Wektor& w)
	{
		
		os << w.pisz();
		return os;
	}
	double Wektor::cosinus_wektorow(Wektor w1, Wektor w2)
	{
		double top = (w1.x * w2.x + w1.y * w2.y);
		
		double bot = (sqrt(w1.x * w1.x + w1.y * w1.y) * sqrt(w2.x * w2.x + w2.y * w2.y));
		return top / bot;
	}
	Wektor Wektor::odejmowanie(Wektor w1, Wektor w2) {
		Wektor w((w1.x - w2.x), (w1.y - w2.y));
		return w;
	 }
	Wektor Wektor::mnozenie_przez_liczbe(double a, Wektor w)
	{
		Wektor ww((a * w.x), (a * w.y));
		return ww;
	 }
	double Wektor::mnozenie_skalarne(Wektor w1, Wektor w2)
	{
		double a = dlugosc_wektora(w1) * dlugosc_wektora(w2) * cosinus_wektorow(w1, w2);
		return a;
	}
}	




