#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int n,p,v[100];

int valid(int k)
{
    if(k>n) return 0;
    return 1;
}

int formare_nr()
{
    int nr=0;
    for(int i=1;i<=n;++i)
        nr=nr*10+v[i];
    return nr;
}

int solutie(int k)
{
    int prod=1;
    for(int i=1;i<=k;++i)
        prod*=v[i];
    if(prod*p==formare_nr()&&k==n) return 1;
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
    for(int i=1;i<=9;++i)
    {
        v[k]=i;
        if(valid(k))
        {
            if(solutie(k)) afisare();
            else BK(k+1);
        }
    }
}

int main()
{
    f>>n>>p;
    BK(1);
    return 0;
}
