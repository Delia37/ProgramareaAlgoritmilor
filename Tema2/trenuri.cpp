#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

vector<int> Graph[100001];
// Link intre numele si indicele orasului
unordered_map<string, int> it;
int nr = 0;  // numarul de orase diferite

void addEdge(int src, int dst) {
    Graph[src].push_back(dst);
}

int get_index(string& oras) {
    // Verific daca orasul are index
    if (it.count(oras) == 0) {
        // daca nu, ii dau un nou indice
        it[oras] = nr;
        nr++;
    }
    return it[oras];
}

vector<int> topologicalSort(int N) {
    vector<int> inDegree(N, 0);
    vector<int> sorted;
    queue<int> q;

    for (int i = 0; i < N; ++i) {
        for (int to : Graph[i]) {
            inDegree[to]++;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        sorted.push_back(node);

        for (int to : Graph[node]) {
            --inDegree[to];
            if (inDegree[to] == 0) {
                q.push(to);
            }
        }
    }

    return sorted;
}

// Functie ce calculeaza maximul de orase ce pot fi vizitate
int max_orase(int start, int end) {
    vector<int> maxim(nr, 0);
    maxim[start] = 1;  // primul e vizitat

    vector<int> sortat = topologicalSort(nr);
    for (int oras : sortat) {
        if (maxim[oras] > 0) {
            int curent = maxim[oras];
            for (int neigh : Graph[oras]) {
                if (maxim[neigh] < curent + 1) {
                    maxim[neigh] = curent + 1;
                }
            }
        }
    }

    return maxim[end];
}

int main() {
    ifstream fin("trenuri.in");
    ofstream fout("trenuri.out");

    string start, end;
    fin >> start >> end;

    int M;
    fin >> M;

    string src, dest;
    for (int i = 0; i < M; ++i) {
        fin >> src >> dest;
        addEdge(get_index(src), get_index(dest));
    }

    int result = max_orase(get_index(start), get_index(end));

    fout << result << endl;

    fin.close();
    fout.close();

    return 0;
}
