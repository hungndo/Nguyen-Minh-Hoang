#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
    fstream read;
    read.open("Input.txt");
    int n,k,total=0;
    read>>n>>k;
    int A[n];
    for(int i=0;i<n;i++)
        {read>>A[i];total+=A[i];}
    read.close();
    //
    int H[n][2*total+1];
    for(int i=0;i<2*total+1;i++)
        H[0][i]=0;
    H[0][total+A[0]]=1;
    //
    for(int row=1;row<n;row++)
        for(int col=0;col<2*total+1;col++)
        {
            if(H[row-1][col-A[row]]!=0)
                H[row][col]=1;
            else if(H[row-1][col+A[row]]!=0)
                H[row][col]=-1;
            else
                H[row][col]=0;
        }
    //
    /*for(int i=0;i<n;i++){
        for(int j=0;j<2*total+1;j++)
            cout<<H[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<A[0]<<" ";
    for(int i=1;i<n;i++)
    cout<<"? "<<A[i]<<" ";
    cout<<"= "<<k<<endl<<endl;
    char sign[n];
    int t=n-1,j=k+total;
    if(H[n-1][j]==0)
        cout<<"No way!";
    else{
        while(t>0)
        {
            if(H[t][j]==1)
            {sign[t]='+';j-=A[t];}
            else
            {sign[t]='-';j+=A[t];}
            t--;
        }
        cout<<A[0]<<" ";
        for(int i=1;i<n;i++)
        cout<<sign[i]<<" "<<A[i]<<" ";
        cout<<"= "<<k;
    }
}
