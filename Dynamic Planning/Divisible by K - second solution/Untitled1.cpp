#include<iostream>
#include<fstream>
using namespace std;
int n,k,array[300],f[300][300],Trace[300][300],Count[300];
void init()
{
    ifstream read;
    read.open("Input.txt");
    read>>n>>k;
    for(int i=0;i<k;i++)
        {
            Count[i]=0;
            f[0][i]=-1;
        }
    for(int i=0;i<n;i++)
        {
            read>>array[i];
            Count[array[i]%k]++;
        }
    f[0][0]=Count[0];
    Trace[0][0]=Count[0];
    read.close();
}
int moduleSub(int a, int b,int key)
{
    int tmp=(a-b)%key;
    if(tmp>=0)
        return tmp;
    else
        return tmp+key;
}
void optimize()
{
    for(int i=1;i<=n;i++)
        for(int t=0;t<k;t++)
            ////find the most number in group i as possible
            for(int j=0;j<=Count[i];j++)
                //if Trace ( there is way to take j number of group i )
                //find the greatest f[i][t]
                if(Trace[i-1][moduleSub(t,j*i,k)]!=-1&&f[i][t]<f[i-1][moduleSub(t,j*i,k)]+j)
                {
                    ////save
                    f[i][t]=f[i-1][moduleSub(t,j*i,k)]+j;
                    Trace[i][t] = j;
                }
}
void result()
{
    cout<<"Length: "<<f[k-1][0]<<endl;
    ////start to trace back
    // starts from t, the final remaining which is 0
    int t=0;
    //Count[i] now is the number of choice in group i.
    for(int i=k-1;i>-1;i--)
    {
        //Trace[i][t] is what we found in optimizing
        int j=Trace[i][t];
        // take away j members of group i
        t=moduleSub(t,j*i,k);
        //new count
        Count[i]=j;
    }
    int sum=0;
    //check all number in array
    for(int i=0;i<n;i++)
    {
        int tmp=array[i]%k;
        if(Count[tmp]>0)
        {
            cout<<array[i]<<endl;
            sum+=array[i];
            Count[tmp]--;
        }
    }
    cout<<"Sum: "<<sum;
}
int main(void)
{
    init();
    optimize();
    result();

}
