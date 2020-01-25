#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
int n, a[100000],cost[100000],minn=1000;
void init()
{
    ifstream doc;
    doc.open("doc.txt");
    int key=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>cost[i];
        if (cost[i]<=cost[key])
            key=i;
        else
        {
            a[key]=a[key]+a[i];
            a[i]=0;
        }
    }
    doc.close();
}

void buy()
{
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+cost[i]*a[i];
    }
    cout<<sum;
}
int main(void)
{
    init();
    buy();
}
