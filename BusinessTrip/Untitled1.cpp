#include<iostream>
#include<stdio.h>
using namespace std;
int month[12],n;
void swap (int*a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void sort(int L,int H)
{
    int i=L,j=H,key=month[(i+j)/2];
    while(i<=j)
    {
        while(month[i]>key)
            i++;
        while(month[j]<key)
            j--;
        if(i<=j)
        {
            swap(month[i],month[j]);
            i++;j--;
        }
    }
    if(L<j)
    sort(L,j);
    if(i<H)
    sort(i,H);
}

int main(void)
{
    cin>>n;
    for(int i=0;i<12;i++)
        cin>>month[i];
    sort(0,11);
    int c=0;
    if(n!=0)
    {
    for(int i=0;i<12;i++)
    {
        c+=month[i];
        if(c>=n)
        {
            n=i+1;
            break;
        }
    }
    if(c<n)
        cout<<-1;
    else
    cout<<n;
    }
    else
        cout<<n;
}
