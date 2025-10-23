#include <iostream>
#include <vector>
using namespace std;
const int N = 100;
vector<int> graf[N];
bool vizitat[N];
void DFS(int nod) {
    vizitat[nod] = true;
    for (int i = 0; i < graf[nod].size(); ++i) {
        int vecin = graf[nod][i];
        if (!vizitat[vecin]) {
            DFS(vecin);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int componente = 0;
    for(int i=1; i<=n; ++i){
      if(vizitat[i] == 0) {
          DFS(i);
          componente++;
      }
    }
    cout<<componente;
    return 0;
}
