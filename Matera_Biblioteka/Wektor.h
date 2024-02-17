#pragma once
#include<iostream>

	class Wektor
	{
	protected:
		double x, y;
	public:
		static  Wektor dodawanie(Wektor w1, Wektor w2);
		static Wektor odejmowanie(Wektor w1, Wektor w2);
		static Wektor mnozenie_przez_liczbe(double a, Wektor w);
		static double mnozenie_skalarne(Wektor w1, Wektor w2);
		static double dlugosc_wektora(Wektor w1);
		static double cosinus_wektorow(Wektor w1, Wektor w2);
		Wektor();
		Wektor(double wartosc_x, double wartosc_y);
		friend std::ostream& operator<<(std::ostream& os, Wektor& w);
		virtual std::string pisz();
		double getX();
		double getY();
		void setX(double wartosc_x);
		void setY(double wartosc_y);
		Wektor operator+(Wektor w);
		Wektor operator-(Wektor w);
		double operator*(Wektor w);
		Wektor operator*(double a);
		virtual double dlugosc();
	};

