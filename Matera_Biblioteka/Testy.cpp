#include "Testy.h"
#include"Funkcje_Matematyczne.h"
#include <iostream>
#include "LiczbaWymierna.h"
#include "OperacjeNaBitach.h"
#include "GeneratorLiczbLosowych.h"
#include "LiczbyDoskonale.h"
#include "LiczbyPierwsze.h"
#include "Macierz.h"
#include"Wektor.h"
#include"Wektor_3d.h"
using namespace std;

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
		cout << "Test dla klasy FunkcjeMatematyczne" ;
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
		cout << endl;
		cout << endl;
	}
	//nie chce mi sie juz takich testow pisac
	void Testy::test_LiczbaWymierna() {
		cout << "Testy dla klasy LiczbaWymierna:\n";

		LiczbaWymierna liczba1(3, 4);
		LiczbaWymierna liczba2(2, 3);

		cout << "Liczba 1: " << liczba1 << endl;
		cout << "Liczba 2: " << liczba2 << endl;

		LiczbaWymierna suma = liczba1 + liczba2;
		cout << "Suma: " << suma << endl;

		LiczbaWymierna roznica = liczba1 - liczba2;
		cout << "Roznica: " << roznica << endl;

		LiczbaWymierna iloczyn = liczba1 * liczba2;
		cout << "Iloczyn: " << iloczyn << endl;

		LiczbaWymierna iloraz = liczba1 / liczba2;
		cout << "Iloraz: " << iloraz << endl;
		LiczbaWymierna liczba3(2, 4);
		cout << "Stworzono liczbe 2/4, test metody skroc:" << liczba3 << endl;
		
		cout << endl;
	}

	void Testy::test_OperacjeNaBitach() {
		cout << "Testy dla klasy OperacjeNaBitach:\n";

		int liczba = 10;
		cout << "Liczba: " << liczba<<endl;
		cout << "Liczba w postaci bitow:" << OperacjeNaBitach::getBit(liczba, 7) << OperacjeNaBitach::getBit(liczba, 6) << OperacjeNaBitach::getBit(liczba, 5) << OperacjeNaBitach::getBit(liczba, 4) << OperacjeNaBitach::getBit(liczba, 3) << OperacjeNaBitach::getBit(liczba, 2) << OperacjeNaBitach::getBit(liczba, 1) << OperacjeNaBitach::getBit(liczba, 0)<<endl;

	
		cout << "Bit na pozycji 2(liczone od 0): " << OperacjeNaBitach::getBit(liczba, 2) << endl;

		OperacjeNaBitach::toggleBit(liczba, 2);
		cout << "Po przelaczeniu bitu na pozycji 2(liczone od 0): " << liczba << endl;
		cout << "Liczba po przelaczeniu: " << liczba << endl;
		cout << "Liczba w postaci bitow po przelaczeniu:" << OperacjeNaBitach::getBit(liczba, 7) << OperacjeNaBitach::getBit(liczba, 6) << OperacjeNaBitach::getBit(liczba, 5) << OperacjeNaBitach::getBit(liczba, 4) << OperacjeNaBitach::getBit(liczba, 3) << OperacjeNaBitach::getBit(liczba, 2) << OperacjeNaBitach::getBit(liczba, 1) << OperacjeNaBitach::getBit(liczba, 0) << endl;

		cout << "Liczba ustawionych bitow: " << OperacjeNaBitach::countSetBits(liczba) << endl;

		cout << endl;
	}

	void Testy::test_GeneratorLiczbLosowych() {
		cout << "Testy dla klasy GeneratorLiczbLosowych:\n";

		GeneratorLiczbLosowych generator;

		cout << "Losowa liczba calkowita z zakresu 1-100: " << generator.losujLiczbeCalkowita(1, 100) << endl;

		cout << "Losowa liczba zmiennoprzecinkowa z zakresu 1.0-10.0: " << generator.losujLiczbeZmiennoprzecinkowa(1.0, 10.0) << endl;

		cout << "Losowa liczba z rozkladu normalnego (srednia: 5.0, odchylenie: 2.0): " << generator.losujZNormalnegoRozkladu(5.0, 2.0) << endl;

		cout << endl;
	}
	void Testy::test_LiczbyDoskonale() {
		cout << "Testy dla klasy LiczbyDoskonale:\n";

		int n = 100000;
		LiczbyDoskonale D(n);
		cout << "testowanie czyDoskonala do " << n << " w petli:\n";
		for (int i = 1; i <= n; ++i) {
			if (D.czyDoskonala(i))
				cout << i << " ";
		}
		cout << endl << "pobieranie vektora z liczbami za pomoca metody:\n";
		auto x = D.liczbyDoskonaleDo(n);
		for (auto a : x)
		{
			cout << a<<" ";
		}
		cout <<endl<<endl;
	}

	void Testy::test_LiczbyPierwsze() {
		cout << "Testy dla klasy LiczbyPierwsze:\n";

		int n = 100;
		LiczbyPierwsze P(n);
		cout << "testowanie czuPierwsza do " << n << " w petli:\n";
		for (int i = 1; i <= n; ++i) {
			if (P.czyPierwsza(i))
				cout << i << " ";
		}
		cout << endl << "pobieranie vektora z liczbami za pomoca metody:\n";
		auto x = P.liczbyPierwszeDo(n);
		for (auto a : x)
		{
			cout << a << " ";
		}
		cout << endl << endl;
	}

	void Testy::test_Macierze() {
		cout << "Testy dla klasy Macierze:\n";

		Macierz<int> macierz1(3, 3, 1);
		Macierz<int> macierz2(3, 3, 2); 

		cout << "Macierz 1:\n";
		cout << macierz1 << endl;

		cout << "Macierz 2:\n";
		cout << macierz2 << endl;

		Macierz<int> suma = macierz1 + macierz2;
		cout << "Suma macierzy:\n";
		cout << suma << endl;

		Macierz<int> iloczyn = macierz1 * macierz2;
		cout << "Iloczyn macierzy:\n";
		cout << iloczyn << endl;
		 
		Macierz<int> odej = macierz1 - macierz2;
		cout << "Odejmowanie macierzy:\n";
		cout << odej << endl;

		macierz1.wypelnij(21);
		cout << "wypelnianie macierzy1 lcziba 21:\n";
		cout << macierz1 << endl;

		Macierz<double> m(3, 3);
		m(0, 0, true, 1);
		m(0, 1, true, 2);
		m(0, 2, true, 3);
		m(1, 0, true, 0);
		m(1, 1, true, 1);
		m(1, 2, true, 2);
		m(2, 0, true, 2);
		m(2, 1, true, 1);
		m(2, 2, true, 1);
		cout << "Macierz do testowania odwrotnej i wyznacznika:" << endl << m;
		cout << "Wyznacznik: " << m.Wyznacznik() << endl;
		cout << "odwrotna: \n" << m.Odwrotna()<<endl;
		cout << endl;
	}
	void Testy::test_Wektor()
	{
		cout << "Testy dla klasy Wektor:\n";


		Wektor v1(3.0, 4.0);
		Wektor v2(1.0, 2.0);

		cout << "Wektor 1: " << v1 << endl;
		cout << "Wektor 2: " << v2 << endl;

		Wektor suma = Wektor::dodawanie(v1, v2);
		cout << "Suma wektorow: " << suma << endl;

		Wektor roznica = Wektor::odejmowanie(v1, v2);
		cout << "Roznica wektorow: " << roznica << endl;

		double skalar = 2.0;
		Wektor iloczynPrzezLiczbe = Wektor::mnozenie_przez_liczbe(skalar, v1);
		cout << "Iloczyn wektora 1 przez liczbe " << skalar << ": " << iloczynPrzezLiczbe << endl;

		double iloczynSkalarny = Wektor::mnozenie_skalarne(v1, v2);
		cout << "Iloczyn skalarny wektorow: " << iloczynSkalarny << endl;

		double dlugosc = v1.dlugosc();
		cout << "Dlugosc wektora 1: " << dlugosc << endl;

		double cosinus = Wektor::cosinus_wektorow(v1, v2);
		cout << "Wartosc cosinusa kata pomiedzy wektorami: " << cosinus << endl;
		cout << endl;
	}
	void Testy::test_Wektor_3d()
	{
		cout << "Testy dla klasy Wektor_3d:\n";

		Wektor_3d v1(1.0, 2.0, 3.0);
		Wektor_3d v2(4.0, 5.0, 6.0);

		cout << "Wektor 1: " << v1 << endl;
		cout << "Wektor 2: " << v2 << endl; 

		Wektor_3d suma = Wektor_3d::dodawanie(v1, v2);
		cout << "Suma wektorow : " << suma << endl;

		Wektor_3d roznica = Wektor_3d::odejmowanie(v1, v2);
		cout << "Roznica wektorow : " << roznica << endl;

		double skalar = 2.0;
		Wektor_3d iloczynPrzezLiczbe = Wektor_3d::mnozenie_przez_liczbe(skalar, v1);
		cout << "Iloczyn wektora 1  przez liczbe " << skalar << ": " << iloczynPrzezLiczbe << endl;

		double iloczynSkalarny = Wektor_3d::mnozenie_skalarne(v1, v2);
		cout << "Iloczyn skalarny wektorow : " << iloczynSkalarny << endl;

		double dlugosc = v1.dlugosc();
		cout << "Dlugosc wektora  1: " << dlugosc << endl;

		Wektor_3d iloczynWektorowy = Wektor_3d::mnozenie_wektorowe(v1, v2);
		cout << "Iloczyn wektorowy wektorow : " << iloczynWektorowy << endl;

		double cosinus = Wektor_3d::cosinus_wektorow(v1, v2);
		cout << "Wartosc cosinusa kata pomiedzy wektorami : " << cosinus << endl;
		cout << endl;
	}
	void Testy::test_all()
	{
		test_Funkcje();
		 test_Wektor();
		 test_Wektor_3d();
		test_LiczbaWymierna();
		test_OperacjeNaBitach();
		test_GeneratorLiczbLosowych();
		test_LiczbyDoskonale();
		test_LiczbyPierwsze();
		test_Macierze();
	}
