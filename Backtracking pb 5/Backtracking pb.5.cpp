#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int n,c[6],v[100];

int valid(int k)
{
    if(k>n) return 0;
    if(v[k]==0&&k==1) return 0;
    return 1;
}

int solutie(int k)
{
    if(k==n-1) return 1;
    return 0;
}

void afisare()
{
    for(int i=1;i<=n;++i)
        g<<v[i];
    g<<'\n';
}

void BK(int k)
{
    for(int i=1;i<=5;++i)
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
    for(int i=1;i<=5;++i)
        f>>c[i];
    v[1]=c[1];
    v[n]=c[5];
    BK(2);
    return 0;
}
