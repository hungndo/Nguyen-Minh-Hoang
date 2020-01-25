#include<iostream>
#include<stdio.h>
using namespace std;
int x,X,n;
bool pass[300]={false};
void init()
{
    cin>>n;
    for(int t=0;t<2;t++)
    {
    cin>>X;
    for(int i=0;i<X;i++)
        {
            cin>>x;
            if(pass[x-1]==false)
            {
                pass[x-1]=true;
                n--;
            }
        }
    }
}
int main(void)
{
    init();
    if(n==0)
        cout<<"I become the guy.";
    else
        cout<<"Oh, my keyboard!";
}
