#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();
const int MAXN = 100005;

// Structura pentru muchie cu nodul de destinație și cost
struct Edge {
    int to;
    long long cost;
};

struct DijkstraResult {
    vector<long long> d;  // distanțele minime de la sursă la fiecare nod
    vector<int> p;  // predecesorii pe cel mai scurt drum

    explicit DijkstraResult(int n) : d(n + 1, INF), p(n + 1, -1) {}
};

// Liste de adiacență pentru graf și graf transpus
vector<Edge> Graph[MAXN], rGraph[MAXN];

DijkstraResult dijkstra(int src, vector<Edge> graph[], int n) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;
    DijkstraResult result(n);
    result.d[src] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > result.d[u]) continue;

        for (const auto &edge : graph[u]) {
            int v = edge.to;
            long long newDist = d + edge.cost;
            if (newDist < result.d[v]) {
                result.d[v] = newDist;
                result.p[v] = u;
                pq.emplace(newDist, v);
            }
        }
    }
    return result;
}

int main() {
    ifstream fin("drumuri.in");
    ofstream fout("drumuri.out");

    int N, M;
    fin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        long long c;
        fin >> a >> b >> c;
        Graph[a].push_back({b, c});
        rGraph[b].push_back({a, c});  // construiesc graf transpus
    }

    int x, y, z;
    fin >> x >> y >> z;

    // aplic Dijkstra din x, y în graf și din z în graf transpus
    auto fromX = dijkstra(x, Graph, N);
    auto fromY = dijkstra(y, Graph, N);
    auto fromZ = dijkstra(z, rGraph, N);

    long long min_cost = INF;
    for (int u = 1; u <= N; ++u) {
        // Verific accesibilitatea și calculez costul minim
        if (fromX.d[u] != INF && fromY.d[u] != INF && fromZ.d[u] != INF) {
            long long curent = fromX.d[u] + fromY.d[u] + fromZ.d[u];
            if (curent < min_cost) {
                min_cost = curent;
            }
        }
    }

    fout << min_cost;

    fin.close();
    fout.close();
    return 0;
}
