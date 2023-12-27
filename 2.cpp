#include <bits/stdc++.h> // стандартные библиотеки
using namespace std;
typedef long long ll;
typedef long double ld;

ld square_and_round(ld number) {
    return round(number * number * 100) / 100.0;
}

signed main(int argc, char** argv) {
    ifstream infile("file.txt");
    if (!infile.is_open()) {
        cout << "ошибка\n";
        return 0;
    }

    vector<ld> numbers;
    ld number;

    while (infile >> number) {
        numbers.push_back(square_and_round(number));
    }

    infile.close();

    ofstream outfile("file.txt");
    for (const auto& num : numbers) {
        outfile << num << " ";
    }

    return 0;
}
