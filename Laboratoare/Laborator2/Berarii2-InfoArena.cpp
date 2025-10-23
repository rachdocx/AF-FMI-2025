#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream in("berarii2.in");
    ofstream out("berarii2.out");

    int N, M, P;
    in >> N >> M >> P;

    vector<vector<int>> graf_invers(N + 1);
    for (int i = 0; i < M; i++) {
        int X, Y;
        in >> X >> Y;
        graf_invers[Y].push_back(X);
    }

    vector<int> berarii(P);
    for (int i = 0; i < P; i++)
        in >> berarii[i];

    vector<bool> viz(N + 1, false);
    queue<int> Q;

    for (int b : berarii) {
        viz[b] = true;
        Q.push(b);
    }

    while (!Q.empty()) {
        int nod = Q.front();
        Q.pop();

        for (int vecin : graf_invers[nod]) {
            if (!viz[vecin]) {
                viz[vecin] = true;
                Q.push(vecin);
            }
        }
    }

    vector<int> rele;
    for (int i = 1; i <= N; i++) {
        if (!viz[i])
            rele.push_back(i);
    }

    sort(rele.begin(), rele.end());
    out << rele.size() << "\n";
    for (int x : rele)
        out << x << "\n";

    return 0;
}
