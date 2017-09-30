#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int n,c[5],v[100];

int valid(int k)
{
    if(k>n) return 0;
    if(abs(v[k-1]-v[k])!=2&&abs(v[k-1]-v[k])!=3&&k>1) return 0;
    if(k==1&&v[k]==0) return 0;
    return 1;
}

int solutie(int k)
{
    if(k==n) return 1;
    return 0;
}

void afisare(int k)
{
    for(int i=1;i<=k;++i)
        g<<v[i];
    g<<'\n';
}

void BK(int k)
{
    for(int i=1;i<=4;++i)
    {
        v[k]=c[i];
        if(valid(k))
        {
            if(solutie(k)) afisare(k);
            else BK(k+1);
        }
    }
}

int main()
{
    f>>n;
    for(int i=1;i<=4;++i)
        f>>c[i];
    BK(1);
    return 0;
}
