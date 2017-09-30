///Backtracking pb 77
#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int n,nr,v[100],suma,m[100];

int valid(int k)
{
    if(v[k-1]>v[k]) return 0;
    if(suma>n) return 0;
    return 1;
}

int solutie(int k)
{
    if(suma==n) return 1;
    return 0;
}

void afisare(int k)
{
    for(int i=1;i<=k;++i)
        cout<<v[i]<<' ';
    cout<<endl;
}

void BK(int k)
{
    for(int i=1;i<=nr;++i)
    {
        v[k]=m[i];
        suma+=v[k];
        if(valid(k))
        {
            if(solutie(k)) afisare(k);
            BK(k+1);
        }
        suma-=v[k];
    }
}

int main()
{
    int i=0;
    f>>n>>nr;
    while(nr!=0)
    {
        i++;
        m[i]=nr%10;
        nr/=10;
    }
    nr=i;
    BK(1);
    return 0;
}
