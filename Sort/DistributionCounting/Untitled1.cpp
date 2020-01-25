#include<stdio.h>
#include<iostream>
using namespace std;
#define M 300
int array[M],n,c[M]={0},x[M];
void init()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>array[i];
}

void print()
{
    for(int i=0;i<n;i++)
    {
        array[i]=x[i];
        cout<<array[i];
    }
}
void sort()
{
    for(int i=0;i<n;i++)
        c[array[i]]++;
    int t=0;
    for(int k=0;k<M;k++)
    {
        while(c[k]!=0&&t<n)
        {
            x[t]=k;
            t++;
            c[k]--;
        }
    }
    /*
    int outputindex=0;
    for (int j=0;j<M;j++)
    {
        while (c[j]--)
            array[outputindex++] = j;
    }
    */
}
int main(void)
{
    init();
    sort();
    print();

}
