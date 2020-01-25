#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
    ifstream read;
    read.open("Input.txt");
    int n,total=0;
    read>>n;
    int a[n+1], b[n+1];
    for(int i=1;i<n+1;i++)
    {
        read>>a[i]>>b[i];
        total+=a[i]+b[i];
    }
    int maxCol=total/2;
    //
    int A[n+1][maxCol+1];
    for(int i=0;i<maxCol+1;i++)//set base
        A[0][i]=0;
    //
    for(int row=1;row<n+1;row++)
        for(int col=0;col<maxCol+1;col++)
        {
            if(col-a[row]>=0&&col-b[row]>=0){
                    if(A[row-1][col-a[row]]+a[row]>=A[row-1][col-b[row]]+b[row])
                        A[row][col]=A[row-1][col-a[row]]+a[row];
                    else
                        A[row][col]=A[row-1][col-b[row]]+b[row];
            }
            else if(col-a[row]>=0)
                A[row][col]=A[row-1][col-a[row]]+a[row];
            else if(col-b[row]>=0)
                A[row][col]=A[row-1][col-b[row]]+b[row];
            else
                A[row][col]=-maxCol*2;//set negative infinity
        }
    /*
    for(int row=1;row<n+1;row++){
        for(int col=0;col<maxCol+1;col++)
            cout<<A[row][col]<<" ";
        cout<<endl;}
    */
    int i=n,j=maxCol,numberOfSwitch=0;
    bool swit[n];
    while(i>0)
    {
            if(A[i][j]==A[i-1][j-a[i]]+a[i])
            {
                j-=a[i];swit[i]=false;i--;
            }
            else if(A[i][j]==A[i-1][j-b[i]]+b[i])
            {
                j-=b[i];i--;swit[i]=true;numberOfSwitch++;
            }
    }
    if(numberOfSwitch<n/2){
        for(int k=0;k<n;k++)
            if(swit[k])
                cout<<"Switch "<<k+1<<" : "<<b[k+1]<<" "<<a[k+1]<<endl;
            else
                cout<<"Don't switch "<<k+1<<" : "<<a[k+1]<<" "<<b[k+1]<<endl;
    }
    else{
        for(int k=0;k<n;k++)
            if(!swit[k])
                cout<<"Switch "<<k+1<<" : "<<b[k+1]<<" "<<a[k+1]<<endl;
            else
                cout<<"Don't switch "<<k+1<<" : "<<a[k+1]<<" "<<b[k+1]<<endl;
    }

    cout<<"Total top: "<<A[n][maxCol]<<endl;
    cout<<"Total bottom: "<<total-A[n][maxCol]<<endl;
}
