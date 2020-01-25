#include<iostream>
using namespace std;
int n,M, W[300],V[300], chart[300][300];
void init()
{
    cin>>n>>M;
    for(int i=1;i<n+1;i++)
        cin>>W[i]>>V[i];
    for(int i=0;i<M;i++)
        chart[0][i]=0;
}
void Optimize()
{
    for(int i=1;i<n+1;i++)
        for(int j=0;j<M+1;j++)
        {
            if(j>=W[i]&&chart[i-1][j]<V[i]+chart[i-1][j-W[i]])
                chart[i][j]=chart[i-1][j-W[i]]+V[i];
            else
                chart[i][j]=chart[i-1][j];
        }
}
void Trace()
{
    cout<<chart[n][M]<<endl;
    while (n!=0)
    {
        if (chart[n][M]!=chart[n-1][M])
        {
            cout<<n<<" ";
            M-=W[n];
        }
        n--;
    }
}
int main(void)
{
    init();
    Optimize();
    Trace();
}
