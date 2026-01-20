#include <vector>       // std::vector
#include <random>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>
#include <locale>
#include <list>
#include <algorithm>



// RANDOM  GENERATOR



using namespace std;

class rand_double {
protected:
    static random_device gen;
};
random_device rand_double::gen;

class Urand_double : public rand_double {
    // This distribution produces random numbers in a range[a, b) 
    // where all intervals of the same length within it are equally probable.
    uniform_real_distribution<double> Udist;
public:
    Urand_double(double a, double b) : Udist(a, b) {};
    double operator()() { return Udist(gen); }
};

class Nrand_double : public rand_double {
    // This distribution produces random numbers around the distribution 
    // mean (mi) with a specific standard deviation (sigma).
    normal_distribution<double> Ndist;
public:
    Nrand_double(double mi, double sigma) : Ndist(mi, sigma) {};
    double operator()() { return Ndist(gen); }
};

//int main() {
//    Urand_double U(0, 10); // generator liczb o rozk³adzie jednostajnym z przedzia³u [0,10)
//    vector<double> UV;
//    vector<vector<double>> UO;
//    for (int i = 0; i < 100; ++i) UV.push_back(U());
//
//    Nrand_double N(0, 10); // generator liczb z rozk³adu normalnego N(0,10)
//    vector<double> NV;
//    for (int i = 0; i < 100; ++i) NV.push_back(N());
//
//    system("pause");
//
//    vector < vector<double>> ujemnododatnie;
//    Nrand_double Na(0, 0.1);
//    vector<double> dodatnie;
//    vector<double> ujemne;
//    vector<double> zera;
//    for (int i = 0; i < 100000; ++i) {
//        double l = Na();
//        if (l < 0) {
//            ujemne.push_back(l);
//        }
//        else if (l>0) {
//           dodatnie.push_back(l);
//        }
//        else {
//          zera.push_back(l);
//        }
//        
//        
//    
//    }
//    sort(ujemne.begin(), ujemne.end());
//    sort(dodatnie.begin(), dodatnie.end());
//    sort(zera.begin(), zera.end());
//
//
//    ujemnododatnie.push_back(dodatnie);
//    ujemnododatnie.push_back(zera);
//    ujemnododatnie.push_back(ujemne);
//    
//    string tablica[3] = {"Dodatnie" , "Zera", "Ujemne"};
//    string *p = tablica;
//    cout << "\n\n";
//    for (auto it = ujemnododatnie.begin(); it != ujemnododatnie.end(); it++ ) {
//        auto& row = *it;
//        cout << *p << "\n";
//        p++;
//        for (double x : row) {
//            cout << fixed << setprecision(2) << x << " ";
//        }
//        system("pause");
//        cout << "\n";
//    }
//
//
//    system("pause");
//
//    cout << "Ujemne:" << endl;
//    for (double x : UV)
//        cout << fixed << setprecision(2) << x << " ";
//    cout << endl << endl;
//
//    system("pause");
//
//
//    cout << "UV:" << endl;
//    for (double x : UV)
//        cout << fixed << setprecision(2) << x << " ";
//    cout << endl << endl;
//
//    sort(UV.begin(), UV.end());
//    int j = 1;
//   
//        vector<double> row;
//        for (double x : UV) {
//
//            if (j % 5 != 0) {
//                row.push_back(x);
//                cout << x << "\n";
//
//            }
//            else {
//                UO.push_back(row);
//                row = {};
//            }
//            j++;
//
//        }
//    
//
//
//    cout << "UO:" << endl;
//
//
//        for (auto it = UO.begin(); it != UO.end();it++) {
//            auto& row = *it;
//            //row.sort();
//            for (auto it = row.begin(); it != row.end(); it++) {
//                
//                double x = *it;
//    
//                //printf("%7.2lf ", x);
//                cout << fixed << setprecision(10) << x << " ";
//    
//            }
//            cout << "\n";
//        }
//    
//    
//
//
//    system("pause");
//
//    cout << "UV:" << endl;
//    for (double x : UV)
//        cout << fixed << setprecision(2) << x << " ";
//    cout << endl << endl;
//
//    
//    system("pause");
//
//
//    cout << "NV:" << endl;
//    for (double x : NV)
//        cout << fixed << setprecision(2)<<x << " ";
//    cout << endl;
//
//    system("pause");
//
//    return 0;
//}



// ZADANIE 1

using namespace std;

vector<vector<double>>* wczytajITansponuj(deque<deque<double>>  macierz)
{
 

   

    // Wymiary macierzy
    size_t wiersze = macierz.size();
    size_t kolumny = macierz[0].size();

    // Dynamiczna alokacja transponowanej macierzy
    vector<vector<double>>* transpozycja =
        new vector<vector<double>>(kolumny, vector<double>(wiersze));

    // Transpozycja
    for (size_t i = 0; i < wiersze; ++i)
    {
        for (size_t j = 0; j < kolumny; ++j)
        {
            (*transpozycja)[j][i] = macierz[i][j];
        }
    }

    return transpozycja;
}

//int main() {
//	ifstream file("qv-lab4.txt");
//	deque<deque<double>> kolejka;
//
//	if (!file.is_open()) {
//		cerr << "BLAD";
//		return 1;
//	}
//	string line;
//
//    while (std::getline(file, line)) {
//        std::stringstream ss(line);
//        std::deque<double> row;
//
//        double value;
//        while (ss >> value) {
//            row.push_back(value);
//        }
//
//        // dodajemy tylko jeœli wiersz nie by³ pusty
//        if (!row.empty()) {
//            kolejka.push_back(row);
//        }
//    }
//
//	file.close();
//
//
//    for (const auto& row : kolejka) {
//        for (double x : row) {
//            printf("%7.2lf ", x);
//           // std::cout << x << " ";
//        }
//        std::cout << "\n";
//    }
//    std::vector<std::vector<double>>* mat = wczytajITansponuj(kolejka);
//    
//    printf("\n-------------------------------\n\n");
//    for (const auto& wiersz : *mat)
//    {
//        for (double x : wiersz)
//            printf("%7.2lf ", x);
//        cout << endl;
//    }
//
//}




//ZADANIE 2

//using namespace std;
//int main() {
//    std::setlocale(LC_ALL, "");
//	ifstream file("lab6.txt");
//	list<list<string>> kolejka;
//
//	if (!file.is_open()) {
//		cerr << "BLAD";
//		return 1;
//	}
//	string line;
//
//    while (std::getline(file, line)) {
//        std::stringstream ss(line);
//        std::list<string> row;
//
//        string value;
//        while (ss >> value) {
//            row.push_back(value);
//        }
//   
//       
//        // dodajemy tylko jeœli wiersz nie by³ pusty
//        if (!row.empty()) {
//            kolejka.push_back(row);
//        }
//    }
//
//	file.close();
//
//
//    for (auto it = kolejka.begin(); it != kolejka.end(); it++) {
//        const auto& row = *it;
//        //sort(row.begin(), row.end()); 
//        for (auto it = row.begin(); it != row.end(); it++) {
//            string x = *it;
//            //printf("%7.2lf ", x);
//           std::cout << fixed << setprecision(10) << x << " ";
//
//        }
//        std::cout << "\n";
//    }
//   // kolejka.sort();
//
//    std::cout << "\n\n\n\n\n\n";
//
//    for (auto it = kolejka.begin(); it != kolejka.end();it++) {
//        auto& row = *it;
//        row.sort();
//        for (auto it = row.begin(); it != row.end(); it++) {
//            
//            string x = *it;
//
//            //printf("%7.2lf ", x);
//            cout << fixed << setprecision(10) << x << " ";
//
//        }
//        cout << "\n";
//    }
//
//}