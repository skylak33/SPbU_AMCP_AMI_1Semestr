#include <bits/stdc++.h>
using namespace std;

double func(double x) {
    return x / 3 + 20 * pow(x, 6);
}

int main() {
    //mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    const int seed = 0;
    mt19937 rnd(seed);
    const double xMin = 0.0;
    const double xMax = 0.4;
    const double yMax = 1.0;

    const int totalPoints = 1e6;
    int pointsUnderCurve = 0;
    int points;
    uniform_real_distribution<double> disX(xMin, xMax);
    uniform_real_distribution<double> disY(0.0, yMax);

    double area = 0.0;

    for (int i = 0; i < totalPoints; ++i) {
        double x = disX(rnd);
        double y = disY(rnd);

        if (y <= func(x)) {
            pointsUnderCurve++;
        }

        area = static_cast<double>(pointsUnderCurve) / (i+1) * (xMax - xMin) * yMax;

        if (abs(area - 0.031) >= 0.001) {
            points = i;
        }
    }

    area = static_cast<double>(pointsUnderCurve) / totalPoints * (xMax - xMin) * yMax;

    cout << points;

    return 0;
}
