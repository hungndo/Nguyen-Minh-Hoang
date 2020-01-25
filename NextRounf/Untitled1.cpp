#include<stdio.h>
#include<iostream>
using namespace std;
int main (void)
{
    int k,n;
        cin>>n;
    int a[n+1],t=n;
        a[n]=0;
        cin>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=n-1;i>-1;i--)
    {
            if (a[i]>0&&a[i]>a[t])
            {
                t=i;
                if(a[t]>=a[k-1])
                    break;
            }
    }
    if(t==n)
        cout<<0;
    else
    cout<<t+1;
}
