#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// structura ce retine informatia
struct cuvinte {
    string word;  // cuvantul curent
    int length;  // lungimea cuvantului
    int count[26];  // de cate ori apare o litera in cuvant
    double procent[26];
};

void citire(ifstream& fin, vector<cuvinte>& words, int& N) {
    fin >> N;
    words.resize(N);
    string cuv;
    for (int i = 0; i < N; ++i) {
        fin >> cuv;
        // completez datele
        words[i].word = cuv;
        words[i].length = cuv.length();
        fill(words[i].count, words[i].count + 26, 0);
        for (char c : cuv) {
            words[i].count[c - 'a']++;
        }
        for (int j = 0; j < 26; ++j) {
            words[i].procent[j] = static_cast<double>(words[i].count[j]) /
                         words[i].length;
        }
    }
}

// comparartor bazat pe procent
bool compareWords(const cuvinte& a, const cuvinte& b, int index) {
    if (a.procent[index] != b.procent[index])
        return a.procent[index] > b.procent[index];
    // daca procentele sunt egale
    return a.length > b.length;
}

// sortarea cuvintelor
void sortare(vector<cuvinte>& words, int index) {
    sort(words.begin(), words.end(), [&](const cuvinte& a, const cuvinte& b) {
        return compareWords(a, b, index);
    });
}

// construieste parola pe baza unui anumit caracter
int password(vector<cuvinte>& words, int ch) {
    vector<int> current_count(26, 0);
    int total = 0;
    int max_ch = 0;

    for (const auto& w : words) {
        bool can_add = true;
        int new_len = total + w.length;
        int lim = new_len/ 2 + 1;

        if (current_count[ch] + w.count[ch] < lim) {
            can_add = false;
        }

        if (can_add) {
            for (int i = 0; i < 26; ++i) {
                current_count[i] += w.count[i];
            }
            total = new_len;
            max_ch = max(max_ch, total);
        }
    }

    return max_ch;
}

int main() {
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");

    int N;
    vector<cuvinte> words;

    citire(fin, words, N);

    int max_len = 0;
    for (int i = 0; i < 26; ++i) {
        sortare(words, i);
        max_len = max(max_len, password(words, i));
    }

    fout << max_len;

    return 0;
}
