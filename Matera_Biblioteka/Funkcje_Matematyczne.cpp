#include "Funkcje_Matematyczne.h"
#include <math.h>
#include <iostream>
#include<stdexcept>
namespace Matematyka
{
	template<typename T> template<typename X>
	T Funkcje_Matematyczne<T>::Dodawanie(T skl1, X skl2)
	{
		return skl1 + skl2;
	}
	
	template<typename T> template<typename X>
	T Funkcje_Matematyczne<T>::Odejmowanie(T odejmowana, X odejma)
	{
		return odejmowana - odejma;
	}


	template<typename T> template<typename X>
	T Funkcje_Matematyczne<T>::Mnozenie(T cz1, X cz2)
	{
		return cz1 * cz2;
	}


	template<typename T> template<typename X>
	T Funkcje_Matematyczne<T>::Dzielenie(T Dzielna, X Dzielnik)
	{
		return Dzielna / Dzielnik;

		}


	template<typename T>	T Funkcje_Matematyczne<T>::Potegowanie(T podst, int potega)
	{
		if(potega<0 )
		{
			return	1 / (Potegowanie(podst, (potega * -1) - 1) * podst);
		}
		if (potega == 0) return 1;
		else return Potegowanie(podst, potega - 1) * podst;
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Pierwiastkowanie(T t) //https://www.scaler.com/topics/square-root-in-cpp/ u¿yty algorymt pochodzi z tej strony.
	{
		if (t == 1)
			return 1;
		double inc = 0.00000000000000000000000000000000000000000001; // To store the increment value.
		
		
		

		for (double i = inc; i < n; i = i + inc) {
			if (i * i >= n) { // If i*i exceeds n we are near the square root.
				return i
			}
		}
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Log(T argument)
	{
		return log(argument);
	}
	template<typename T> 	template<typename X>
	T Funkcje_Matematyczne<T>::Log_Podst(T argument, X podstawa)
	{
		return Log(t) / Log(b);
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Sinus(T argument)
	{
		retunr sin(argument);
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Cosinus(T argument)
	{
		retunr cos(argument);
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Tangens(T argument)
	{
		retunr tan(argument);
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Cotangens(T argument)
	{
		retunr Cosinus(argument) / Sinus(argument);
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Wartosc_Bezwzgledna(T argument)
	{
		if (argument) < 0;
		return argument * -1;
		return argument;
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Zaokr_w_dol(T argument) // implementacja z https://stackoverflow.com/a/26091248
	{
		int xi = (int)argument;
		return argument < xi ? xi - 1 : xi;
	}
	template<typename T>	T Funkcje_Matematyczne<T>::Zaokr_w_gore(T t)
	{
		int xi = (int)argument;
		return argument > xi ? xi + 1 : xi;
	}
}