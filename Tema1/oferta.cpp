#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

double minim3(double a, double b, double c) {
    return min(a, min(b, c));
}


// functie ce calculeaza pretul dupa reguli
double calcul(vector<double>& prices) {
    int n = prices.size();
    vector<double> dp(n + 1, 0);

    // iterez prin produse
    for (int i = 1; i <= n; ++i) {
        // daca suntem la primul produs
        if (i == 1) {
            dp[i] = prices[i - 1];
        } else if (i == 2) {
            // daca suntem la al doilea, luam si cazul de grupare in 2
            double min_price = min(prices[i-2], prices[i-1]);
            double max_price = max(prices[i-2], prices[i-1]);
            double grup2 = max_price + min_price / 2;
            dp[i] = min(grup2, prices[i - 1] + dp[i-1]);
        } else {  // in rest, luam toate cazurile
            // minimuri pentru grupele de 2
            double min2 = min(prices[i-2], prices[i-1]);
            double max2 = max(prices[i-2], prices[i-1]);

            double min3 = minim3(prices[i-3], prices[i-2], prices[i-1]);

            double grup2 = dp[i - 2] + max2 + min2 / 2;

            double grup3 = dp[i - 3] + prices[i - 1] + prices[i - 2]
            + prices[i - 3] - minim3(prices[i-3], prices[i-2], prices[i-1]);

            // iau cazul cel mai ieftin
            dp[i] = minim3(grup2, grup3, dp[i - 1] + prices[i-1]);
        }
    }

    return dp[n];  // Return the minimum price
}

int main() {
    ifstream fin("oferta.in");
    ofstream fout("oferta.out");

    int n, k;
    fin >> n;
    fin >> k;

    vector<double> prices(n);
    for (int i = 0; i < n; ++i) {
        fin >> prices[i];
    }

    double result = calcul(prices);
    if (k == 1) {
        fout << fixed << result;
    } else {
        fout << -1;  // nu tratez cazurile de bonus
    }

    fin.close();
    fout.close();

    return 0;
}
