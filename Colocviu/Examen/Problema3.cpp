#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int NMAX= 999999;
vector<pair<int, int>> G[NMAX];
int viz[NMAX];
pair<int, int> sol[NMAX];

int n,m;

void dfs(int nod) {
    while (!G[nod].empty()) {
        pair<int, int> p = G[nod].back();
        G[nod].pop_back();

        int v = p.first;
        int i = p.second;

        if (viz[i])
            continue;

        viz[i] = 1;
        sol[i] = {nod,v};

        dfs(v);
    }
}
int main() {
    cin>>n>>m;
    for (int i=1; i<=m;++i) {
        int u,v;
        cin>>u>>v;
        G[u].push_back({v,i});
        G[v].push_back({u,i});


    }

    for (int i=1; i<=n;++i) {
                    dfs(i);
    }

    for (int i=1; i<=m;++i) {
        cout<<sol[i].second<<" "<<sol[i].first<<endl;
    }
    return 0;
}
