#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream f("listavecini.in");
ofstream g("listavecini.out");
int n,a[101][101],b[101][101],x,y;
int main()
{
    f>>n;
    while(f>>x>>y)
    {
        if(!a[x][y])
        {
            b[x][0]++;
            b[x][b[x][0]]=y;
            b[y][0]++;
            b[y][b[y][0]]=x;
        }
        a[x][y]=a[y][x]=1;
    }
    for(int i=1;i<=n;++i)
        sort(b[i]+1,b[i]+b[i][0]+1);
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=b[i][0];++j)
            g<<b[i][j]<<' ';
        g<<endl;
    }
    return 0;
}