#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int max_len(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int m = B.size();

    int i = 0, j = 0;

    // pastrez primele elemente in sume
    int sum1 = A[i];
    int sum2 = B[j];

    int len = 0;
    while (i < n && j < m) {
        if (sum1 == sum2) {
            len ++;  // am mai gasit o egalitate
            i++;
            j++;
            sum1 = A[i];
            sum2 = B[j];
        } else if (sum1 < sum2) {
            while (sum1 < sum2) {
                sum1 += A[i+1];
                i++;
            }
            A[i] = sum1;
        } else if (sum1 > sum2) {
            while (sum1 > sum2) {
                sum2 += B[j+1];
                j++;
            }
            B[j] = sum2;
        }
    }

    // verific daca se poate aplica compresia
    if (i < n || j < m) {
        return -1;
    }

    return len;
}

int main() {
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    int n, m;
    fin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        fin >> A[i];
    }
    fin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; ++i) {
        fin >> B[i];
    }

    int result = max_len(A, B);

    fout << result;

    fin.close();
    fout.close();

    return 0;
}
