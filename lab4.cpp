/* ==========================
   (c) WMP.SNŒ UKSW, 2015
========================== */
#include<iostream>
#include<fstream>
#include<string>
#include<limits>
#include<exception>

using namespace std;

class _Bazowe_Cechy {
public:
	// pola statyczne sta³e - dla sta³ych wartoœci ca³kowitych
	static const bool _jest_liczba = false;
	static const bool _nalezy_do_przedzialu = false;
	static const bool _jest_liczba_calkowita = false;
	static const bool _jest_co_1_10 = false;
	static const bool _jest_calkowita_lub_ma_koncowke05 = false;
	static const bool _jest_potega_dwojki = false;

};

template<typename T>
class _Cechy : public _Bazowe_Cechy {
public:
	// metody statyczne - dla wartoœci innych typów ni¿ liczby ca³kowite
	static const T _dolna_granica() { return T(); };
	static const T _gorna_granica() { return T(); };
};

template<typename T>
class Cechy : public _Cechy<T> {
};

class przyspieszenie {
	double a;
public:
	przyspieszenie(double acc = 0) : a(acc) {};
	double operator()() const { return a; };
	przyspieszenie& operator=(double acc) { a = acc; return *this; };
	bool operator<(const przyspieszenie& p) const { return (a < p.a); };
	friend ostream& operator<<(ostream& os, const przyspieszenie&);
};
ostream& operator<<(ostream& os, const przyspieszenie& p) { return os << p.a; };

template<>
class Cechy<przyspieszenie> : public _Cechy<przyspieszenie> {
public:
	static const bool _jest_liczba = true;
};

class znaki {
	char t;
public:
	znaki(char temp = 'a') : t(temp) {};
	char operator()() const { return t; };
	znaki& operator=(double temp) { t = temp; return *this; };
	bool operator<(const znaki& tw) const { return (t < tw.t); };
	friend ostream& operator<<(ostream& os, const znaki&);
};
ostream& operator<<(ostream& os, const znaki& tw) { return os << tw.t; };

template<>
class Cechy<znaki> : public _Cechy<znaki> {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const znaki _dolna_granica() { return znaki('a'); };
	static const znaki _gorna_granica() { return znaki('Z'); };
};

class temperatura_wody {
	double t;
public:
	temperatura_wody(double temp = 50) : t(temp) {};
	double operator()() const { return t; };
	temperatura_wody& operator=(double temp) { t = temp; return *this; };
	bool operator<(const temperatura_wody& tw) const { return (t < tw.t); };
	friend ostream& operator<<(ostream& os, const temperatura_wody&);
};
ostream& operator<<(ostream& os, const temperatura_wody& tw) { return os << tw.t; };

template<>
class Cechy<temperatura_wody> : public _Cechy<temperatura_wody> {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const temperatura_wody _dolna_granica() { return temperatura_wody(0); };
	static const temperatura_wody _gorna_granica() { return temperatura_wody(100); };
};
class numer_kolnierzyka {
	int n;
public:
	numer_kolnierzyka(int num = 37) : n(num) {};
	int operator()() const { return n; };
	numer_kolnierzyka& operator=(int num) { n = num; return *this; };
	bool operator<(const numer_kolnierzyka& k) const { return (n < k.n); };
	friend ostream& operator<<(ostream& os, const numer_kolnierzyka&);
};
ostream& operator<<(ostream& os, const numer_kolnierzyka& k) { return os << k.n; };

template<>
class Cechy<numer_kolnierzyka> : public _Cechy<numer_kolnierzyka> {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const numer_kolnierzyka _dolna_granica() { return numer_kolnierzyka(37); };
	static const numer_kolnierzyka _gorna_granica() { return numer_kolnierzyka(54); };
};

class pojemnoscMicroSD {
	int n;
public:
	pojemnoscMicroSD(int num = 37) : n(num) {};
	int operator()() const { return n; };
	pojemnoscMicroSD& operator=(int num) { n = num; return *this; };
	bool operator<(const pojemnoscMicroSD& k) const { return (n < k.n); };
	friend ostream& operator<<(ostream& os, const pojemnoscMicroSD&);
};
ostream& operator<<(ostream& os, const pojemnoscMicroSD& k) { return os << k.n; };

template<>
class Cechy<pojemnoscMicroSD> : public _Cechy<pojemnoscMicroSD> {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const bool _jest_potega_dwojki = true;

	static const pojemnoscMicroSD _dolna_granica() { return pojemnoscMicroSD(2); };
	static const pojemnoscMicroSD _gorna_granica() { return pojemnoscMicroSD(128); };
};




class srednica_opony {
	int n;
public:
	srednica_opony(int num = 10) : n(num) {};
	int operator()() const { return n; };
	srednica_opony& operator=(int num) { n = num; return *this; };
	bool operator<(const srednica_opony& k) const { return (n < k.n); };
	friend ostream& operator<<(ostream& os, const srednica_opony&);
};
ostream& operator<<(ostream& os, const srednica_opony& k) { return os << k.n; };

template<>
class Cechy<srednica_opony> : public _Cechy<srednica_opony> {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const srednica_opony _dolna_granica() { return srednica_opony(10); };
	static const srednica_opony _gorna_granica() { return srednica_opony(24); };
};

class kostka_do_gry {
	int n;
public:
	kostka_do_gry(int num = 1) : n(num) {};
	int operator()() const { return n; };
	kostka_do_gry& operator=(int num) { n = num; return *this; };
	bool operator<(const kostka_do_gry& k) const { return (n < k.n); };
	friend ostream& operator<<(ostream& os, const kostka_do_gry&);
};
ostream& operator<<(ostream& os, const kostka_do_gry& k) { return os << k.n; };

template<>
class Cechy<kostka_do_gry> : public _Cechy<kostka_do_gry> {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = true;
	static const kostka_do_gry _dolna_granica() { return kostka_do_gry(1); };
	static const kostka_do_gry _gorna_granica() { return kostka_do_gry(6); };
};

class czestotliwosc {
	double f;
public:
	czestotliwosc(double num = 87) : f(num) {};
	double operator()() const { return f; };
	czestotliwosc& operator=(double freq) {f = freq; return *this; };
	bool operator<(const czestotliwosc& k) const {return (f < k.f); };
	friend ostream& operator<<(ostream& os, const czestotliwosc&);
};
ostream& operator<<(ostream& os, const czestotliwosc& k) { return os << k.f; };

template<>
class Cechy<czestotliwosc> : public _Cechy<czestotliwosc> {
public:
	static const bool _jest_liczba = true;            
	static const bool _nalezy_do_przedzialu = true;    
	static const bool _jest_co_1_10 = true; 
	static const czestotliwosc _dolna_granica() { return czestotliwosc(87.5); };
	static const czestotliwosc _gorna_granica() { return czestotliwosc(108.0); };


};

class rozmiarButa {
	double f;
public:
	rozmiarButa(double num = 45) : f(num) {};
	double operator()() const { return f; };
	rozmiarButa& operator=(double freq) { f = freq; return *this; };
	bool operator<(const rozmiarButa& k) const { return (f < k.f); };
	friend ostream& operator<<(ostream& os, const rozmiarButa&);
};
ostream& operator<<(ostream& os, const rozmiarButa& k) { return os << k.f; };

template<>
class Cechy<rozmiarButa> : public _Cechy<rozmiarButa> {
public:
	static const bool _jest_liczba = true;
	static const bool _nalezy_do_przedzialu = true;
	static const bool _jest_liczba_calkowita = false;
	static const bool _jest_co_1_10 = false;
	static const bool _jest_calkowita_lub_ma_koncowke05 = true;


	static const rozmiarButa _dolna_granica() { return rozmiarButa(22); };
	static const rozmiarButa _gorna_granica() { return rozmiarButa(55); };


};



class Przepelnienie : public exception {
	char opis[100];
public:
	Przepelnienie(const char* o) { strcpy_s(opis, o); }
	const char* what() const throw() { return opis; };
};
class BrakDanych : public exception {
	char opis[100];
public:
	BrakDanych(const char* o) { strcpy_s(opis, o); }
	const char* what() const throw() { return opis; };
};

template<typename T, int rozmiar, typename CechyT = Cechy<T>>
class SzablonStosu {
	T stos[rozmiar];
	int top;
public:
	int zajetosc() { return top; };
	SzablonStosu() : top(0) {}
	void push(const T& i) {
		if (top == rozmiar)
			throw Przepelnienie(typeid(i).name());
		stos[top++] = i;
	}


	void push(int i) {
		if (top == rozmiar)
			throw Przepelnienie(typeid(i).name());

		// walidacja wartoœci przekazanej do zapisu
		if (CechyT::_jest_liczba && CechyT::_jest_liczba_calkowita && !CechyT::_jest_potega_dwojki) {
			if (CechyT::_nalezy_do_przedzialu) {
				if (!(T(i) < CechyT::_dolna_granica()) && !(CechyT::_gorna_granica() < T(i)))
					stos[top++] = i;
			}
			else
				stos[top++] = i;
		}
		else if (CechyT::_jest_potega_dwojki && jestpotegadwojki(i)) {
			if (CechyT::_nalezy_do_przedzialu  ) {
				if (!(T(i) < CechyT::_dolna_granica()) && !(CechyT::_gorna_granica() < T(i)))
					stos[top++] = i;
			}
			else
				stos[top++] = i;
		}
	}
	bool jestpotegadwojki(int j) {
		int i = 0;
		int potega = 1;
		for (i; i < 7; i++) {
			potega = potega * 2;
			//cout << potega << "\n";
			if (potega == j) {
				return true;
			}
		}
		return false;


	}
	bool jestcalkowitalalubzjednymmiejscem(double j) {
		double h;
		j = j * 10;

		int i;
		i = (int)j;
		h = (double)i;
		if (j == h) {
			//printf("spelnia");
			return true;
		}
		return false;

	}
	bool jestcalkowitalalubzjednymmiejscemipolowka(double j){
		double h;
	j = j * 10;

	int i;
	i = (int)j;
	h = (double)i;
	if (j == h && i % 5 == 0) {
		//printf("spelnia");
		return true;
	}
	return false;

	}

	void push(double i) {
		if (top == rozmiar)
			throw Przepelnienie(typeid(i).name());

		// walidacja wartoœci przekazanej do zapisu
		if (CechyT::_jest_liczba && !CechyT::_jest_liczba_calkowita && !CechyT::_jest_co_1_10 && !CechyT::_jest_calkowita_lub_ma_koncowke05) {
			if (CechyT::_nalezy_do_przedzialu) {
				if (!(T(i) < CechyT::_dolna_granica()) && !(CechyT::_gorna_granica() < T(i)))
					stos[top++] = i;
			}

			else
				stos[top++] = i;
		}
		else if (CechyT::_jest_liczba && !CechyT::_jest_liczba_calkowita && CechyT::_jest_co_1_10) {
			if (CechyT::_nalezy_do_przedzialu) {
				if ((!(T(i) < CechyT::_dolna_granica()) && !(CechyT::_gorna_granica() < T(i)))&& jestcalkowitalalubzjednymmiejscem(i))
					stos[top++] = i;
			}

			else
				if (jestcalkowitalalubzjednymmiejscem(i)) {
					stos[top++] = i;
				}
		}
		else if (CechyT::_jest_liczba && !CechyT::_jest_liczba_calkowita && !CechyT::_jest_co_1_10 && CechyT::_jest_calkowita_lub_ma_koncowke05) {
			if (CechyT::_nalezy_do_przedzialu) {
				if ((!(T(i) < CechyT::_dolna_granica()) && !(CechyT::_gorna_granica() < T(i))) && jestcalkowitalalubzjednymmiejscemipolowka(i))
					stos[top++] = i;
			}

			else
				if (jestcalkowitalalubzjednymmiejscemipolowka(i)) {
					stos[top++] = i;
				}
		}
				else if (CechyT::_jest_liczba && !CechyT::_jest_liczba_calkowita && CechyT::_jest_co_1_10) {
			if (CechyT::_nalezy_do_przedzialu) {
				if ((!(T(i) < CechyT::_dolna_granica()) && !(CechyT::_gorna_granica() < T(i)))&& jestcalkowitalalubzjednymmiejscem(i))
					stos[top++] = i;
			}

			else
				if (jestcalkowitalalubzjednymmiejscem(i)) {
					stos[top++] = i;
				}
		}

	}
	T pop() {
		if (top == 0)
			throw BrakDanych(typeid(stos[0]).name());

		return stos[--top];
	}
	template<typename U1, int r, typename U2>
	friend ostream& operator<<(ostream& os, const SzablonStosu<U1, r, U2>&);
};
template<typename U1, int r, typename U2>
ostream& operator<<(ostream& os, const SzablonStosu<U1, r, U2>& S)
{
	for (int i = 0; i < S.top; i++) cout << S.stos[i] << endl;
	return os;
};

int main() {
	//printf("Zadanie przykladowe do przecwiczenia\n\n\n\n");
	//system("pause");
	//SzablonStosu<string, 5> K1;
	//SzablonStosu<przyspieszenie, 10> K2;
	//SzablonStosu<temperatura_wody, 10> K3;
	//SzablonStosu<kostka_do_gry, 10> K4;
	//SzablonStosu<numer_kolnierzyka, 10> K5;
	//SzablonStosu<znaki, 15> K6;
	//// zape³nianie stosów K1, K2, K3 i K4:
	//ifstream fi("qv-lab4.txt");
	//string s;
	//try {
	//	K1.push("Henryk");
	//	K1.push("Sienkiewicz");
	//	while (fi) {
	//		fi >> s;
	//		K1.push("Henryk");
	//		fi.seekg(ios::beg);
	//		fi.clear();
	//		cout << '*';
	//	};
	//}
	//catch (Przepelnienie& e) {
	//	cout << "K1 gotowy: " << e.what() << endl;
	//};
	//cout << K1;
	//cout << "Danych na stosie K1: " << K1.zajetosc() << endl << endl;
	////cout << K1;
	//K2.push(przyspieszenie());
	//K2.push(przyspieszenie(5.0));
	//K2.push(10);	// uwaga: nie akceptujemy przyspieszenia jako liczby ca³kowitej
	//K2.push(10.0);
	//cout << K2;
	//cout << "Danych na stosie K2: " << K2.zajetosc() << endl << endl;

	//K3.push(temperatura_wody());
	//K3.push(temperatura_wody(36.6));
	//K3.push(71.2);
	//K3.push(5.0);
	//K3.push(112.1); // uwaga: nie akceptujemy wartoœci spoza przedzia³u
	//cout << K3;
	//cout << "Danych na stosie K3: " << K3.zajetosc() << endl << endl;

	//K4.push(kostka_do_gry(3));
	//K4.push(kostka_do_gry());
	//K4.push(6);
	//K4.push(10); // uwaga: nie akceptujemy wartoœci spoza przedzia³u
	//cout << K4;
	//cout << "Danych na stosie K4: " << K4.zajetosc() << endl << endl;

	//K5.push(numer_kolnierzyka(5));
	//K5.push(numer_kolnierzyka());
	//K5.push(52);
	//K4.push(10); // uwaga: nie akceptujemy wartoœci spoza przedzia³u
	//cout << K5;
	//cout << "Danych na stosie K5: " << K5.zajetosc() << endl << endl;

	//K6.push(znaki('b'));
	//K6.push(znaki('b'));
	//K6.push(znaki('b'));
	//K6.push(znaki(';'));
	//K6.push(znaki('/'));
	//cout << K6;
	//cout << "Danych na stosie K6: " << K6.zajetosc() << endl << endl;


	//// opró¿nianie stosów
	//try {
	//	while (true)
	//		 K1.pop();
	//}
	//catch (BrakDanych& e) {
	//	cout << "K1 pusty: " << e.what() << endl;
	//}
	//try {
	//	while (true)
	//		K2.pop();
	//}
	//catch (BrakDanych& e) {
	//	cout << "K2 pusty: " << e.what() << endl;
	//}
	//try {
	//	while (true)
	//		K3.pop();
	//}
	//catch (BrakDanych& e) {
	//	cout << "K3 pusty: " << e.what() << endl;
	//}
	//try {
	//	while (true)
	//		K4.pop();
	//}
	//catch (BrakDanych& e) {
	//	cout << "K4 pusty: " << e.what() << endl;
	//}
	//system("pause");
	//system("cls");

	printf("Zadanie labolatoryjne \n\n\n\n");
	system("pause");
	system("cls");


	SzablonStosu<srednica_opony, 5> K10;
	K10.push(srednica_opony(11));
	K10.push(11.12);

	K10.push(srednica_opony());
	K10.push(8);
	K10.push(24); // uwaga: nie akceptujemy wartoœci spoza przedzia³u
	cout << K10;
	cout << "Danych na stosie K10: " << K10.zajetosc() << endl << endl;

	SzablonStosu<czestotliwosc, 5> K11;
	K11.push(100.23);
	K11.push(100.1);

	K11.push(czestotliwosc());
	K11.push(8);
	K11.push(89.2); // uwaga: nie akceptujemy wartoœci spoza przedzia³u
	cout << K11;
	cout << "Danych na stosie K11: " << K11.zajetosc() << endl << endl;
	//bool a = jestpotegadwojki(123);

	SzablonStosu<rozmiarButa, 5> K12;
	K12.push(100.23);
	K12.push(100.1);

	K12.push(45.5);
	K12.push(46);
	K12.push(45.6);
	K12.push(89.2); // uwaga: nie akceptujemy wartoœci spoza przedzia³u
	cout << K12;
	cout << "Danych na stosie K12: " << K12.zajetosc() << endl << endl;

	SzablonStosu<pojemnoscMicroSD, 5> K13;
	K13.push(2);
	K13.push(3);

	K13.push(4);
	K13.push(128);
	K13.push(129); // uwaga: nie akceptujemy wartoœci spoza przedzia³u
	cout << K13;
	cout << "Danych na stosie K12: " << K13.zajetosc() << endl << endl;
	system("pause");

	try {
		while (true)
			K10.pop();
	}
	catch (BrakDanych& e) {
		cout << "K10 pusty: " << e.what() << endl;
	}
	try {
		while (true)
			K11.pop();
	}
	catch (BrakDanych& e) {
		cout << "K11 pusty: " << e.what() << endl;
	}
	try {
		while (true)
			K12.pop();
	}
	catch (BrakDanych& e) {
		cout << "K12 pusty: " << e.what() << endl;
	}
	try {
		while (true)
			K13.pop();
	}
	catch (BrakDanych& e) {
		cout << "K4 pusty: " << e.what() << endl;
	}
	system("pause");

	return 0;
}