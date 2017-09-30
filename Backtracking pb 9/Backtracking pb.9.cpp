#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int n,v[100];

int valid(int k)
{
    int s1=0;
    float s2=0;
    for(int i=1;i<=k;++i)
        s1+=v[i];
    if(s1>n) return 0;
    for(int i=1;i<=k;++i)
        s2+=float(1)/float(v[i]);
    if(float(1)<=s2) return 0;
    if(v[k-1]>v[k]&&k>1) return 0;
    return 1;
}

int solutie(int k)
{
    int suma=0;
    for(int i=1;i<=k;++i)
        suma+=v[i];
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
    for(int i=1;i<=n;++i)
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
