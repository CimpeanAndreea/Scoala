#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int n,v[100];

int valid(int k)
{
    if(k>n) return 0;
    return 1;
}

int solutie(int k)
{
    if(k==n&&v[n]==8||v[n]==9) return 1;
    return 0;
}

void afisare()
{
    for(int i=1;i<=n;++i)
        g<<v[i];
    g<<endl;
}

void BK(int k)
{
    v[k]=v[k-1]+2;
    if(valid(k))
    {
        if(solutie(k)) afisare();
        else BK(k+1);
    }
    v[k]=v[k-1]-2;
    if(valid(k))
    {
        if(solutie(k)) afisare();
        else BK(k+1);
    }
    v[k]=v[k-1]+3;
    if(valid(k))
    {
        if(solutie(k)) afisare();
        else BK(k+1);
    }
    v[k]=v[k-1]-3;
    if(valid(k))
    {
        if(solutie(k)) afisare();
        else BK(k+1);
    }
}

int main()
{
    f>>n;
    v[1]=1;
    BK(2);
    v[1]=2;
    BK(2);
    return 0;
}
