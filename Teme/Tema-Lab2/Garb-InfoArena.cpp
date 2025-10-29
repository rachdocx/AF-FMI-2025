#include <iostream>
#include <fstream>
using namespace std;
ifstream f("garb.in");
ofstream g("garb.out");
vector<vector<int>> graf;
vector<int> viz;

void dfs(int start, int &noduri, int &muchii) {
    viz[start] = true;
    ++noduri;
    muchii += (int)graf[start].size();
    for (int i = 0; i < graf[start].size(); ++i) {
        int vecin = graf[start][i];
        if (!viz[vecin]) {
            dfs(vecin, noduri, muchii);
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    graf.resize(n+1);
    viz.assign(n+1, 0);
    for (int i=0; i<m; ++i) {
        int x,y;
        cin >> x >> y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
    int nrElConexe = 0;
    int nrMuchiiDeScos = 0;
    for (int i = 1; i <= n; ++i) {
        if (!viz[i]) {
            int noduri = 0, muchii = 0;
            dfs(i, noduri, muchii);
            ++nrElConexe;
            muchii /= 2;
            nrMuchiiDeScos += muchii - noduri + 1;
        }
    }
    cout << nrElConexe -1 <<" "<< nrMuchiiDeScos;
    return 0;
}
