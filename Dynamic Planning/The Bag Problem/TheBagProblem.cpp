#include<iostream>
#include<fstream>
using namespace std;
int numberOfGoods, maximumWeight;
int main(void)
{
    //init
    ifstream read;
    read.open("input.txt");
    int numberOfGoods,maximumWeight;
    read>>numberOfGoods>>maximumWeight;
    int weight[numberOfGoods+1], price[numberOfGoods+1];
    for(int i=1;i<numberOfGoods+1;i++)
        {
            read>>weight[i]>>price[i];
        }
    read.close();
    //
    int priceTrace[numberOfGoods+1][maximumWeight+1];
    for(int i=0;i<maximumWeight+1;i++)
        priceTrace[0][i]=0;
    for(int i=0;i<numberOfGoods+1;i++)
        priceTrace[i][0]=0;
    //
    for(int g=1;g<numberOfGoods+1;g++)
        for(int w=1;w<maximumWeight+1;w++)
        {
            if(w-weight[g]>=0&&priceTrace[g-1][w-weight[g]]+price[g]>priceTrace[g-1][w])
                priceTrace[g][w]=priceTrace[g-1][w-weight[g]]+price[g];
            else
                priceTrace[g][w]=priceTrace[g-1][w];
        }
    //
    int tmp=maximumWeight;
    for(int g=numberOfGoods;g>0;g--)
    {
        if(priceTrace[g][tmp]==priceTrace[g-1][tmp-weight[g]]+price[g])
        {
            cout<<g<<endl;
            tmp-=weight[g];
        }
    }
    cout<<priceTrace[numberOfGoods][maximumWeight];
}
