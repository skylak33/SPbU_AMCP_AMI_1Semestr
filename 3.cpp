#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
map <ll, vector<vector<int>>> print;

void generateMatrix(vector<vector<int>>& matrix, int K) {
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dis(0, 9);

    matrix.resize(K, vector<int>(K));

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            matrix[i][j] = dis(rnd);
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

void findAllPaths(const vector<vector<int>>& matrix, int i, int j, vector<int>& currentPath) {
    int K = matrix.size();
    vector<int> path;
    if (i == K - 1 && j == K - 1) {
        ll sum = 0;
        for (int element : currentPath) {
            path.push_back(element);
            sum += element;
        }
        print[sum].push_back(path);
        return;
    }

    if (i < K - 1) {
        currentPath.push_back(matrix[i + 1][j]);
        findAllPaths(matrix, i + 1, j, currentPath);
        currentPath.pop_back();
    }

    if (j < K - 1) {
        currentPath.push_back(matrix[i][j + 1]);
        findAllPaths(matrix, i, j + 1, currentPath);
        currentPath.pop_back();
    }
}
void printAllPaths() {
    for (auto path : print) {
        cout << "Пути с суммой - " << path.first << " :\n";
        for (auto v : path.second) {
            cout << "\t";
            for (auto u : v) {
                cout << u << " ";
            }
            cout << std::endl;
        }
    }
}
void findPaths(const vector<vector<int>>& matrix, int K) {
    int i = 0, j = 0;
    vector<int> path;
    path.push_back(matrix[i][j]);

    findAllPaths(matrix, i, j, path);
    printAllPaths();
}

signed main(int argc, char** argv) {
    int K;

    cout << "Введите размер матрицы K: ";
    cin >> K;

    if (K <= 0) {
        cout << "Размер матрицы должен быть больше 0." << endl;
        return 1;
    }

    vector<vector<int>> matrix;
    generateMatrix(matrix, K);

    cout << "Сгенерированная матрица:" << endl;
    printMatrix(matrix);

    findPaths(matrix, K);

    return 0;
}
