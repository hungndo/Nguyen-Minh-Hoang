#include<iostream>
#include<stdio.h>
using namespace std;
int main (void)
{
    int n,x,c=0,k=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<3;j++)
           {
            cin>>x;
            if(x==1)
            {
                k++;
                if(k==2)
                c++;
            }
           }
    }
    cout<<c;
}
