#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool havelHakimi(vector<int> d) {
    while (true) {
        sort(d.begin(), d.end(), greater<int>());
        if (d[0] == 0)
            return true;
        int k = d[0];
        d.erase(d.begin());
        if (k > (int)d.size())
            return false;
        for (int i = 0; i < k; ++i) {
            d[i]--;
            if (d[i] < 0)
                return false;
        }
    }
}

int main() {
    int n, m;
    cin >> m;
    for (int j=0; j<m; ++j) {
        cin >> n;
        vector<int> d(n);
        for (int i = 0; i < n; ++i)
            cin >> d[i];
        if (havelHakimi(d))
            cout << "POSSIBLE\n";
        else
            cout<< "IMPOSSIBLE\n";
    }

    return 0;
}
