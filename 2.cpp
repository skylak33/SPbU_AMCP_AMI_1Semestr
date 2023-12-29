#include <bits/stdc++.h> // стандартные библиотеки
using namespace std;
typedef long long ll;
typedef long double ld;

ld square_and_round(ld number) {
    return round(number * number * 100) / 100.0;
}

signed main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    ifstream infile("file.txt");
    if (!infile.is_open()) {
        cout << "ошибка\n";
        return 0;
    }

    vector<ld> numbers_square;
    set<int> indexes;
    string numbers;
    int k = 0;
    while (getline(infile, numbers)) {
        istringstream iss(numbers);
        ld x;
        while (iss >> x) {
            k++;
            numbers_square.push_back(square_and_round(x));
        }
        indexes.insert(k);
    }

    infile.close();
    ofstream outfile("file.txt");
    for (int i = 0; i < numbers_square.size(); ++i) {
        if (indexes.count(i)) {
            outfile << endl;
        }
        outfile << numbers_square[i] << "\t";
    }

    return 0;
}
