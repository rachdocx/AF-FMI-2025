 #include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream fin("ctc.in");
ofstream fout("ctc.out");

vector<vector<int>> grInitial;
vector<vector<int>> grTranspus;
vector<int> viz;
stack<int> st;
void dfs(int vf) {
    viz[vf] = 1;
    for (int x :grInitial[vf]) {
        if (!viz[x]) {
            dfs(x);
        }
    }
    st.push(vf);
}

void dfsTranspus(int vf) {
    viz[vf] = 1;
    fout << vf << " ";
    for (int x :grTranspus[vf]) {
        if (!viz[x]) {
            dfsTranspus(x);
        }
    }
}
int main() {
    int n, m;
    fin >> n >> m;
    grInitial.resize(n+1);
    grTranspus.resize(n+1);
    viz.assign(n+1, 0);
    for (int i = 1; i<=m; ++i) {
        int x,y;
        fin >> x >> y;

        grInitial[x].push_back(y);
        grTranspus[y].push_back(x);
    }

    for (int i = 1; i <= n;  ++i) {
        if (!viz[i]) {
            dfs(i);
        }
    }
    viz.assign(n+1, 0);
    while (!st.empty()) {
        int vf = st.top();
        st.pop();
        if (!viz[vf]) {
            dfsTranspus(vf);
            fout << endl;
        }
    }
    return 0;
}
