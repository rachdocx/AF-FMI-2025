
#include <fstream>
using namespace std;
int n, m;
vector<pair<int, int>> G[100005];
int grad[100005], start_muchii[100005];
bool muchie_fol[500005];
vector<int> solutie;
ifstream cin("ciclueuler.in");
ofstream cout("ciclueuler.out");
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
        grad[u]++;
        grad[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (grad[i] % 2 != 0) {
            cout << -1;
            return 0;
        }
    }

    stack<int> stiva;
    stiva.push(1);
    while (!stiva.empty()) {
        int nod = stiva.top();
        if (start_muchii[nod] < G[nod].size()) {
            int vecin = G[nod][start_muchii[nod]].first;
            int id = G[nod][start_muchii[nod]].second;
            ++start_muchii[nod];

            if (!muchie_fol[id]) {
                muchie_fol[id] = true;
                stiva.push(vecin);
            }
        }
        else {
            solutie.push_back(nod);
            stiva.pop();
        }
    }
    if (solutie.size() != m + 1) {
        cout << -1;

    }
    else {
        for (int i = 1; i < solutie.size(); ++i) {
            cout << solutie[i]<< ' ';
        }
    }
    return 0;
}
