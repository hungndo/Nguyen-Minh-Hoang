#include<iostream>
#include<stdio.h>
using namespace std;
int array[300],n;
void init()
{
    cin>>n;
    for(int i=0;i<n;i++)
        array[i]=i+1;
}

void print()
{
    for(int i=0;i<n;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}
void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main (void)
{
    init();
    int k=n-2,t=n-1;
    while(k>-1)
    {
        print();
        while(array[k]>array[k+1])
            k--;
        if(k==-1)
            break;
        while(array[t]<array[k])
            t--;
        swap(array[k],array[t]);
        int a=k+1,b=n-1;
        while(a<b)
        {
            swap(array[a],array[b]);
            a++;b--;
        }
        k=n-2;t=n-1;
    }
}

