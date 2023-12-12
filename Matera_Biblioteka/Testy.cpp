#include "Testy.h"
#include"Funkcje_Matematyczne.h"
#include <iostream>
using namespace std;
namespace Matematyka {
	bool AreSame(double a, double b)
	{
		return fabs(a - b) < 0.00001;
	}
	void test_Dodawanie()
	{
		 
		cout << "\ntest dodwania liczb:";
		if ((Funkcje_Matematyczne<int>::Dodawanie(1, 2) == 3))
			cout << "ok";
		else cout << "fail";
		cout << "\ntest dodwania tekstu:";
		if (Funkcje_Matematyczne<string>::Dodawanie("1", "2") == "12")
			cout << "ok";
		else cout << "fail";
	}
	void test_Odejmowanie()
	{
		
		cout << "\ntest odejmowania liczb:";
		if ((Funkcje_Matematyczne<int>::Odejmowanie(1, 2) == ( - 1)))
			cout << "ok";
		else cout << "fail";
	

		
	}
	void test_Mnozenie()
	{
		cout << "\ntest mnozenia liczb:";
		if ((Funkcje_Matematyczne<int>::Mnozenie(4, 2) == 8))
			cout << "ok";
		else cout << "fail";


		
	}
	void test_dzielenie()
	{
		cout << "\ntest dzielenia liczb:";
		if ((Funkcje_Matematyczne<int>::Dzielenie(4, 2) == 2))
			cout << "ok";
		else cout << "fail";
		

		
	}
	void test_Potegowanie()
	{
		cout << "\ntest potegowania liczb dodatnich:";
		if ((Funkcje_Matematyczne<int>::Potegowanie(4, 5) == 1024))
			cout << "ok";
		else cout << "fail";
		cout << "\ntest potegowania liczb ujemnych:";
		if ((Funkcje_Matematyczne<int>::Potegowanie(4, -5) == 1/1024))
			cout << "ok";
		else cout << "fail";
	
	}
	void test_Pierwiastkowanie()
	{
		cout << "\ntest pierwiastkowania liczb:";
		if ((Funkcje_Matematyczne<int>::Pierwiastkowanie(16) == 4))
			cout << "ok";
		else cout << "fail";
	}
	void test_Log()
	{
		cout << "\ntest log liczb:\n dla 1:";
		if ((Funkcje_Matematyczne<int>::Log(1) == 0))
		{
			
				cout << "ok";
			
		}
		else cout << "fail";
		cout << "\n dla 10:";
		if (Funkcje_Matematyczne<double>::Log(10) == log(10))
			cout << "ok";
		else cout << "fail";
	}
	void test_Log_Podst()
	{
		cout << "\ntest log z podstawa liczb:";
		if ((Funkcje_Matematyczne<float>::Log_Podst(1000, 10) == 3))
		{

			cout << "ok";

		}
		else cout << "fail";
		
	}
	void test_Sinus()
	{
		cout << "\ntest sin liczb:";

		if (AreSame( Funkcje_Matematyczne<double>::Sinus(30) , 0.5))
			cout << "ok";
		else cout << "fail";
	}
	void test_Cosinus()
	{
		cout << "\ntest cos liczb:";
		if (AreSame (Funkcje_Matematyczne<double>::Cosinus(180) , -1))
			cout << "ok";
		else cout << "fail";
	}
	void test_Tangens()
	{
		cout << "\ntest tng liczb:";
		if (AreSame(Funkcje_Matematyczne<double>::Tangens(45) ,1))
			cout << "ok";
		else cout << "fail";
	}
	void test_Cotangens()
	{
		cout << "\ntest ctng liczb:";
		if (AreSame (Funkcje_Matematyczne<double>::Cotangens(45) , 1))
			cout << "ok";
		else cout << "fail";
	}
	void test_Wartosc_Bez()
	{
		cout << "\ntest bezwzgl liczby dodatniej:";
		if (Funkcje_Matematyczne<int>::Wartosc_Bezwzgledna(45)== 45)
			cout << "ok";
		else cout << "fail";
		cout << "\ntest bezwzgl liczby ujemnej:";
		if (Funkcje_Matematyczne<int>::Wartosc_Bezwzgledna(-45)== 45)
			cout << "ok";
		else cout << "fail";
	}
	void test_zaokr()
	{
		cout << "\ntest zaokraglania w gore:";
		if (Funkcje_Matematyczne<double>::Zaokr_w_gore(44.45685) == 45)
			cout << "ok";
		else cout << "fail";
		cout << "\ntest zaokraglania w dol:";
		if (Funkcje_Matematyczne<double>::Zaokr_w_dol(45.5654) == 45)
			cout << "ok";
		else cout << "fail";
	}
	void Testy::test_Funkcje()
	{
		test_Dodawanie();
		test_Odejmowanie();
		test_dzielenie();
		test_Mnozenie();
		test_Potegowanie();
		test_Log();
		test_Log_Podst();
		test_Sinus();
		test_Cosinus();
		test_Tangens();
		test_Cotangens();
		test_Wartosc_Bez();
		test_zaokr();
	}
}