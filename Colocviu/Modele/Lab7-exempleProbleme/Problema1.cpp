#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n, r, c;
int ok1 = 0, ok2 = 0;
vector<int> graf[10000000];
int tati[10000000];
int viz[10000000];

void dfs(int nod, int tata){
    viz[nod] = 1;
    for(auto vecin : graf[nod]){
      if(viz[vecin] == 0){
          tati[vecin] = nod;
          dfs(vecin, nod);
      }
    }
}

void dfs(int nod) {
    viz[nod] = 1;
    for (auto vecin : graf[nod]) {
        if (viz[vecin] == 0 && vecin != tati[nod]) {
            cout << vecin << " ";
            ok2 = 1;
            dfs(vecin);
        }
    }
}

int main() {
    cin >> n >> r >> c;
    for (int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        graf[u].push_back(v);
        graf[v].push_back(u);
    }
    dfs(r, 0);

    int curr = tati[c];
    while(curr != 0){
        cout << curr << " ";
        ok1 = 1;
        curr = tati[curr];
    }
    if (ok1 == 0)
        cout << "0";
    cout << endl;

    for (int i = 1; i <= n; ++i){
        viz[i] = 0;
    }

    dfs(c);
    if (ok2 == 0)
        cout << "0";
    return 0;
}
