#pragma once
#include <math.h>
#define PI 3.14159265

	template<typename T>
	class Funkcje_Matematyczne
	{
		static 	double deg_na_rad(T t);
	public:
		template <typename X>
		static	T Dodawanie(T t, X x);
		template <typename X>
		static	T Odejmowanie(T t, X x);
		template <typename X>
		static	T Mnozenie(T t, X x);
		template <typename X>
		static	T Dzielenie(T t, X x);
		static	T Potegowanie(T t,int x);
		static	T Pierwiastkowanie(T t);
		static	T Log(T t);
		template <typename X>
		static	T Log_Podst(T t, X x);
		static	T Sinus(T t);
		static	T Cosinus(T t);
		static	T Tangens(T t);
		static	T Cotangens(T t);
		static	T Wartosc_Bezwzgledna(T t);
		static	T Zaokr_w_dol(T t);
		static	T Zaokr_w_gore(T t);
	};
	template<typename T>
	double Funkcje_Matematyczne<T>::deg_na_rad(T t)
	{
		return t * PI / 180;
	}

	template<typename T> template <typename X>
	T Funkcje_Matematyczne<T>::Dodawanie(T skl1, X skl2)
	{
		return skl1 + skl2;
	}

	template<typename T> template <typename X>
	T Funkcje_Matematyczne<T>::Odejmowanie( T odejmowana,  X odejma)
	{
		
		return odejmowana - odejma ;
	}


	template<typename T> template <typename X>
	T Funkcje_Matematyczne<T>::Mnozenie(T cz1, X cz2)
	{
		return cz1 * cz2;
	}


	template<typename T> template <typename X>
	T Funkcje_Matematyczne<T>::Dzielenie(T Dzielna, X Dzielnik)
	{
		return Dzielna / Dzielnik;

	}


	template<typename T>	T Funkcje_Matematyczne<T>::Potegowanie(T podst, int potega)
	{
		if (potega < 0)
		{
			return	1 / (Potegowanie(podst, (potega * -1) - 1) * podst);
		}
		if (potega == 0) return 1;
		else return Potegowanie(podst, potega - 1) * podst;
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Pierwiastkowanie(T argument) //https://www.scaler.com/topics/square-root-in-cpp/ uzyty algorymt pochodzi z tej strony.
	{
		if (argument == 1)
			return 1;
		double inc = 0.00000000000000000000000000000000000000000001; // To store the increment value.

		for (double i = inc; i < argument; i = i + inc)
		{
			if (i * i >= argument) { // If i*i exceeds n we are near the square root.
				return i;
			}
		}
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Log(T argument)
	{
		return log(argument);
	}
	template<typename T> 	template <typename X>
	T Funkcje_Matematyczne<T>::Log_Podst(T argument, X podstawa)
	{
		return Log(argument) / Log(podstawa);
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Sinus(T argument)
	{
		return sin(deg_na_rad(argument));
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Cosinus(T argument)
	{
		return cos(deg_na_rad(argument));
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Tangens(T argument)
	{
		return tan(deg_na_rad(argument));
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Cotangens(T argument)
	{
		return Cosinus(argument) / Sinus(argument);
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Wartosc_Bezwzgledna(T argument)
	{
		if (argument < 0)
			return argument * -1;
		return argument;
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Zaokr_w_dol(T argument) 
	{
		int xi = (int)argument;
		return argument < xi ? xi - 1 : xi;
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Zaokr_w_gore(T argument)
	{
		int xi = (int)argument;
		return argument > xi ? xi + 1 : xi;
	}
