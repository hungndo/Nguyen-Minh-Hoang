#include<iostream>
#include<stdio.h>
using namespace std;
int array[300],n;
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
void insertsort()
{
    for(int i=1;i<n;i++)
    {
        int l=0,h=i-1,k=(l+h)/2,tmp=array[i];
        while(tmp<array[k-1]||tmp>array[k+1])
        {

            if (tmp<array[k])
            h=k-1;
            else if (tmp>array[k])
            l=k+1;
            else
            break;
            k=(l+h)/2;
        }
        if (tmp<array[k])
        {for(int t=i-1;t>k-1;t--)
            {
                array[t+1]=array[t];
            }
        array[k]=tmp;
        }
        else
        {
            for(int t=i-1;t>k;t--)
            {
                array[t+1]=array[t];
            }
        array[k+1]=tmp;
        }
    }
}
int main(void)
{
    init();
    insertsort();
    print();
}
