#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int v[10],c[10];

int valid(int k)
{
    if(k>3) return 0;
    if(v[1]==0) return 0;
    for(int i=1;i<k;++i)
        if(v[k]==v[i]) return 0;
    if(v[3]==3) g<<"da"<<endl;
    return 1;
}

int solutie(int k)
{
    if(k==3&&v[4]==4&&(v[1]==2||v[2]==2||v[3]==2)) return 1;
    return 0;
}

void afisare()
{
    for(int i=1;i<=4;++i)
        g<<v[i];
    g<<endl;
}

void BK(int k)
{
    for(int i=1;i<=5;++i)
    {
        v[k]=c[i];
        g<<"pe pozitia "<<k<<' '<<v[k]<<endl;
        if(valid(k))
        {
            if(solutie(k)) afisare();
            else BK(k+1);
        }
    }
}

int main()
{
    c[1]=0;
    c[2]=1;
    c[3]=2;
    c[4]=3;
    c[5]=5;
    v[4]=4;
    BK(1);
    return 0;
}
