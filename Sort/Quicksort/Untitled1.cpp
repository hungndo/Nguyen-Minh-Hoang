#include<iostream>
#include<stdio.h>
using namespace std;
int array[300],n;
void init()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>> array[i];
}
void print()
{
    for(int i=0;i<n;i++)
        cout<<array[i];
}
void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void adjust(int root,int endnode)
{
    int c,key=array[root];
    while(root*2+1<endnode)
    {
        c=root*2+1;
        if(array[c]<array[c+1]&&(c+1)<=endnode)
        c++;
        if(array[c]<=key)
        break;
        array[root]=array[c];root=c;
    }
    array[root]=key;
}
void heapsort()
{
    for(int i =(n-1)/2;i>-1;i--)
        adjust(i,n);
    for(int i =n-1;i>0;i--)
    {
        swap(array[0],array[i]);
        adjust(0,i-1);
    }
}
int main(void)
{
    init();
    heapsort();
    print();
}
