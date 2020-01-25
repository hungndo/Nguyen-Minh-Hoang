#include<iostream>
using namespace std;
#include<fstream>
int chart[300][300],lenA;
string A,B;
void init()
{
    ifstream doc;
    doc.open("Input.txt");
    doc>>A>>B;
    doc.close();
    lenA=A.length();
    for(int i=0;i<=lenA;i++)
        {chart[i][0]=i;
        }
        int lenB=B.length();
    for(int i=0;i<=lenB;i++)
        {chart[0][i]=i;
        }

}
////because A's length changes;
void printA()
{
    for(int k=0;k<lenA;k++)
        cout<<A[k];
}
int findMin(int a,int b,int c)
{
    int tmp=a;
    if(tmp>b)
        tmp=b;
    if(tmp>c)
        tmp=c;
    return tmp;
}
void optimize(int nA,int nB)
{
    //because chart's index is the length of each string, therefore , it should be counted to nA and nB instead of nA-1 and nB-1
    for(int i=1;i<=nA;i++)
        for(int j=1;j<=nB;j++)
        {
            if(B[j-1]==A[i-1])
                ////if there is no need to change
                chart[i][j]=chart[i-1][j-1];
            else
                ////find the best best way in three to go
                chart[i][j]=findMin(chart[i-1][j],chart[i-1][j-1],chart[i][j-1])+1;
        }
}
void result()
{
    cout<<chart[A.length()][B.length()]<<endl;
    ////print steps
    int i=A.length(),j=B.length();
    while(i!=0 ||j!=0)
    {
        ////if it doesn't need any change
        if(A[i-1]==B[j-1])
        {
            i--;j--;
        }
        ////if it needs change
        else
        {
            for(int k=0;k<lenA;k++)
                cout<<A[k];
            cout<< " -> ";
            ////delete
            if(chart[i][j]==chart[i-1][j]+1&&i-1>-1)
            {
                for(int k=i-1;k<lenA-1;k++)
                    A[k]=A[k+1];
                    lenA--;
                cout<<"Delete ";
                printA();
                cout<<endl;
                i--;
            }
            ////replace
            else if(chart[i][j]==chart[i-1][j-1]+1&&i-1>-1&&j-1>-1)
            {
                A[i-1]=B[j-1];
                cout<<"Replace "<<A<<endl;
                i--;j--;
            }
            ////insert
            else if (j-1>-1)
            {
                for(int k=lenA+1;k>i;k--)
                    A[k]=A[k-1];
                A[i]=B[j-1];
                lenA++;
                cout<<"Insert ";
                printA();
                cout<<endl;
                j--;
            }
        }
    }
}
int main(void)
{
    init();
    optimize(A.length(),B.length());
    result();
}
