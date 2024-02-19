#pragma once
#include <iostream>
#include <string>
using namespace std;

	template <typename T>
	class Macierz
	{
	private:
		int wiersze;
		int kolumny;
		void alloctab();
		void freetab();
		T** tablica;
	public:
		void wypelnij(T x);
		Macierz(int k, int w, T x = 0);
		Macierz();
		int GetWiersze();
		int GetKolumny();
		void SetWiersze(int w);
		void SetKolumny(int k);
		void Transponuj();
		Macierz<T> operator*(Macierz<T> m);
		T operator()(int w,int k,bool zap=false,int a=0);
		T Wyznacznik();
		Macierz<T> Odwrotna();
		Macierz<T> operator+(Macierz<T> m);
		Macierz<T> operator-(Macierz<T> m);

	};
	template<typename T>
	void Macierz<T>::SetWiersze(int w) {
		if (w > 0)wiersze = w;
		freetab();
		alloctab();
	}
		template<typename T>
	int  Macierz<T>::GetWiersze() { return wiersze; }
		template<typename T>
	void Macierz<T>::SetKolumny(int k) {
		if (k > 0)kolumny = k;
		freetab();
		alloctab();
	}
		template<typename T>
	int Macierz<T>::GetKolumny() { return kolumny; }
	template<typename T>
	Macierz<T>::Macierz()
	{
		
			wiersze = 3;
			kolumny = 3;
			alloctab();
			wypelnij(0);
		
	}
	template<typename T>
	Macierz<T>::Macierz(int k, int w, T x )
	{
		wiersze = w;
		kolumny = k;
		alloctab();
		wypelnij(x);
	}
	template <typename T>
	T Macierz<T>::operator()(int w, int k,bool zap,int a)
	{
		if (zap)
		{
			tablica[w][k] = a;
			return 0;
	}
		else
		return tablica[w][k];
	}
	template <typename T>
	void Macierz<T>::wypelnij(T x)
	{
		for (int i = 0; i < wiersze; i++)
		{
			for (int j = 0; j < kolumny; j++)
				tablica[i][j] = x;
		}
	}
	
	template<typename T>
	Macierz<T> Macierz<T>::Odwrotna() {
		if (this->wiersze != this->kolumny) {
			throw std::invalid_argument("Macierz musi byæ kwadratowa!");
		}
		if (this->Wyznacznik() == 0) {
			throw std::invalid_argument("Macierz nie ma odwrotnoœci!");
		}
		int n = this->wiersze; 
		T d, temp, c, ** a;
		int i, j, k, m, nn, * ipvt;

		ipvt = new int[n];
		nn = n;

		for (i = 0; i < nn; i++)
			ipvt[i] = i;

		a = new T * [n];
		for (k = 0; k < n; k++)
			a[k] = new T[n];

		try {
			
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					a[i][j] = this->tablica[i][j];
				}
			}

			// Algorytm Gaussa-Jordana
			for (k = 0; k < nn; k++) {
				temp = 0.;
				m = k;
				for (i = k; i < nn; i++) {
					d = a[k][i];
					if (fabs(d) > temp) {
						temp = fabs(d);
						m = i;
					}
				}
				if (m != k) {
					j = ipvt[k];
					ipvt[k] = ipvt[m];
					ipvt[m] = j;
					for (j = 0; j < nn; j++) {
						temp = a[j][k];
						a[j][k] = a[j][m];
						a[j][m] = temp;
					}
				}
				d = 1 / a[k][k];
				for (j = 0; j < k; j++) {
					c = a[j][k] * d;
					for (i = 0; i < nn; i++)
						a[j][i] -= a[k][i] * c;
					a[j][k] = c;
				}
				for (j = k + 1; j < nn; j++) {
					c = a[j][k] * d;
					for (i = 0; i < nn; i++)
						a[j][i] -= a[k][i] * c;
					a[j][k] = c;
				}
				for (i = 0; i < nn; i++)
					a[k][i] = -a[k][i] * d;
				a[k][k] = d;
			}

	
			Macierz<T> odwrotna(this->wiersze, this->kolumny);

			for (i = 0; i < nn; i++) {
				for (j = 0; j < nn; j++) {
					odwrotna.tablica[ipvt[i]][j] = a[i][j];
				}
			}

		
			delete[] ipvt;
			for (k = 0; k < n; k++)
				delete[] a[k];
			delete[] a;

			
			return odwrotna;

		}
		catch (...) {
			
			throw std::runtime_error("Wyst¹pi³ b³¹d podczas obliczania macierzy odwrotnej.");
		}
	}

	template<typename T>
	void Macierz<T>::Transponuj() {
		Macierz<T> tmp(this->kolumny, this->wiersze);

		for (int i = 0; i < this->wiersze; ++i) {
			for (int j = 0; j < this->kolumny; ++j) {
				tmp.tablica[j][i] = this->tablica[i][j];
			}
		}
		std::swap(this->wiersze, this->kolumny);
		std::swap(this->tablica, tmp.tablica);
	}
	template<typename T>
	Macierz<T> Macierz<T>::operator-(Macierz<T> m) {
		if (this->wiersze != m.wiersze || this->kolumny != m.kolumny) {
			throw std::invalid_argument("Niepoprawne wymiary macierzy!");
		}

		Macierz<T> tmp(this->wiersze, this->kolumny);

		for (int i = 0; i < this->wiersze; ++i) {
			for (int j = 0; j < this->kolumny; ++j) {
				tmp.tablica[i][j] = this->tablica[i][j] - m.tablica[i][j];
			}
		}

		return tmp;
	}
	template<typename T>
	Macierz<T> Macierz<T>::operator+(Macierz<T> m) {
		if (this->wiersze != m.wiersze || this->kolumny != m.kolumny) {
			throw std::invalid_argument("Niepoprawne wymiary macierzy!");
		}

		Macierz<T> tmp(this->wiersze, this->kolumny);

		for (int i = 0; i < this->wiersze; ++i) {
			for (int j = 0; j < this->kolumny; ++j) {
				tmp.tablica[i][j] = this->tablica[i][j] + m.tablica[i][j];
			}
		}

		return tmp;
	}
	template <typename T>
	ostream& operator<<(ostream& os, Macierz<T> m)
	{
		for (int i = 0; i < m.GetWiersze(); i++)
		{
			for (int j = 0; j < m.GetKolumny(); j++)
				os << to_string(m(i,j)) << " ";
			os << "\n";
		}
		return os;
	}
	template<typename T>
	void Macierz<T>::alloctab()
	{
		tablica = (T**)malloc(wiersze * sizeof(T*));
		tablica[0] = (T*)malloc(wiersze * kolumny * sizeof(T));
		for (int i = 1; i < wiersze; i++) tablica[i] = tablica[0] + i * kolumny;
	}
	template <typename T>
	void Macierz<T>::freetab()
	{
		free(tablica[0]);
		free(tablica);
		tablica = NULL;
	}
	template<typename T>
	Macierz<T> Macierz<T>::operator*(Macierz<T> m)
	{
		if (this->kolumny != m.wiersze)  throw std::invalid_argument("Niepoprawne wymiary macierzy!");
		Macierz<T> tmp(this->kolumny, m.wiersze);
		for (int i = 0; i < this->wiersze; ++i) {
			for (int j = 0; j < m.kolumny; ++j) {
				T sum = static_cast<T>(0);
				for (int k = 0; k < this->kolumny; ++k) {
					sum += this->tablica[i][k] * m.tablica[k][j];
				}
				tmp.tablica[i][j] = sum;
			}
		}

		return tmp;
	}template<typename T>
		T Macierz<T>::Wyznacznik() {
		if (this->wiersze != this->kolumny) {
			throw std::invalid_argument("Macierz musi byc kwadratowa!");
		}

		if (this->wiersze == 1) {
			return this->tablica[0][0]; 
		}

		T det = static_cast<T>(0);

		if (this->wiersze == 2) {
			det = (this->tablica[0][0] * this->tablica[1][1]) - (this->tablica[0][1] * this->tablica[1][0]);
			return det;
		}


		for (int i = 0; i < this->wiersze; ++i) {
			Macierz<T> mniejsza(this->wiersze - 1, this->kolumny - 1);
			for (int j = 1; j < this->wiersze; ++j) {
				for (int k = 0; k < this->kolumny; ++k) {
					if (k < i) {
						mniejsza.tablica[j - 1][k] = this->tablica[j][k];
					}
					else if (k > i) {
						mniejsza.tablica[j - 1][k - 1] = this->tablica[j][k];
					}
				}
			}
			T wspolczynnik = (i % 2 == 0) ? this->tablica[0][i] : -this->tablica[0][i];
			det += wspolczynnik * mniejsza.Wyznacznik();
		}

		return det;
	}
