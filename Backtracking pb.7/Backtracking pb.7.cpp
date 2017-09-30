#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int n,c[4],v[100];

int valid(int k)
{
    if(k>n) return 0;
    if(k==1&&v[k]==0) return 0;
    return 1;
}

int formare_nr()
{
    int nr=0;
    for(int i=1;i<=n;++i)
        nr=nr*10+v[i];
    return nr;
}

int prim(int k)
{
    for(int d=2;d<=sqrt(k);++d)
        if(k%d==0) return 0;
    return 1;
}

int solutie(int k)
{
    if(k==n&&prim(formare_nr())) return 1;
    return 0;
}

void afisare()
{
    for(int i=1;i<=n;++i)
        cout<<v[i];
    cout<<endl;
}

void BK(int k)
{
    for(int i=1;i<=3;++i)
    {
        v[k]=c[i];
        if(valid(k))
        {
            if(solutie(k)) afisare();
            else BK(k+1);
        }
    }
}

int main()
{
    f>>n;
    for(int i=1;i<=3;++i)
        f>>c[i];
    BK(1);
    return 0;
}
