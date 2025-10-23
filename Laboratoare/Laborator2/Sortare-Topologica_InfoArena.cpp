 #include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream fin("sort.in");
ofstream fout("sort.out");

vector<vector<int>> grInitial;

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

int main() {
    int n, m;
    fin >> n >> m;
    grInitial.resize(n+1);
    viz.assign(n+1, 0);
    for (int i = 1; i<=m; ++i) {
        int x,y;
        fin >> x >> y;

        grInitial[x].push_back(y);
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
        fout << vf <<" ";
    }
    return 0;
}
