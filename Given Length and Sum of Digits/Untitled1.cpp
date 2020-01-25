#include<iostream>
#include<stdio.h>
using namespace std;
int n,l;
int main (void)
{
    cin>>n>>l;
    if((l==0&&n>1)||l>9*n)
        cout<<"-1 -1";

    else
    {
    int x[n],y[n];
    int t=l;
    for(int i=n-1;i>0;i--)
        {
            if(t==1)
                x[i]=0;
            else if(t<=9)
                {
                    x[i]=t-1;t=1;
                }
            else
                {x[i]=9;t=t-9;}

        }
    x[0]=t;
    for(int i=0;i<n-1;i++)
        {
            if(l<=9)
                {
                    y[i]=l;l=0;
                }
            else
                {y[i]=9;l=l-9;}
        }
    y[n-1]=l;
    for(int i=0;i<n;i++)
        cout<<x[i];
    cout<<" ";
    for(int i=0;i<n;i++)
        cout<<y[i];
    }

}
