#include<iostream>
#include<stdio.h>
using namespace std;
bool doc[300],sac[300],huyen[300];
int array[300][300],n;
void init()
{
    cin>>n;
    for(int i=0;i<n*2;i++)
    {
        doc[i]=true;
        sac[i]=true;
        huyen[i]=true;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        array[i][j]=0;
}
void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<array[i][j];
        cout<<endl;
    }
    cout<<endl;
}
void xep(int k)
{
    for(int j=0;j<n;j++)
        {
            if(doc[j]&&sac[k+j]&&huyen[k-j+n-1])
            {
                array[k][j]=1;
                if(k==n-1)
                {
                    print();
                    array[k][j]=0;
                }
                else
                {
                doc[j]=false;sac[k+j]=false;huyen[k-j+n-1]=false;
                xep(k+1);
                array[k][j]=0;
                doc[j]=true;sac[k+j]=true;huyen[k-j+n-1]=true;
                }
            }
        }
    return;
}
int main(void)
{
    init();
    xep(0);

}

