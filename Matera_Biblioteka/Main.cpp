#include <iostream>
#include "Wektor.h"
#include"Wektor_3d.h"
using namespace Matematyka;
using namespace std;
void main()
{
	Wektor w(55, 22);
	Wektor_3d ww(55,22,33);
	Wektor_3d ww2(21,64, 61);
	Wektor_3d wyn (ww.mnozenie_wektor(ww2));
	cout << wyn;
}
