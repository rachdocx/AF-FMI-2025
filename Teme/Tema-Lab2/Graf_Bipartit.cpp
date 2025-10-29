#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<vector<int>> graf;
vector<int> team;
bool ok = 1;

using namespace std;

void bfs(int start) {
    queue<int> Q;
    team[start] = 1;
    Q.push(start);

    while (!Q.empty()) {
        int nod = Q.front();
        Q.pop();

        for (int vecin: graf[nod]) {
            if (team[vecin] == 0) {
                if (team[nod] == 1)
                    team[vecin] = 2;
                else
                    if (team[nod] == 2)
                        team[vecin] = 1;
                Q.push(vecin);
            }
            else if (team[vecin] == team[nod]) {
                ok = false;
                return;
            }

        }

    }
}
int main() {
    int n, m;
    cin >> n >> m;
    graf.resize(n + 1);
    team.resize(n+1);
    for (int i = 0; i <m; ++i) {
        int x, y;
        cin >> x >> y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
    for (int i=1; i <= n; ++i) {
        if (team[i] == 0)
            bfs(i);
    }
    if (!ok)
        cout << "Impossible!";
    else
        for (int i = 1; i <=n; ++i)
            cout<< team[i] << " ";
    return 0;
}
