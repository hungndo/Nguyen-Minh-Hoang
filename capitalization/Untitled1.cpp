#include<iostream>
#include<stdio.h>
using namespace std;
int main (void)
{
    string a;cin>>a;
    if(a[0]>=97)
        a[0]-=32;
    cout<<a;
}
