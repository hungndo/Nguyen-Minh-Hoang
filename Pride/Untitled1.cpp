#include<stdio.h>
#include "Untitled2.h"
using namespace std;
int array[300],n,k;
init()
{
    cin>>n>>k;
}
int main void()
{
    init();
    int coun=0;
    bool correct=false;
    while(correct)
    {
        for(int i=0;i<n-1;i++)
        {
            if(GCD(array[i],array[i+1])==1)
                {   coun=coun+n-1;correct==false;
                break;}
        }
    }
}
