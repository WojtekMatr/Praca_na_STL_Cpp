#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>

// do wlaczenia polskich znakow
#include <locale>
#include <windows.h>




template <class T>
struct wyzszy {
    bool operator() (const T& x, const T& y) const {
        return x.length() < y.length();
    };
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;
};


template <class T>
struct sort {
    bool operator() (const T& x, const T& y) const {
        
        return x.size() < y.size();
    };
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef bool result_type;
};


using namespace std;
//ListaKolejek = std::list<std::priority_queue<std::string>>;
using ListaKolejek = list<priority_queue<string, vector<string>, wyzszy<string>>>;
//using BaseList = list<KolejkaSlow>;



struct DwieKolejki {
    bool operator()(
         priority_queue<string, vector<string>, wyzszy<string>>& a,
         priority_queue<string, vector<string>, wyzszy<string>>& b
        )  
    
    {
        return a.size() > b.size();
    }
};

ostream& operator<<(
    ostream& o,
    priority_queue<string, vector<string>, wyzszy<string>>& q
    ) {
    o << q.size() << ": ";

    while (!q.empty()) {
        o << q.top() << " ";
        q.pop(); 
    }

    o << '\n';
    return o;
}

class Mikser: public ListaKolejek {

public:
	//static ListaKolejek list;
	Mikser() {}
	Mikser(string zrodlo) {
		cout << "Powstal Mikser\n";
		open(zrodlo);
	}
	~Mikser() {
		this->clear();
		cout << "Mikser zostal zniszczony\n";
	}

    int open(const string& zrodlo) {
        ifstream file(zrodlo);
        if (!file.is_open()) {
            cerr << "BLAD\n";
            return 1;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            priority_queue<string, vector<string>, wyzszy<string>> row;
            string value;

            while (ss >> value) {
                row.push(value);
            }

            if (!row.empty()) {
                this->push_back(row); 
            }
        }
        cout << this->size() << "\n";
        return 0;
    }
    void print() const {
        int i = 1;
        for (const auto& q : *this) {
            priority_queue<string, vector<string>, wyzszy<string>> temp = q;
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }

    void execute() {
        this->sort(DwieKolejki());
    }

    void write(const string& nazwaPliku) {
        ofstream file(nazwaPliku);
        if (!file.is_open()) {
            cerr << "BLAD\n";
            return;
        }

        for (auto& q : *this) {
            file << q; 
        }

        file.close();
    }



};




int main() {
    //do wlaczenia polskich znakow
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "pl_PL.UTF-8");




	ListaKolejek *list;
	Mikser mikser = Mikser();
    cout << "Open\n";
	mikser.open("mistrz.txt");
    cout << "Print\n";
    mikser.print();
    cout << "Execute\n";
    mikser.execute();
    cout << "Print (posortowany)\n";
    mikser.print();
    cout << "Write\n";
    mikser.write("tak.txt");
    mikser.print();


    //mikser.write();




}

