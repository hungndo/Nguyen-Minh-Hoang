#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
string array[300];
int n;
int strcmp(string a, string b)
{
    int k=0;
    do
    {
        if(a[k]>b[k])
            return 1;
        else if(a[k]<b[k])
            return -1;
        k++;
    }while(a[k]!='\0'||b[k]!='\0');
}
void init()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>array[i];
}
void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void quicksort(int l,int h)
{
    if(l>=h)
        return;
    else
    {
        int i=l,j=h;string key=array[(i+j)/2];
        while(i<=j)
        {
            while(strcmp(array[i],key)==-1)
                i++;
            while(strcmp(array[j],key)==1)
                j--;
            if(i<=j)
            {
                swap(array[i],array[j]);
                i++;j--;
            }
        }
        quicksort(l,j);quicksort(i,h);
    }
}
void print()
{
    for(int i=0;i<n;i++)
        cout<<i+1<<"."<<array[i]<<endl;
}
int main(void)
{
    init();
    quicksort(0,n-1);
    print();
}
