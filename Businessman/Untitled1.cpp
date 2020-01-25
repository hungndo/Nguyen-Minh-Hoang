#include<iostream>
#include<stdio.h>
using namespace std;
int n,numberofstreet,fee[300][300],cheapest=0,path[300],bestpath[300];
bool city[300];
void init()
{
    cin>>n>>numberofstreet;
    ////every cities is true except the first one
    city[0]=false;
    for(int i=1;i<n;i++)
        city[i]=true;
    for(int i=0;i<numberofstreet;i++)
    {
        int x,y;
        cin>>x>>y;
        cin>>fee[x-1][y-1];
        cheapest+=fee[x-1][y-1];
        ////The fees of both ways are the same
        fee[y-1][x-1]=fee[x-1][y-1];
    }
    ////initialize the cheapest
    cheapest+=fee[n-1][0];
    path[0]=1;
}
void travel(int citynumber,int attempt)
{
    for(int i=1;i<n;i++)
        if(city[i])
        {
            ///////Check if this attempt is still cheaper than the cheapest or not
            if(attempt+fee[path[citynumber-1]-1][i]>cheapest)
                break;
            ///////Record the path
            path[citynumber]=i+1;
            ///////If this is still not the one before the last city
            if(citynumber!=n-1)
            {
                city[i]=false;
                travel(citynumber+1,attempt+fee[path[citynumber-1]-1][i]);
                city[i]=true;
            }
            ///////If this is the last one && still the cheapest when it is added the fee to return to the 1st city
            else if (attempt+fee[path[citynumber-1]-1][i]+fee[i][0]<cheapest)
            {
                for(int j=0;j<n;j++)
                    bestpath[j]=path[j];
                cheapest=attempt+fee[path[citynumber-1]-1][i]+fee[path[i]-1][0];
            }
        }
}

int main(void)
{
    init();
    travel(1,0);
    ////print
    for (int i=0;i<n;i++)
        cout<<bestpath[i]<<" -> ";
    cout<<"1"<<endl;
    cout<<"Cost: "<<cheapest;
}
