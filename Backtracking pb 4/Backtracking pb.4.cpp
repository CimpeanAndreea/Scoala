#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int n,v[6];

int valid(int k)
{
    if(k>n) return 0;
    if(k>1&&v[k]<=v[k-1]) return 0;
    if(v[1]==0&&n>1) return 0;
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
        g<<v[i]<<' ';
    g<<'\n';
}

void BK(int k)
{
    for(int i=0;i<=8;i+=2)
    {
        v[k]=i;
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
    BK(1);
    return 0;
}
