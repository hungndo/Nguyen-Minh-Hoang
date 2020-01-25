#include<iostream>
using namespace std;
in11t link[300], length[300], array[300],n;
void init()
{
    cin>>n;
    //// create infinity
    array[0]=-32768;
    array[n+1]=32768;
    for(int i=1;i<n+1;i++)
    {
        cin>>array[i];
    }
    length[n+1]=1;
}
void finding()
{
    for(int i=n;i>-1;i--)
    {
        int k=n+1;
        for(int j=i+1;j<n+2;j++)
            ////find the one that is bigger than itself and has the longest sequence.
            ////only take the bigger one, equal does not count.
            if(array[j]>array[i]&&length[j]>length[k])
                k=j;
        ////assign length and link.
        length[i]=length[k]+1;
        link[i]=k;
    }
}
void print()
{
    cout<<length[0]-2<<endl;
    int i=link[0];
    while(i!=n+1)
    {
        cout<<array[i]<<" ";
        i=link[i];
    }
}
int main(void)
{
    init();
    finding();
    print();
}
