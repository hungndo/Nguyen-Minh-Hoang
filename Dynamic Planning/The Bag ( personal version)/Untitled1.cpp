#include<iostream>
using namespace std;
int valueMax=0,W[300],V[300],bestList[300],Wmax,numberOfPick,n,array[300];;
bool flag[300];
void init()
{
    cin>>n>>Wmax;
    for(int i=0;i<n;i++)
    {
        cin>>W[i]>>V[i];
        flag[i]=true;
    }
}
void result()
{
    cout<<valueMax<<endl;
    for(int i=0;i<numberOfPick;i++)
        cout<<bestList[i]+1<<" ";
}
void combination(int pick, int total, int k, int value, int weight)
{
    for(int i=0;i<total;i++)
        ////if the bag hasn't been picked and the total weight is still small enough
        if(flag[i]&&weight+W[i]<=Wmax)
        {
            ////still not the last pick
            if (k<pick)
            {
                array[k-1]=i;
                flag[i]=false;
                combination(pick,total,k+1,value+V[i],weight+W[i]);
                flag[i]=true;
            }
            ////last pick
            else
            {
                array[k-1]=i;
            //// if this gives better bestList
                if (value+V[i]>valueMax)
                {
                    valueMax= value+V[i];
                    ////record to print
                    numberOfPick=pick;
                    ////copy
                    ////still try to learn to return an array from a function.
                    for(int i=0;i<pick;i++)
                        bestList[i]=array[i];
                }
            }
        }
}
int main(void)
{
    init();
    //// try different number of picks
    for(int i=1;i<n+1;i++)
        {
            combination(i,n,1,0,0);
            ////reset flags
            for(int j=0;j<n;j++)
                flag[j]=true;
        }
    result();
}

