#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int n, x;
int main() {
    cin >> n;
    vector<vector<int>> list(n+1);
    for(int i=1 ;i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            cin >> x;
            if (x == 1) {
                list[i].push_back(j);
            }
        }
    }
    for (auto i : list) {
        for (auto j : i)
            cout<< j<<" ";
        cout<<'\n';
    }
    return 0;
}
