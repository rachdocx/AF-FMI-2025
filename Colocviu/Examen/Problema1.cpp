#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int NMAX = 100005;
vector <int> G[NMAX];
int val[NMAX];
int dist[NMAX];
int viz[NMAX];
vector<int> val1 [NMAX];

void bfs(int nod) {
    queue<int> Q;
    Q.push(nod);
    viz[nod]=1;
    dist[nod]=0;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        val1[dist[cur]].push_back(val[cur]);
        for (auto & vecin : G[cur]) {
            if (!viz[vecin]) {
                viz[vecin]=1;
                dist[vecin]=dist[cur]+1;
                Q.push(vecin);
            }
        }
    }
}
int main() {
    int n;
    cin>>n;

    for (int i=1; i<=n; ++i) {
        cin >> val[i];
    }
    for (int i=1; i<n; ++i) {
        int u, v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bfs(1);

    int max_dist = 0;

    for (int i=1; i<=n; ++i) {
        if (dist[i] > max_dist)
            max_dist = dist[i];
    }

    for (int i=0; i<=max_dist; ++i) {
            if (val1[i].size() > 0)
                sort(val1[i].begin(), val1[i].end(), greater<int>());

    }

    int sol = -9999999;

    for (int i=0; i<=max_dist; ++i) {
        if (val1[i].size() >= 2) {
            int s = val1[i][0] + val1[i][1];
            if (s > sol)
                sol = s;

        }

        if (i+1 <=max_dist && val1[i].size() > 0 && val1[i+1].size() > 0) {
            int s;
            s= val1[i][0] + val1[i + 1][0];
            if (s > sol)
                sol = s;
        }

        if (i+2 <= max_dist && val1[i].size()>0 &&val1[i+2].size() > 0) {
            int s = val1[i][0] + val1[i+2][0];
            if (s > sol)
                sol = s;
        }
    }

    cout << sol;
    return 0;
}
