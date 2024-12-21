#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MOD 1000000007;

vector<int> Graph1[100001];  // lista de adiacenta pentru primul graf
vector<int> Graph2[100001];  // list de adiacenta pentru al doilea graf

// Functie ce adauga muchii in graf
void addEdge(vector<int> graph[], int src, int dst) {
    graph[src].push_back(dst);
}

// Functie de citire pentru grafuri
void read(vector<int> graph[], int M, ifstream& fin) {
    int u, v;
    for (int i = 0; i < M; ++i) {
        fin >> u >> v;  // citesc o muchie
        addEdge(graph, u, v);  // o adaug
    }
}

// Functie ce verifica daca un element se gaseste intr-o lista
bool gasit(const vector<int>& list, int x) {
    for (int el : list) {
        if (el == x) {
            return true;
        }
    }
    return false;
}

// Fac sortarea topologica folosind BFS
vector<int> topologicalSort(vector<int> graph[], int N) {
    vector<int> in_degree(N + 1, 0);
    vector<int> topsort;  // lista sortata
    queue<int> q;  // coada pentru lucrul cu noduri

    // Calculez in-degrees
    for (int i = 1; i <= N; ++i) {
        for (int j : graph[i]) {
            ++in_degree[j];
        }
    }

    // Pun in coada nodurile cu in_degree 0
    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    // BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topsort.push_back(node);

        // Scad in-degree-urile vecinilor si pun in coada nodurile cu 0
        for (int neigh : graph[node]) {
            --in_degree[neigh];
            if (in_degree[neigh] == 0) {
                q.push(neigh);
            }
        }
    }

    // Verific daca apar cicluri
    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] > 0) {
            return {};
        }
    }

    return topsort;
}

// Functie ce gaseste numarul de lanturi elementare
int count(int N) {
    vector<int>sortat = topologicalSort(Graph1, N);
    if (sortat.empty()) {
        return 0;  // nu s-a putut face sortarea topologica
    }

    vector<int> dp(N + 1, 0);
    dp[1] = 1;  // incep de la nodul 1

    for (int nod : sortat) {
        for (int next : Graph1[nod]) {
            if (gasit(Graph2[nod], next)) {
                // verific daca muchia e comuna
                dp[next] = (dp[next] + dp[nod]) % MOD;
            }
        }
    }

    return dp[N];
}

int main() {
    ifstream fin("numarare.in");
    ofstream fout("numarare.out");
    int N, M;

    fin >> N >> M;
    read(Graph1, M, fin);
    read(Graph2, M, fin);

    int result = count(N);
    fout << result << endl;

    fin.close();
    fout.close();
    return 0;
}
