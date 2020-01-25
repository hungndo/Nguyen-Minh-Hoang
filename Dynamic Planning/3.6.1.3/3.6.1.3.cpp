#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
    int n,M=0;
    ifstream read;
    read.open("Input.txt");
    read>>n;
    int bag[n+1];
    for(int i=1;i<n+1;i++)
        {read>>bag[i];
            M+=bag[i];
        }
    M=M/2;
    read.close();
    //  1st Way........................................
    /*
    int A[n+1][M+1];
    for(int i=0;i<M;i++)
        A[1][i]=0;
    A[1][M]=2;
    A[1][M-bag[1]]=1;
    //
    for(int row=2;row<n+1;row++)
        for(int col=0;col<M+1;col++)
        {
            //if pick
            if(A[row-1][col+bag[row]]>0&&col+bag[row]<M+1)
                A[row][col]=1;
            //if not pick
            else if (A[row-1][col]>0)
                A[row][col]=2;
            //no way
            else
                A[row][col]=0;
        }
    //find the won with lowest difference
    int i=-1,j;
    for(int col=0;col<M+1;col++)
    {
        for(int row=n;row>0;row--)
        if(A[row][col]>0)
        {
            i=row,j=col;
            break;
        }
        if(i!=-1)
            break;
    }
    //
    cout<<"For person A:"<<endl;
    M=0;
    while(i>0)
    {
        if(A[i][j]==1)
        {
            cout<<"Bag "<<i<<": "<<bag[i]<<endl;
            j+=bag[i];M+=bag[i];bag[i]=-1;i-=1;
        }
        else
            i-=1;
    }
    cout<<"Total: "<<M<<"."<<endl<<endl;
    M=0;
    cout<<"For person B:"<<endl;
    for(int i=1;i<n+1;i++)
        if(bag[i]!=-1)
        {
            cout<<"Bag "<<i<<": "<<bag[i]<<endl;
            M+=bag[i];
        }
    cout<<"Total: "<<M<<".";
    */
    // 2nd way.....................................................................
    /*
    int A[n+1][M+1];
    for(int i=0;i<M+1;i++)
        A[0][i]=0;
    for(int row=1;row<n+1;row++)
        for(int col=0;col<M+1;col++)
        {
            if(col>=bag[row]&&A[row-1][col-bag[row]]+bag[row]>A[row-1][col])
                A[row][col]=A[row-1][col-bag[row]]+bag[row];
            else
                A[row][col]=A[row-1][col];
        }
    //
    cout<<"For person A:"<<endl;
    int i=n,j=M;
    while(i>0)
    {
        if(A[i][j]==A[i-1][j-bag[i]]+bag[i])
        {
            cout<<"Bag "<<i<<": "<<bag[i]<<endl;
            j-=bag[i];bag[i]=-1;i-=1;
        }
        else
            i-=1;
    }
    cout<<"Total: "<<A[n][M]<<"."<<endl<<endl;
    M=0;
    cout<<"For person B:"<<endl;
    for(int i=1;i<n+1;i++)
        if(bag[i]!=-1)
        {
            cout<<"Bag "<<i<<": "<<bag[i]<<endl;
            M+=bag[i];
        }
    cout<<"Total: "<<M<<".";
    */
}
