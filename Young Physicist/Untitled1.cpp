#include<iostream>
#include<stdio.h>
using namespace std;
int a=0,b=0,c=0,n,x;
int main (void)
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a+=x;
        cin>>x;
        b+=x;
        cin>>x;
        c+=x;
    }
    if(a==0&&b==0&&c==0)
        cout<<"YES";
    else
        cout<<"NO";
}
