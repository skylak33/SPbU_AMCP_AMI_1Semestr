#include <bits/stdc++.h> // стандартные библиотеки 
using namespace std;
typedef long long ll;

signed main(int argc, char** argv) {

    setlocale(LC_ALL, "Russian");
    while (true)
    {   cout << "Введите строку : ";
        string s;
        getline(cin, s);
        bool err = false;
        for (auto c : s) {
            if (c != '+' && c != '-' && (c > '9' ||  c < '0') && (c != ' ')) {
                cout << "Ошибка." << std::endl;
                err = true;
                break;
            }
        }
        if (err) continue;
        ll sum = 0; string current_num = ""; ll multuplier = 1;
        for (auto c : s) {
            if (c == ' ') continue;
            if (c == '+' || c == '-') {
                sum += stoi(current_num) * multuplier;
                (c == '+') ? (multuplier = 1) : (multuplier = -1);
                current_num = "";
            }  else {
                current_num += c;
            }
        }
        cout << sum + (stoi(current_num) * multuplier);
        return 0;
    }

}