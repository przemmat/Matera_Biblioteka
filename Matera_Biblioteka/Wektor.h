#pragma once
#include<iostream>
namespace Matematyka {
	class Wektor
	{
	protected:
		double x, y;
	public:
		static Wektor dodawanie(Wektor w1, Wektor w2);
		static Wektor odejmowanie(Wektor w1, Wektor w2);
		static Wektor mnozenie_przez_liczbe(double a, Wektor w);
		static double mnozenie_skalarne(Wektor w1, Wektor w2);
	
		static double dlugosc_wektora(Wektor w1);

		static double cosinus_wektorow(Wektor w1, Wektor w2);
		Wektor();
		Wektor(double wartosc_x, double wartosc_y);
		friend std::ostream& operator<<(std::ostream& os, Wektor& w);
		virtual std::string pisz();
		double getX()
		{
			return x;
		}
		double getY()
		{
			return y;
		}
		void setX(double wartosc_x)
		{
			x = wartosc_x;
		}
		void setY(double wartosc_y)
		{
			y = wartosc_y;
		}
		 Wektor operator+(Wektor w)
		{
			return dodawanie(*this, w);
		}
		 Wektor operator-(Wektor w)
		{
			return odejmowanie(*this, w);
		}
		virtual double operator*(Wektor w)
		{
			return mnozenie_skalarne(*this, w);
		}
		 Wektor operator*(double a)
		{
			return mnozenie_przez_liczbe(a, *this);
		}
		virtual double dlugosc()
		{
			return dlugosc_wektora(*this);
		}
	};

}