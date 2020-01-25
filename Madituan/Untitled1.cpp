#include<iostream>
#include<stdio.h>
using namespace std;
bool crit[300][300],stop=false;
int array[300][300],n,a[]={-2,-2,-1,-1,1,1,2,2},b[]={-1,1,-2,2,-2,2,-1,1};
void init()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        crit[i][j]=true;
}
void print()
{
    for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++)
        {
            if(array[i][j]<10)
            cout<<array[i][j]<<"    ";
            else
            cout<<array[i][j]<<"   ";
        }
        cout<<endl<<endl;
       }
    cout<<endl;
}
void path(int row,int column,int k)
{
    if(stop)
        return;
    ////if the move is not in the map or the spot is used
    else if((row>=n&&row<=-1&&column>=n&&column<=-1)||!crit[row][column])
        return;
    ////the last spot
    else if(k==n*n&&crit[row][column])
    {
        array[row][column]=k;stop=true;
        print();
    }
    ////if the spot has not been used yet
    else
    {
        ////record the step
        array[row][column]=k;
        crit[row][column]=false;
        ////choose next step
        for(int i=0;i<8;i++)
            {
                path(row+a[i],column+b[i],k+1);
            }
        ////delete the record
        crit[row][column]=true;
        array[row][column]=0;
    }


}

int main(void)
{
    init();
    path(0,0,1);
}
