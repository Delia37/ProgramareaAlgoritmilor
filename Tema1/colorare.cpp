#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MOD 1000000007;

// functia pow optimizata
long long pow(int base, int exp) {
    if (exp == 0) {
        return 1;
    } else if (exp % 2 == 0) {
        long long half_pow = pow(base, exp / 2) % MOD;
        return half_pow * half_pow % MOD;
    } else {
        long long half_pow = pow(base, (exp - 1) / 2) % MOD;
        return base * half_pow * half_pow % MOD;
    }
}

int count(int k , const vector<pair<int, char>>& zones) {
    long long result = 1;

    if (zones[0].second == 'H') {
        result = 6 * pow(3, zones[0].first - 1) % MOD;
    } else {
        result = 3 * pow(2, zones[0].first - 1) % MOD;
    }

    for (int i = 1; i < k; i++) {
        int X = zones[i].first;  // numarul de zone
        char T = zones[i].second;  // tipul zonei

        if (T == 'H') {
            if (zones[i - 1].second == 'H') {  // cazul HxH
                result = result * pow(3, X) % MOD;
            } else {
                result = result * 2 * pow(3, X - 1) % MOD;  // cazul VxH
            }
        } else {
            if (zones[i - 1].second == 'H') {  // cazul HxV
                result = result * pow(2, X - 1) % MOD;
            } else {
                result = result * pow(2, X) % MOD;  // cazul VxV
            }
        }
    }
    return result;
}


int main() {
    ifstream fin("colorare.in");
    ofstream fout("colorare.out");

    long long K;
    fin >> K;
    vector<pair<int, char>> zones(K);
    for (int i = 0; i < K; ++i) {
        int X;
        char T;
        fin >> X >> T;
        zones[i] = {X, T};
    }
    fin.close();

    long long result = count(K, zones);
    fout << result;

    fout.close();

    return 0;
}
