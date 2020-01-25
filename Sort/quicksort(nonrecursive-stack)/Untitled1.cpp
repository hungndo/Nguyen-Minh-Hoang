#include<iostream>
#include<stdio.h>
using namespace std;
#define max 300
int array[max],n,k;
bool empty;
typedef struct
{
    int L;
    int H;
}nhom;
nhom stack[max],O;
void push(nhom V)
{
    if(k==-1)
        empty=false;
    if (k==max-1)
    cout<<"fuck";
    k++;
    stack[k]=V;
}
nhom pop()
{
    if(k==0)
        empty=true;
    k--;
    return stack[k+1];
}
void init()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>array[i];
    k=-1;
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
void quicksort()
{
    O.L=0;O.H=n-1;
    push(O);
    while(!empty)
    {
        O=pop();
        int i=O.L,j=O.H, key=array[(i+j)/2],l=i,h=j;
        while(i<=j)
        {
            while(array[i]<key)
                i++;
            while(array[j]>key)
                j--;
            if(i<j)
            {
                swap(array[i],array[j]);
                i++;j--;
            }
        }
        if(l<j)
        {
            O.L=l;O.H=j;push(O);
        }
        if(i<h)
        {
            O.L=i;O.H=h;push(O);
        }
    }
}
int main(void)
{
    init();
    quicksort();
    print();
}
