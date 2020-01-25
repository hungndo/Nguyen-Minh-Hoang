#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
int n,M;
int main(void)
{
    ifstream read;
    read.open("Input.txt");
    read>>n>>M;
    /*int bag[n+1];
    for(int i=0;i<n;i++)
        read>>bag[i];
    read.close();
    ////
    /* MY WAY________________________________________
    ////
    int A[n][M];
    for(int i=0;i<M;i++)
        A[0][i]=0;
    A[0][bag[0]-1]=1;
    //check if there is way
    for(int row=1;row<n;row++)
        for(int col=0;col<M;col++)
    {
        // pick item row
       if(col-bag[row]>=0&&A[row-1][col-bag[row]]>0)
            A[row][col]=1;
        // not pick item row
       else if (A[row-1][col]>0)
            A[row][col]=2;
       // no way
       else
        A[row][col]=0;
    }
        for(int i=0;i<n;i++){
        for(int j=0;j<M;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    ////trace

    if(A[n-1][M-1]>0){
        int i=n-1,j=M-1;
        while(j>-1){
            //if pick
            if(A[i][j]==1)
            {
                cout<<"Bag "<<i+1<<": "<<bag[i]<<endl;
                j-=bag[i];i-=1;
            }
            //if not pick
            else
            {
               i-=1;
            }
        }
    }
    ///
    /* NMH way-------------------------------
    int bag[n+1];
    for(int i=1;i<n+1;i++)
        read>>bag[i];
    read.close();
    int A[M+1];
    A[0]=0;
    A[M+1]=10000;
    for(int i=1;i<M+1;i++)
    {   A[i]=i;
        for(int k=n;k>-1;k--)
            if(bag[k]<=i&&A[i-bag[k]]<A[i])
                A[i]=k;

    }
    for(int i=0;i<M+1;i++)
        cout<<A[i];
        */
}
