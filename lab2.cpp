#include <iostream>
//#include "iterator.h"
#include "Konten.h"

using namespace std;
template<typename Iter>
void wypisz(Iter start, Iter end) {
    Iter m = start;

    //printf("Wypisanie Kontenera:\n");
    while (start != end) {
        cout << *start++ << "  ";
    }
}


// generuje liczbê pseudolosow¹ typu double od 0.0 do 0.999...
double randdouble()
{
    return rand() / (double(RAND_MAX) + 1);
}

// obliczanie wektora p q
//
template<typename Iter>
void roznicuj(Iter i1, Iter i2, Iter i3) {
    int n =0;
    double wynik = 0;
    while (i1 != i2) {
        n++;
        //cout << "x[" << n << "] = " << *i3 - *i1 << "\n";
		*i1 = *i1 - *i3;
        ++i1;
		++i3;
    }
	//wynik = sqrt(wynik*wynik);
	//cout << "Ilosc elementow: " << n << "\n";
	//cout << "Wynik roznicowania: " << wynik << "\n";

}



template<typename Iter>
void doKwadratu(Iter i1, Iter i2) {
    while (i1 != i2) {
        *i1 = (*i1) * (*i1);
        i1++;
    }
}


template<typename Iter>
void suma(Iter i1, Iter i2, double &a) {
    while (i1 != i2) {
        a += *i1;
        i1++;
    }
    cout << "\nSuma elementow: " << a << "\n";
}

int main() {
    double a = 0;
	Konten<double, 100> dk;
	Konten <double, 100> di;
	//Konten <int, 100> dx;
    for (int i = 0; i < 10; i++)
    {
		double l = randdouble();
        dk.push(10*l);
	}
    for (int i = 0; i < 10; i++)
    {
        double l = randdouble();
        di.push(10 * l);

	}
    

    cout << "P: ";
	wypisz(dk.begin(), dk.end());
    //dk.pop();
    //cout << "\n";
    //wypisz(dk.begin(), dk.end());
	cout << "\nQ: ";
	wypisz(di.begin(), di.end());
    roznicuj(dk.begin(), dk.end(), di.begin());
    cout << "\nX: ";
    wypisz(dk.begin(), dk.end());
	cout << "\nX^2: ";
	doKwadratu(dk.begin(), dk.end());
    wypisz(dk.begin(), dk.end());
	suma(dk.begin(), dk.end(), a);
	a = sqrt(a);
    cout << "Wynik koncowy a: " << a;
    getchar();
	return 0;


}