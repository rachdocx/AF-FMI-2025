#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("apm2.in");
ofstream fout("apm2.out");

vector<int> vectorTati;
vector<int> vectorInaltimi;

int reprezentant(int x){
    if(vectorTati[x] == 0){
        return x;
    }
    else{
        vectorTati[x] = reprezentant(vectorTati[x]);
        return vectorTati[x];
    }
}

void reunire(int x, int y){
    x = reprezentant(x);
    y = reprezentant(y);
    if(vectorInaltimi[x] < vectorInaltimi[y]){
        vectorTati[x] = y;
    }
    else if(vectorInaltimi[x] == vectorInaltimi[y]){
        vectorTati[x] = y;
        vectorInaltimi[y]++;
    }
    else{
        vectorTati[y] = x;
    }
}

vector<vector<int>> kruskal(vector<vector<int>> m, int nrNoduri){
    fill(vectorTati.begin(), vectorTati.end(), 0);
    fill(vectorInaltimi.begin(), vectorInaltimi.end(), 0);

    sort(m.begin(), m.end());
    vector<vector<int>> rezultat;

    for(auto muchie : m){
        if(reprezentant(muchie[1]) != reprezentant(muchie[2])){
            reunire(muchie[1], muchie[2]);
            rezultat.push_back(muchie);
            if((int)rezultat.size() >= nrNoduri - 1){
                break;
            }
        }
    }
    return rezultat;
}

int dfs(int nod, int destinatie, int parinte, vector<vector<pair<int, int>>>& graf){
    if(nod == destinatie){
        return 0;
    }

    for(auto& vecin : graf[nod]){
        int nodVecin = vecin.first;
        int cost = vecin.second;

        if(nodVecin != parinte){
            int maxPeDrum = dfs(nodVecin, destinatie, nod, graf);
            if(maxPeDrum != -1){
                return max(cost, maxPeDrum);
            }
        }
    }

    return -1;
}

int main()
{
    int N, M, Q;
    fin >> N >> M >> Q;

    vectorTati.assign(N + 1, 0);
    vectorInaltimi.assign(N + 1, 0);

    vector<vector<int>> muchii;

    for(int i = 0; i < M; i++){
        int x, y, cost;
        fin >> x >> y >> cost;
        muchii.push_back({cost, x, y});
    }

    vector<vector<int>> apm = kruskal(muchii, N);

    vector<vector<pair<int, int>>> graf(N + 1);
    for(auto& muchie : apm){
        int cost = muchie[0];
        int x = muchie[1];
        int y = muchie[2];
        graf[x].push_back({y, cost});
        graf[y].push_back({x, cost});
    }

    for(int i = 0; i < Q; i++){
        int a, b;
        fin >> a >> b;

        int maxCost = dfs(a, b, -1, graf);
        fout << maxCost - 1 << '\n';
    }

    return 0;
}