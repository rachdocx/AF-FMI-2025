#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ifstream in("bfs.in");
    ofstream out("bfs.out");

    int n, m, start;
    in >> n >> m >> start;

    vector<vector<int>> vecin(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        in >> x >> y;
        vecin[x].push_back(y);
    }

    vector<int> dist(n + 1, -1);
    vector<bool> viz(n + 1, false);

    queue<int> Q;
    Q.push(start);
    viz[start] = true;
    dist[start] = 0;

    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();

        for (int v : vecin[node]) {
            if (!viz[v]) {
                viz[v] = true;
                dist[v] = dist[node] + 1;
                Q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        out << dist[i] << " ";
    }

    return 0;
}
