#include<iostream>
#include<fstream>
using namespace std;
#define MAX 3000
int array[300],n,k,chart[300][300],sumAll=0;

void init()
{
    ifstream doc;
    doc.open("Input.txt");
    doc>>n>>k;
    for(int i=0;i<n;i++)
        {
            doc>>array[i];
            sumAll+=array[i];
        }
    doc.close();
    //initialize the base
    chart[0][0]=0;
    for(int i=1;i<=k;i++)
        chart[0][i]=MAX;
}
//// subtract by module
int moduleSub(int a,int b,int key)
{
    int tmp=(a-b)%key;
    if (tmp>=0)
        return tmp;
    else return tmp+key;
}
void result()
{
    //length
    cout<<"Length: "<<n-chart[n][sumAll%k]<<endl;
    int sum=0;
    //trace back
    int j=sumAll%k;
    for(int i=n;i>0;i--)
    {
        if (chart[i][j]==chart[i-1][j])
        {
            cout<<"a["<<i<<"] = "<<array[i-1]<<endl;
            sum+=array[i-1];
        }
        else
            j=moduleSub(j,array[i-1],k);
    }
    //sum
        cout<<"Sum: "<<sum<<endl;
}

void optimize()
{
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++)
        {
            // find the lower
            if(chart[i-1][j]<=chart[i-1][moduleSub(j,array[i-1],k)]+1)
                //not choose
                chart[i][j]=chart[i-1][j];
            else
                //choose
                chart[i][j]=chart[i-1][moduleSub(j,array[i-1],k)]+1;
        }
}
int main(void)
{
    init();
    optimize();
    result();
}
