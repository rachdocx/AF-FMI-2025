#include <iostream>
#include <fstream>
using namespace std;
/*
În Regatul Luminii, există n orașe conectate printr-o rețea de drumuri bidirecționale. Regele Solaris a primit q cereri (numerotate de la 1 la ) pentru a adăuga noi drumuri între perechi de orașe . Totuși, fiecare drum construit consumă resurse importante, așa că regele l-a rugat pe Oracolul Drumurilor să analizeze cererile.
Pentru fiecare cerere, Oracolul trebuie să răspundă:
1 – dacă noul drum reduce drumul cel mai scurt dintre Orașul 1 și Orașul .
0 – dacă drumul nu aduce nicio îmbunătățire.
După evaluare, regele dorește să știe pentru câte cereri răspunsul este 1 și indicele acestor cereri în ordine crescătoare.
Input Format
Programul citește de la tastatură de pe prima linie două numere întregi  (numărul de orașe) și  (numărul de drumuri). Următoarele  linii descriu drumurile existente prin perechi de numere întregi  indicând că există un drum între orașele  și . Apoi se citeșțe  (numărul de cereri). Următoarele  linii conțin întrebările de forma , unde  și  reprezintă orașele între care se propune construirea unui nou drum.
Constraints
In graful inițial există cel puțin un lanț de la orașul 1 la orașul .
In graful inițial există cel mult o muchie între oricare două orașe.
Se garantează că drumurile din cele  cereri nu există în graful inițial.
Output Format
Programul afișează pe ecran pe prima linie numărul de cereri pentru care răspunsul este 1, iar pe a doua linie indicii cererilor pentru care răspunsul este 1 în ordine crescătaore separați printr-un spațiu.
 */
vector<vector<int>> graf;
vector<int> viz;
vector<pair<int, int>> cereri;
int main() {
    int n,m,c;
    cin >> n >> m;
    graf.resize(n+1);
    viz.assign(n+1, 0);
    for (int i=0; i<m; ++i) {
        int x,y;
        cin >> x >> y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
    cin >> c;


    return 0;
}
