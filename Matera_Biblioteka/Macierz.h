#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace Matematyka {
	template <typename T>
	class Macierz
	{
	private:
		int wiersze;
		int kolumny;

		void alloctab();
		void freetab();
	public:
		void wypelnij(T x);
		T** tablica;
		Macierz(int k, int w, T x = 0)
		{
			wiersze = w;
			kolumny = k;
			alloctab();
			wypelnij(x);
		}
		Macierz()
		{
			wiersze = 3;
			kolumny = 3;
			alloctab();
			wypelnij(0);
		}
		int GetWiersze() { return wiersze; }
		int GetKolumny() { return kolumny; }
		void SetWiersze(int w) {
			if (w > 0)wiersze = w;
			freetab();
			alloctab();
		}
		void SetKolumny(int k) {
			if (k > 0)kolumny = k;
			freetab();
			alloctab();
		}
		void Transponuj();

		Macierz<T> operator*(Macierz<T> m);
		T Wyznacznik();
		Macierz Odwrotna();
		Macierz<T> operator+(Macierz<T> m);
		Macierz<T> operator-(Macierz<T> m);

	};
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
			throw std::invalid_argument("Macierz musi byc kwadratowa!");
		}

		Macierz<T> rozszerzona(this->wiersze, this->kolumny * 2);
		for (int i = 0; i < this->wiersze; ++i) {
			for (int j = 0; j < this->kolumny; ++j) {
				rozszerzona.tablica[i][j] = this->tablica[i][j];
			}
			rozszerzona.tablica[i][i + this->kolumny] = static_cast<T>(1);
		}

		// Algorytm Gaussa-Jordana
		for (int i = 0; i < rozszerzona.wiersze; ++i) {
			int maxRow = i;
			for (int j = i + 1; j < rozszerzona.wiersze; ++j) {
				if (std::abs(rozszerzona.tablica[j][i]) > std::abs(rozszerzona.tablica[maxRow][i])) {
					maxRow = j;
				}
			}
			for (int k = 0; k < rozszerzona.kolumny; ++k) {
				std::swap(rozszerzona.tablica[i][k], rozszerzona.tablica[maxRow][k]);
			}
			T pivot = rozszerzona.tablica[i][i];
			if (pivot == static_cast<T>(0)) {
				throw std::runtime_error("Macierz nie ma odwrotnosci!");
			}
			for (int k = 0; k < rozszerzona.kolumny; ++k) {
				rozszerzona.tablica[i][k] /= pivot;
			}
			for (int j = 0; j < rozszerzona.wiersze; ++j) {
				if (j != i) {
					T factor = rozszerzona.tablica[j][i];
					for (int k = 0; k < rozszerzona.kolumny; ++k) {
						rozszerzona.tablica[j][k] -= factor * rozszerzona.tablica[i][k];
					}
				}
			}
		}

		Macierz<T> odwrotna(this->wiersze, this->kolumny);
		for (int i = 0; i < this->wiersze; ++i) {
			for (int j = 0; j < this->kolumny; ++j) {
				odwrotna.tablica[i][j] = rozszerzona.tablica[i][j + this->kolumny];
			}
		}

		return odwrotna;
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
				os << to_string(m.tablica[i][j]) << " ";
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
}