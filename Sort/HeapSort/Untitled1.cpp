#include<iostream>
#include<stdio.h>
using namespace std;
#define max 300
int array[max],n;
void init()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>array[i];
}
void print()
{
    for(int i=0;i<n;i++)
        cout<<array[i];
}
void adjust(int root,int endnode)
{
    int c,tmp=array[root];
    while(root*2+1<=endnode)
    {
        c=root*2+1;
        if(c<endnode&&array[c]<array[c+1])
            c++;
        if(array[c]<=tmp)
            break;
        array[root]=array[c];root=c;
    }
    array[root]=tmp;
}
void swap(int *a,int *b)
{
    int tmp= *a;
    *a=*b;
    *b=tmp;
}
void heapsort()
{

    for(int i=(n-2)/2;i>-1;i--)
        adjust(i,n-1);
    for(int i=n-1;i>0;i--)
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
