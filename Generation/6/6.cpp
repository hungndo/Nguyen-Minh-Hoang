#include<iostream>
#include<stdio.h>
using namespace std;
int male[300],female[300],n;
void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void init()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        male[i]=i+1;
        female[i]=i+1;
    }
}
void print()
{
    for(int i=0;i<n;i++)
        cout<<" - male "<< male[i]<<" - female "<< female[i];
    cout<<endl;
}
void permutatefemale()
{
    int key=n-2,smallestgreaternumber=n-1;
    while(true)
    {
        print();
        while(female[key]>female[key+1])
            key--;
        if(key==-1)
            break;
        while(female[smallestgreaternumber]<female[key])
            smallestgreaternumber--;
        swap(female[key],female[smallestgreaternumber]);
        int a=key+1,b=n-1;
        while(a<b)
        {
            swap(female[a],female[b]);
            a++;b--;
        }
        key=n-2;smallestgreaternumber=n-1;
    }
    int a=0,b=n-1;
    while(a<b)
        {swap(female[a],female[b]);
        a++;
        b--;}
}
int main(void)
{
    init();
    int key=n-2,smallestgreaternumber=n-1;
    while(true)
    {
        permutatefemale();
        while(male[key]>male[key+1])
            key--;
        if(key<1)
            break;
        while(male[smallestgreaternumber]<male[key])
            smallestgreaternumber--;
        swap(male[key],male[smallestgreaternumber]);
        int a=key+1,b=n-1;
        while(a<b)
        {
            swap(male[a],male[b]);
            a++;b--;
        }
        key=n-2;smallestgreaternumber=n-1;
    }
}
