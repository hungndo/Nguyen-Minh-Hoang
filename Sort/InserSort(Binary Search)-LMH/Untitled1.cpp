#include<iostream>
#include<stdio.h>
using namespace std;
#define max 300
int n,array[max];
void init ()
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
void insertsort()
{
    for(int i=1;i<n;i++)
    {
        int l=0,h=i-1,k,tmp=array[i];
        while(l<=h)
        {
            k=(l+h)/2;
            if (tmp<array[k])
                h=k-1;
            else l=k+1;
        }
        for(int j=i;j>l;j--)
            array[j]=array[j-1];
        array[l]=tmp;
    }
}
int main(void)
{
    init();
    insertsort();
    print();
}
