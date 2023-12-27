#include <bits/stdc++.h>
using namespace std;

double func(double x) {
    return x / 3 + 20 * pow(x, 6);
}

signed main(int argc, char** argv) {
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

    const double xMin = 0.0;
    const double xMax = 0.4;
    const double yMax = 1.0;

    const int totalPoints = 1e7;
    int pointsUnderCurve = 0;

    uniform_real_distribution<double> disX(xMin, xMax);
    uniform_real_distribution<double> disY(0.0, yMax);

    for (int i = 0; i < totalPoints; ++i) {
        double x = disX(rnd);
        double y = disY(rnd);

        if (y <= func(x)) {
            pointsUnderCurve++;
        }
    }

    double area = static_cast<double>(pointsUnderCurve) / totalPoints * (xMax - xMin) * yMax;

    cout << "Приближенная площадь фигуры методом Монте-Карло: " << area << endl;

    return 0;
}