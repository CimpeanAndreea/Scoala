#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int v[10];

int valid(int k)
{
    for(int i=1;i<k;++i)
        if(v[i]==v[k]) return 0;
    if(k>5) return 0;
    if(k==4)
    {
        for(int i=1;i<k;++i)
            if(v[i]==1||v[i]==2) return 0;
    }
    return 1;
}

int solutie(int k)
{
    if(k==5) return 1;
    return 0;
}

void afisare()
{
    for(int i=1;i<=5;++i)
        cout<<char(64+v[i])<<' ';
    cout<<endl;
}

void BK(int k)
{
    for(int i=1;i<=5;++i)
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
    BK(1);
    return 0;
}
