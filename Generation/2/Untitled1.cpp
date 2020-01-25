/*
    iterate all the binary sequence with the length of n and there are exactly two subsequences 01 in each sequence
*/
#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
void print(int a[],int n);
void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
int main(void)
{
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++)
        array[i]=0;
    /////problem when n==4;
    /////
    for(int firstStart=1;firstStart<=n-4;firstStart++){
        for(int secondStart=firstStart+2;secondStart<=n-2;secondStart++){
            ////
            for(int r=-1;r<firstStart-1;r++){
                if(r>-1)
                array[r]++;
                for(int i=firstStart;i<secondStart-1;i++){
                    array[i]++;
                    for(int j=secondStart;j<n;j++){
                        array[j]++;
                        print(array,n);
                        }
                    ////clear
                    for(int t=secondStart;t<n;t++)
                        array[t]=0;
                }
                ////clear
                for(int t=firstStart;t<n;t++)
                    array[t]=0;
            }
            ////clear
            for(int t=0;t<n;t++)
                array[t]=0;
        }
    }
}
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
