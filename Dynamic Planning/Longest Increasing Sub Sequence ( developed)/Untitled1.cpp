#include<iostream>
using namespace std;
int n,array[300],length[300],link[300],startOf[300],maxx;
////variable maxX and startOf is just used for binary search
void init()
{
    cin>>n;
    for(int i=1;i<n+1;i++)
        cin>>array[i];
    array[0]=-32768;
    array[n+1]=32768;
    length[n+1]=1;
    startOf[1]=n+1;
    maxx=1;
}

void result()
{
    cout<<maxx-2<<endl;
    ////start from the second link
    int i=link[startOf[maxx]];
    while(i!=n+1)
    {
        cout<<array[i]<<" ";
        i=link[i];
    }
}
int binarySearch(int i)
{
    int inf=1,sup=maxx+1,median;
    while((inf+1)!=sup)
    {
        median=(inf+sup)/2;
        if(array[startOf[median]]>array[i])
            inf=median;
        else
            sup=median;
    }
    return startOf[inf];
}
void finding()
{
    for(int i=n;i>-1;i--)
    {
        ////find the start of the longest sequence that is just bigger than array[i].
        int j=binarySearch(i);
        ////assign link and length
        length[i]=length[j]+1;
        link[i]=j;
        ////check if the new sequence is longer than max or not
        if(length[i]>maxx)
        {
            maxx=length[i];
            startOf[maxx]=i;
        }
        ////if there are two sequence that has the same length
        ////chose the one that has the bigger starting value
        else if (array[i]>array[startOf[length[i]]])
        {
            startOf[length[i]]=i;
        }
    }
}
int main(void)
{
    init();
    finding();
    result();
}
