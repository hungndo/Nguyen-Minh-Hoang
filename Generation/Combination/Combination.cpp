#include<iostream>
#include<stdio.h>
using namespace std;
int array[300],n,k;
void init()
{
    cin>>n>>k;
    for(int i=0;i<k;i++)
        array[i]=i+1;
}

void print()
{
    for(int i=0;i<k;i++)
        cout<<array[i];
    cout<<endl;
}

int main(void)
{
    init();
    int key=k-1;
    while(true)
    {
        print();
        while(array[key]==n-k+key+1)
            key--;
        if (key<0)
            break;
        array[key]++;
        for(int i=key+1;i<k;i++)
            array[i]=array[i-1]+1;
        key=k-1;
    }
}
