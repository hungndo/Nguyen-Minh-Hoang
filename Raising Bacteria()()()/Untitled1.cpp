#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int main (void)
{
    int bacteria=0;
    cin>>n;
    while(n>0)
    {
        if(n%2!=0)
        {
            bacteria++;
            n=n/2;
        }
        else
        n=n/2;
    }
    cout<<bacteria;
}
