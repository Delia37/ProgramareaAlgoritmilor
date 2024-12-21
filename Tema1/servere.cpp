#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// calculez formula
double calcul_test(const vector<int>& P, const vector<int>& C,
                     double test_val) {
    double ret = P[0] - abs(C[0] - test_val);
    for (size_t i = 1; i < P.size(); i++) {
        double curent = P[i] - abs(C[i] - test_val);
        if (curent < ret)
            ret = curent;
    }
    return ret;
}

int main() {
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    int N;
    fin >> N;

    vector<int> P(N);
    vector<int> C(N);

    for (int i = 0; i < N; i++)
        fin >> P[i];

    int min_curent, max_curent;
    fin >> C[0];
    min_curent = max_curent = C[0];
    for (int i = 1; i < N; i++) {
        fin >> C[i];
        if (C[i] < min_curent)
            min_curent = C[i];
        else if (C[i] > max_curent)
            max_curent = C[i];
    }

    double rez = calcul_test(P, C, min_curent);

    double start = min_curent + 0.1;
    double end = max_curent;
    double mid, val_mid;

    while (end - start > 0.1) {
        mid = (start + end) / 2;
        val_mid = calcul_test(P, C, mid);
        double trend = calcul_test(P, C, mid - 0.1);
        // sunt pe partea cand valorile au inceput sa scada
        if (trend >= val_mid)
            // trebuie sa caut in partea stanga
            end = mid;
        else  // inca mai urca deci caut in dreapta
            start = mid;
    }
    rez = val_mid;

    for (double i = start; i <= end; i += 0.1) {
        double test = calcul_test(P, C, i);
        if (test > rez)
            rez = test;
    }

    fout << fixed;
    fout.precision(1);
    fout << rez;

    fin.close();
    fout.close();

    return 0;
}
