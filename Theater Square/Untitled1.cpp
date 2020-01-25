#include<iostream>
#include<stdio.h>
using namespace std;
int main(void)
{
    long long n,m,a;
    cin>>n>>m>>a;
    cout<<((n-1)/a+1)*((m-1)/a+1);
}
