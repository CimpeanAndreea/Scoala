#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int n,v[100],c[100],p;

int valid(int k)
{
    if(k>p) return 0;
    return 1;
}

int solutie(int k)
{
    if(n%2==0)
        if((k==p&&v[1]==c[1])||(k==p-1&&v[1]!=c[1])) return 1;
    else
        if(k==p) return 1;
    return 0;
}

void afisare()
{
    for(int i=1;i<=p;++i)
        g<<char(v[i]);
    g<<endl;
}

void BK(int k)
{
    for(int i=2;i<=n;++i)
    {
        v[k]=c[i];
        if(valid(k))
        {
            if(solutie(k)) afisare();
            else BK(k+2);
        }
    }
}

int main()
{
    f>>p>>n;
    for(int i=1;i<=n;++i)
    {
        char x;
        f>>x;
        c[i]=int(x);
    }
    if(p%2==0)
    {
        for(int i=1;i<=p;i+=2)
            v[i]=c[1];
        BK(2);
        for(int i=2;i<=p;i+=2)
            v[i]=c[1];
        BK(1);
    }
    else
    {
        for(int i=1;i<p;i+=2)
            v[i]=c[1];
        BK(2);
        for(int i=2;i<p;i+=2)
            v[i]=c[1];
        BK(1);
    }
    return 0;
}
