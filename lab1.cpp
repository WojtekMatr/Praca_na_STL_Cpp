#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "wyk³ad13b.h"    // szablon Tablica
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;

////zadanie 1 przed 2lab
//double wyliczWyrazenie(string wyrazenie) {
//	stack <double> stos;
//	istringstream iss(wyrazenie);
//    {
//        string token;
//        while (iss >> token) {
//            try {
//                double num = stod(token);
//                stos.push(num);
//            }
//            catch (...) {
//                if (stos.size() < 2) {
//                    throw runtime_error("Niewystarczajaca liczba operandow");
//                }
//                double b = stos.top(); stos.pop();
//                double a = stos.top(); stos.pop();
//                double wynik;
//                if (token == "+") wynik = a + b;
//                else if (token == "-") wynik = a - b;
//                else if (token == "*") wynik = a * b;
//                else if (token == "/") {
//                    if (b == 0) {
//                        throw runtime_error("Dzielenie przez zero");
//                    }
//                    wynik = a / b;
//                }
//                else {
//                    throw runtime_error("Nieznany operator: " + token);
//                }
//                stos.push(wynik);
//
//            }
//        }
//    }
//    
//    return stos.top();
//}
//
//int main() {
//    Tablica<string, 100> tablicaPomiarow;
//
//    ifstream cn("dane-labZTP.txt");
//    if (!cn) {
//        cerr << "Nie mozna otworzyc pliku!" << endl;
//        return 1;
//    }
//
//    string linia;
//    while (getline(cn, linia)) {
//        stringstream ss(linia);
//        string a;
//   
//		getline(ss, a);
//
//
//
//        tablicaPomiarow.dodaj(a);
//		//cout << "Wczytano pomiar ID: " << p.id << endl;
//		//cout << "Debug: " << p.id << ", " << p.temperatura << ", " << p.data << ", " << p.czujnik << endl;
//    }
//
//    cn.close();
//
//
//    cout << string(48, '-') << endl;
//
//    // Wypisywanie danych
//    for (int i = 0; i < tablicaPomiarow.rozmiar(); i++) {
//        try {
//            double wynik = wyliczWyrazenie(tablicaPomiarow[i]);
//			cout << "Wynik wyrazenia: " << wynik << endl;
//        }
//        catch (runtime_error& e) {
//			cerr << "Blad w wyrazeniu: " << e.what() << endl;
//        }
//        cout << left
//             << tablicaPomiarow[i]
//             << endl;
//    }
//
//
//    return 0;
//}


//zadanie 2 przed 3 lab
//int main() {
//	int n;
//	int m = 10;
//	int b = 65;
//	int c = 65 + rand() % (26);
//	int d = 97 + rand() % (26);
//	printf("Gra ASCII\n");
//
//	while (m > 0) {
//		int e = rand() % (2);
//		if (e) {
//			e = d;
//		}
//		else {
//			e = c;
//		}
//		printf("%c\n", e);
//		printf("Podaj numer: \n");
//		scanf_s("%d", &n);
//		if(n==e){
//			printf("Zgadles!\n");
//			m--;
//		}
//		else if (n < c) {
//			printf("Za malo!\n");
//			m--;
//		}
//		else if (n > c) {
//			printf("Za duzo!\n");
//			m--;
//		}
//		c = 65 + rand() % (26);
//
//	}
//
//
//}





//zadanie 3 przed 3 lab


//int main() {
//	  Tablica<string, 100> tablicaPomiarow;
//      int znak_ = 0;
//      int znak__ = 0;
//      int znakgwiazd = 0;
//      int znak2gwizd = 0;
//      int znakcudzyslow = 0;
//      cout << "Tak";
//    ifstream cn("dane-labZTP.txt");
//    if (!cn) {
//        cerr << "Nie mozna otworzyc pliku!" << endl;
//        return 1;
//    }
//    
//    string linia = " ";
//    string cs;
//    getline(cn, linia);
//	cout << linia << "\n";
//
//    while (getline(cn, linia)) {
//      
//        int i = 0;
//        while (linia[i]) {
//            if (linia[i] == '_') {
//                if (linia[i + 1] == '_') {
//                    if (znak__ == 0) {
//                        znak__++;
//                    }
//                    else {
//                        znak__--;
//                    }
//                    linia[i] = '-';
//                    linia[i + 1] = '-';
//
//                }
//                else if (linia[i + 1] != '_') {
//                    linia[i] = '-';
//                    if (znak_ == 0) {
//                        znak_++;
//                    }
//                    else {
//                        znak_--;
//                    }
//                }
//            }
//
//                    
//
//        }
//
//    }
//    cout << linia<< "\n";
//        
//
//}

//zadanie 1 4 cw
//#include <iostream>
//#include <random>
//#include "Stack.h"
//
//
//
//using namespace std;
//int main() {
//    Stack s;
//
////test
//    s.push(5);
//    s.push(1);
//    s.push(9);
//    s.push(4);
//    s.push(7);
//	cout << "Test probny:\n\n";
//    cout << "Min: " << s.getMin() << "\n";
//    cout << "Maks: " << s.getMax() << "\n";
//    cout << "Srednia: " << s.getAverage() << "\n";
//    cout << "Mediana: " << s.getMedian() << "\n";
//
////losowe
//    Stack s2;
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_real_distribution<> dist(0.0, 10.0);
//
//    for (int i = 0; i < 50; i++)
//        s2.push(dist(gen));
//
//    std::cout << "Test random: \n\n";
//    std::cout << "Min: " << s2.getMin() << "\n";
//    std::cout << "Maks: " << s2.getMax() << "\n";
//    std::cout << "Srednia: " << s2.getAverage() << "\n";
//    std::cout << "Mediana: " << s2.getMedian() << "\n";
//
//    return 0;
//}
