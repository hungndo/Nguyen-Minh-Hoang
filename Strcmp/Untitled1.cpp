#include<iostream>
#include<stdio.h>
using namespace std;
int strcmp(string a,string b)
{
    int i=0;
    do
    {
        if(a[i]>=97)
            a[i]-=32;
        if(b[i]>=97)
            b[i]-=32;
        if(a[i]>b[i])
            return 1;
        else if (a[i]<b[i])
            return -1;
        else
            i++;
    }while(a[i]!='\0'||b[i]!='\0');
    return 0;
}

int main(void)
{
    string c,d;
    cin>>c>>d;
    cout<<strcmp(c,d);
}
