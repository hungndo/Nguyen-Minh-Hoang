#include<stdio.h>
bool checkprime(int a)
{
    for(int i=3;i<sqrt(a);i++)
        if(a%i==0)
            return false;
}
int GCD(int a, int b)
{
    while(a!=b)
        {
            if(a>b)
                a=a%b;
            else
                b=b%a;
        }
    return a;
}
