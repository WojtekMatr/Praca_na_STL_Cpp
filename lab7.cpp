#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <functional>
#include <numeric>
#include <cmath>



template <class Type>
class Suma
{
public:
	Type wynik;  
	Suma() {
		wynik = 0;
	}

	void operator()(const Type& x)
	{
		wynik += x;
	}
};




int main() {
	std::random_device rd;
	std::mt19937 rng(rd());
	const int n = 100;
	std::vector<int> dane(n);
	std::uniform_real_distribution<double> distribution(0, 100);
	std::generate(dane.begin(), dane.end(), [&]() {
		return distribution(rng);

		});
	for (auto x : dane) {
		std::cout << x << " ";
	}
	Suma<int> suma1;
	suma1 =std::for_each(dane.begin(), dane.end(), suma1);

	const double srediaZForDouble = (double)suma1.wynik / dane.size();  // 2 mozliwosci obliczania
	//const double srednia = (double)std::accumulate(dane.begin(), dane.end(), 0)/ dane.size(); //accumulate latwiejsze
	std::cout << "\n\nSrednia probki to : " << srediaZForDouble<< " \n";
	std::vector<double> kwadratOdchylen(n);



	std::transform(dane.begin(), dane.end(), kwadratOdchylen.begin(), [srediaZForDouble](int a) {
		return std::pow(a - srediaZForDouble, 2);

		});

	std::cout << "\nKwadraty poszczegolnych odchylen standardowych: \n";
	for (auto x : kwadratOdchylen) {
		std::cout << x << " ";
	}
	const double sumaKwadratow = std::accumulate(kwadratOdchylen.begin(), kwadratOdchylen.end(), 0);
	const double sn = (1.0 / (n - 1)) * sumaKwadratow;
	std::cout << "\n\nWariancja to: " << sn;
	//std::uniform_real_distribution<double> distribution(-10, 10);


}

