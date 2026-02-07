#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int NMAX = 3999;
struct edge {
    int u, v, c;

    bool operator<(const edge &a) const {
        return c < a.c;
    }
};

int n, m;
vector<edge> muchii;
int tata[NMAX];
vector<int> G[NMAX];
int viz[NMAX];
int find(int x) {
    if (tata[x] == 0)
        return x;
    return tata[x] = find(tata[x]);
}

void reuniune(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    tata[ry] = rx;
}
void bfs(int start, vector<int> & noduri) {
    queue<int> Q;
    Q.push(start);
    viz[start] = 1;
    noduri.push_back(start);
    while (!Q.empty()) {
        int nod = Q.front();
        Q.pop();
        for (int & vecin : G[nod]) {
            if (!viz[vecin]) {
                viz[vecin] = 1;
                noduri.push_back(vecin);
                Q.push(vecin);
            }
        }

    }

}
int main() {
    cin>> n>> m;

    for (int i=0; i<m; ++i) {
        int u, v, c;
        cin >>u >> v >>c;
        muchii.push_back({u,v,c});
    }
        sort(muchii.begin(), muchii.end());

        int cost = 0;

        int muchiiSol = 0;

        for (auto & muchie : muchii) {
            if (find(muchie.u) != find(muchie.v)) {
                reuniune(muchie.u, muchie.v);
                cost += muchie.c;

                G[muchie.u].push_back(muchie.v);
                G[muchie.v].push_back(muchie.u);

                ++muchiiSol;
                if (muchiiSol == n -3)
                    break;

            }
        }
    cout << cost << endl;

    for (int i=1; i<=n; ++i) {
        if (!viz[i]) {
            vector<int> componente;
            bfs(i, componente);
            cout<<componente.size();
            for (int & x: componente) {
                cout << " "<< x;
            }
            cout << endl;
        }
    }
    return 0;
}
