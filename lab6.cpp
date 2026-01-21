#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <functional>
#include <numeric>
using namespace std;


double operacja2(double a, double b) {
	return 3 * a + b;
}
double operacja3(double a, double b) {
	return 2;
}
void myFunction(function<double()> func1,function<double()>) {

}



int main() {
	//random_device dv;
	random_device rd;
	mt19937 rng(rd());
	uniform_real_distribution<double> distribution(-10, 10);
	int i = 0;
	int n;
	int init = 100;
	vector<double> A;
	vector<int> B;
	vector<double> C;
	vector<double> D;
	vector<double> Pomocnicza1;
	vector<double> Pomocnicza2;
	cout << "Podaj wartosc przestrzeni n: ";
	while (1) {
		cin >> n;
		if (n >0) {
			break;
		}
	}
	while (i < n) {
		double x = distribution(rng);
		//cout << x<<"\n";
		i++;
		A.push_back(x);
		B.push_back(2);
		C.push_back(0);
		D.push_back(0);
		Pomocnicza1.push_back(0);
		Pomocnicza2.push_back(0);

	}
	i = 0;
	cout << "\nKolejny \n";

	while (i< A.size()) {
		cout << "\nZ vectora \n";
		cout << "A: " << A[i] <<" B: "<< B[i]<<" C: "<< C[i] <<" D: "<< D[i];
		i++;
	}
	std::cin.get();
	i = 0;
	transform(A.begin(), A.end(), B.begin(), D.begin(),
		multiplies<double>());
	cout << "\nKolejny \n";

	while (i < A.size()) {
		cout << "\nZ vectora \n";
		cout << "A: " << A[i] << " B: " << B[i] << " C: " << C[i] << " D: " << D[i];
		i++;
	}
	std::cin.get();
	i = 0;
	transform(B.begin(), B.end(), D.begin(), C.begin(),
		operacja2);
	cout << "\nKolejny \n";

	while (i < A.size()) {
		cout << "\nZ vectora \n";
		cout << "A: " << A[i] << " B: " << B[i] << " C: " << C[i] << " D: " << D[i];
		i++;
	}
	i = 0;
	std::cin.get(); 
	transform(A.begin(), A.end(), C.begin(), Pomocnicza1.begin(),
		[](double a, double b) {
			return 3 * (a + b);
		});
	transform(A.begin(), A.end(), B.begin(), Pomocnicza2.begin(),
	multiplies<double>());
	transform(Pomocnicza1.begin(), Pomocnicza1.end(), Pomocnicza2.begin(), D.begin(),
		[](double a, double b) {
			return a - b;
		});
	cout << "\nKolejny \n";

	while (i < A.size()) {
		cout << "\nZ vectora \n";
		cout << "A: " << A[i] << " B: " << B[i] << " C: " << C[i] << " D: " << D[i];
		i++;
	}



}
//#include <functional>
//void myFunction(function<int()> func) {
//	func();
//	func();
//	func();
//	func();
//	func();
//}
//
//
//int main() {
//	int i = 0;
//	auto message = [&i]() {
//		cout << i << "To twoja liczba \n";
//		return i;
//		};
//	i = 10;
//	myFunction(message);
//}

// This program prints the C++ language standard your compiler is currently using
// Freely redistributable, courtesy of learncpp.com (https://www.learncpp.com/cpp-tutorial/what-language-standard-is-my-compiler-using/)

//#include <iostream>
////#include "funkcje.h"
//
//void add(int a, int b) {
//	cout << a;
//}
//void add(int a, int b) {
//cout << "a+b";
//}
//
//
//int main() {
//	int x{ 5 }, y{6};
//	x={ 5 };
//	add(x, y);
//
//}
