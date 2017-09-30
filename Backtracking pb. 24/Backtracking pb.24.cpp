#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int n,v[5],perimetru_partial;

int valid(int k)
{
    if(k>3) return 0;
    if(perimetru_partial>n) return 0;
    return 1;
}

int solutie(int k)
{
    if(k!=3) return 0;
    if(perimetru_partial!=n) return 0;
    if(v[1]+v[2]<v[3]) return 0;
    if(v[2]+v[3]<v[1]) return 0;
    if(v[1]+v[3]<v[2]) return 0;
    return 1;
}

void afisare()
{
    for(int i=1;i<=3;++i)
        g<<v[i]<<' ';
    g<<endl;
}

void BK(int k)
{
    for(int i=v[k-1];i<=n-perimetru_partial;++i)
    {
        v[k]=i;
        perimetru_partial+=v[k];
        if(valid(k))
        {
            if(solutie(k)) afisare();
            else BK(k+1);
        }
        perimetru_partial-=v[k];
    }
}

int main()
{
    f>>n;
    v[0]=1;
    BK(1);
    return 0;
}
