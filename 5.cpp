#include <bits/stdc++.h>
using namespace std;


void printMatrix(vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << "\t";
        }
        cout << endl;
    }

}

signed main(int argc, char** argv) {
    int X;
    cout << "Введите размер матрицы X: ";
    cin >> X;

    vector<vector<int>> matrix(X, vector<int>(X, 1));

    for (int i = 1; i < X; ++i) {
        for (int j = 1; j < X; ++j) {
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
        }
    }
    printMatrix(matrix);
    return 0;
}
