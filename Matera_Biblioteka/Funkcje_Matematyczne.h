#pragma once
namespace Matematyka {
	template<typename T>
	class Funkcje_Matematyczne
	{
		template<typename X>
		T Dodawanie(T t, X x);
		template<typename X>
		T Odejmowanie(T t, X x);
		template<typename X>
		T Mnozenie(T t, X x);
		template<typename X>
		T Dzielenie(T t, X x);
		T Potegowanie(T t,int x);
		T Pierwiastkowanie(T t);
		T Log(T t);
		template<typename X>
		T Log_Podst(T t, X x);
		T Sinus(T t);
		T Cosinus(T t);
		T Tangens(T t);
		T Cotangens(T t);
		T Wartosc_Bezwzgledna(T t);
		T Zaokr_w_dol(T t);
		T Zaokr_w_gore(T t);
	};

}