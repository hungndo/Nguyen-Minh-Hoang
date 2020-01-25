#include<iostream>
#include<stdio.h>
using namespace std;
#define max 300
int array[max],n,c[max],x[max];

void init()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
}
void print()
{
    for(int i=0;i<n;i++)
        cout<<array[i];
}
void sort()
{
    for(int i=0;i<max;i++)
        c[i]=0;
    for(int i=0;i<n;i++)
        c[array[i]]++;
        ////
    for(int i=1;i<max;i++)
        {
            c[i]=c[i-1]+c[i];
        }
    int v;
    for(int i=n-1;i>-1;i--)
    {
        v=array[i];
        x[c[v]-1]=array[i];c[v]--;
    }
    for(int i=0;i<n;i++)
        array[i]=x[i];
}
int main (void)
{
    init();
    sort();
    print();
}
