#include<iostream>
#include<stdio.h>
using namespace std;
#define max 300
int array[max],n,first,last;
bool empty=false;
typedef struct
{
    int L,H;
}nhom;
nhom O,queue[10000000];
void push(nhom V)
{
    if(last==9999999)
        cout<<"full";
    else
    {
    last++;
    queue[last]=V;
    }
}
void pop()
{
    if(first>last)
    {
       empty=true;
    }
    else
    {
    first++;
    }
}
void swap(int *a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void init()
{
    cin>>n;
    last=-1;first=-1;
    for(int i=0;i<n;i++)
        cin>>array[i];
}
void print()
{
    for(int i=0;i<n;i++)
        cout<<array[i]<<"  ";
}
void quicksort()
{
    O.L=0;
    O.H=n-1;
    push(O);
    do
    {
        pop();
        int i=queue[first].L,j=queue[first].H,key =array[(i+j)/2];
        ////
        while(i<=j)
        {
            while(array[i]<key)
                i++;
            while(array[j]>key)
                j--;
            if(i<=j)
            {
                swap(array[i],array[j]);
                i++;j--;
            }
        }
        ////
        if(queue[first].L<j)
        {O.H=j;
        push(O);}
        //
        if(i<queue[first].H)
        {O.L=i;O.H=queue[first].H;
        push(O);}
        ////
    }while(first<last);
}
int main(void)
{
    init();
    quicksort();
    print();
}
