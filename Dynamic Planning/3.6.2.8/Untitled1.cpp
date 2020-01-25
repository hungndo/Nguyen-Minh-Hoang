#include<iostream>
using namespace std;
int main (void)
{
    int n,p;
    cin>>n>>p;
    //set base
    int A[n+1][n/2+1];
    for(int i=1;i<n/2+1;i++)
            A[1][i]=0;
    A[1][0]=1;
    for(int i=0;i<n+1;i++)
    //optimize
    for(int length=2;length<n+1;length++)
        for(int value=0;value<n/2+1;value++)
            //can either increase or decrease
            if(value+1<=n/2&&value-1>=0)
            A[length][value]=A[length-1][value+1]+A[length-1][value-1];
            //can only decrease
            else if (value+1<=n/2)
            A[length][value]=A[length-1][value+1];
            //can only increase
            else if (value-1>=0)
            A[length][value]=A[length-1][value-1];
            //no way
            else
            A[length][value]=0;
    //trace
    int length=n,digit=0,value=0,result[n];
    while(length>-1){
            if(value-1>=0&&value+1<=n/2)
            {
                if(p>A[length-1][value-1]&&A[length-1][value+1]!=0)
                    {result[length-1]=digit;digit++;value++;}
                else
                    {result[length-1]=digit;digit--;value--;}
            }
            else if (value+1>n/2)
                {result[length-1]=digit;digit--;value--;}
            else
                {result[length-1]=digit;digit++;value++;}
        length--;
    }
    //answer
    cout<<"Answer: ";
    for(int i=0;i<n;i++)
        cout<<result[i];
}
