#include<iostream>
#include<stdio.h>
#define max 300
using namespace std;
int array[max],n;
void init()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>array[i];
}
void print ()
{
    for(int i=0;i<n;i++)
        cout<<array[i];
}
void shellsort()
{
    int h=(n-1)/2;
    while (h!=0)
    {
        for(int i=h+1;i<n;i++)
        {
            int j=i,tmp=array[j];
            while(tmp<array[j-h]&&j-h>=0)
            {
                array[j]=array[j-h];
                j=j-h;
            }
            array[j]=tmp;
        }
        h=h/2;
    }
}
int main(void)
{
    init();
    shellsort();
    print();
}
