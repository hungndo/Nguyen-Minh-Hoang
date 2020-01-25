#include<iostream>
using namespace std;
#define max 1000
int Last=0;
void push (int array[],int value)
{
    if(Last<1000)
    {
        array[Last]= value;
        Last++;
    }
    else
    {
        cout<<"Stack is full.";
    }
}
int pull(int array[])
{
    if(Last>-1)
    {
        Last--;
        return array[Last];
    }
    else
    {
        cout<<"Stack is empty.";
    }
}
int main (void)
{
    int test[10];
    push(test,3);
    cout<<test[0];
    int a=pull(test);
    cout<<a;
}
