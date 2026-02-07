#include <iostream>
#include <fstream>
using namespace std;
int n, m;
vector<int> graf[100000];
int viz[1000000];
int niv[100000];
int niv_min[100000];
void dfs(int nod, int tata) {
    viz[nod] = 1;
    niv_min[nod] = niv[nod];
    int copii = 0;
    int comp_bic = 0;
    for (auto vecin : graf[nod]) {
        if (vecin == tata)
            continue;
        if (viz[vecin] == 1) {
            niv_min[nod] = min(niv_min[nod], niv[vecin]);
        }
        else {
            ++copii;
            niv[vecin] = niv[nod] + 1;
            dfs(vecin, nod);
            niv_min[nod] = min(niv_min[nod], niv_min[vecin]);

        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        graf[u].push_back(v);
        graf[v].push_back(u);
    }

    return 0;
}
