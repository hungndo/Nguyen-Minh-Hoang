#include<iostream>
using namespace std;
#define QUEUE_MAX 1000
int Last=0, First=-1;
void push(int array[],int value)
{
    if(Last!=First-1)
    {
        array[Last]=value;
        Last=(Last+1)%QUEUE_MAX;
    }
    else
    cout<<"Queue is full!";
}
int pull(int array[])
{
    if(First!=Last-1)
    {
       First=(First+1)%QUEUE_MAX;
       return array[First];
    }
    else
    {
        cout<<"Queue is empty!";
        return 0;
    }
}
int main (void)
{
    int sample[10];
    push(sample,5);
    cout<<sample[0];
    cout<<pull(sample);
}
