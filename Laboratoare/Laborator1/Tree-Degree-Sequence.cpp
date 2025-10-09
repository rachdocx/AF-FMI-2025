#include <iostream>
#include <vector>
using namespace std;

int g[101][101];

int main() {
    int n, x;
    cin >> n;

    vector<pair<int,int>> d1;
    vector<pair<int,int>> dm;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        pair<int,int> temp = {x, i};
        if (x == 1)
            d1.push_back(temp);
        else
            dm.push_back(temp);
    }
    for (int i = 0; i+1 < dm.size(); ++i) {
        g[dm[i].second][dm[i+1].second] = g[dm[i+1].second][dm[i].second] = 1;
        dm[i].first--;
        dm[i+1].first--;
    }
    int j = 0;
    for (int i = 0; i < d1.size(); ++i) {
        while (j < dm.size() && dm[j].first == 0)
            j++;
        if (j == dm.size())
            break;
        g[d1[i].second][dm[j].second] = g[dm[j].second][d1[i].second] = 1;
        dm[j].first--;
    }
    for (int i = 0; i < n; ++i) {
        for (int k = i; k < n; ++k)
            if (g[i][k] == 1 && g[k][i] == 1)
                cout<<i+1<<" "<<k+1<<"\n";
    }
    return 0;
}
