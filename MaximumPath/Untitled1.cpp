#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
int array[300][300],tmp,n,maxx=0,r[]={1,-1,0,0},c[]={0,0,1,-1};
bool crit[300][300];
void init()
{
    ifstream doc;
    doc.open("input.txt");
    doc>>n;
    for(int i=0;i<3;i++)
        for(int j=0;j<n;j++)
        {
            crit[i][j]=true;
            doc>>array[i][j];
        }
    doc.close();
}
void path(int h,int cot,int k)
{
    if(crit[h][cot]==false)


        return;
    else if(cot==n-1&&h==2)
    {
        if(k>maxx)
        maxx=k;
    }
    else
    {
        for(int i=0;i<4;i++)
        if(h+r[i]<3&&h+r[i]>-1&&cot+c[i]<n&&cot+c[i]>-1)
            {
                crit[h][cot]=false;
                path(h+r[i],cot+c[i],k+array[h][cot]);
                crit[h][cot]=true;
            }
    }
}
int main(void)
{
    init();
    path(0,0,array[0][0]);
    cout<<maxx;
}

