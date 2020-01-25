#include<iostream>
using namespace std;
int main(void)
{
    // input
    int numberOfTypes,price;
    cin>>numberOfTypes>>price;
    int value[numberOfTypes];
    int min=10001;
    for(int i=0;i<numberOfTypes;i++)
        {
            cin>>value[i];
            if(value[i]<min)
             min=value[i];
        }
    ////initialize trace
    int numberOfBill=price/min; //the maximum number of bill can be use
    int trace[numberOfBill+1][price+1];
    for(int i=0;i<=numberOfBill;i++)
        for(int j=0;j<=price;j++)
            trace[i][j]=0;
    //
    // optimize
    for(int t=0;t<numberOfTypes;t++)
    {
        //calculate ways to purchase the price in the order of bill's value type
        //ex.. calculate ways to purchase by only using value[0]
        // then .... by only using value[0] + value[1];
        //set base
        trace[1][value[t]]=1;
        for(int i=2;i<=numberOfBill;i++)
        for(int j=1;j<=price;j++)
        {
            if(j-value[t]>=0)
                {
                    trace[i][j]+=trace[i-1][j-value[t]];
                    if(trace[i][j]>1000000000)
                        {
                        trace[i][j]=-1;
                        break;
                        }
                }
        }
        // just to keep track
        for(int e=0;e<=numberOfBill;e++){
    for(int r=0;r<=price;r++)
            cout<<trace[e][r]<<" ";
            cout<<endl;
    }
    cout<<endl;
    }
    // find total number of ways by adding ways to purchase the price by each number of bills
    int finalNumber=0;
    for(int i=1;i<=numberOfBill;i++){
        if(trace[i][price]==-1)
        {
            finalNumber=-1;
            break;
        }
        else
        finalNumber+=trace[i][price];
    }
    // print
    for(int i=0;i<=numberOfBill;i++){
    for(int j=0;j<=price;j++)
            cout<<trace[i][j]<<" ";
            cout<<endl;
    }
    cout<<finalNumber;
}
