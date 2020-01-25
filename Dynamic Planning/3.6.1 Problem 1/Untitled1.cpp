/* Enter two positive integer n and k ( n,k<=100)
How many positive integer with that has <=n digits have the sum of all digits equals to k.
If there are more than 1 billion number, announce that it has more than 1 billion*/
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;
int n,k;
string key;
long long f[300][300];
int findKey();
int anotherFindKey();
void init()
{
    ifstream read;
    read.open("Input.txt");
    read>>n>>k>>key;
    read.close();
    f[0][0]=1;
}
int lengthfunction(int number)
{
      int counter=0;
      while(number)
     {
            number=number/10;
            counter++;
      }
      return (counter);
}
void result()
{
    cout<<"Number: ";
    if(f[n][k]<=1000000000)
        cout<<f[n][k];
    else
        cout<<"More than 1 billion.";
    cout<<endl;
    cout<<findKey()<<endl;
    cout<<anotherFindKey()<<endl;
}
void optimize()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++)
            if(j<=9*i)
                {
                    for(int t=0;t<10;t++)
                        if(t<=j)
                        {
                            f[i][j]+=f[i-1][j-t];
                            if(f[i][j]>1000000000)
                                f[i][j]=1000000001;
                        }
                        else
                            break;
                }
            else
                f[i][j]=0;
}
int powerofTen(int a)
{
    if(a==0)
        return 1;
    else
        return 10*powerofTen(a-1);
}
//// wrong one
int findKey()
{
    int len=key.length(),place=0,index=0,anotherK=k;
    while(len>0)
    {
        int firstDigit=key[index]-48;
        place+=f[len-1][anotherK-firstDigit];
        len--;index++;anotherK-=firstDigit;
    }
    return place+1;
}
////true one
int anotherFindKey()
{
    int len=key.length(),place=0,index=0,anotherK=k;
    while(len>0)
    {
        int firstDigit=key[index]-48;
        // count all the number before key based on the first digit.
        for(int i=0;i<firstDigit;i++)
            {place+=f[len-1][anotherK-i];}
        len--;index++;anotherK-=firstDigit;
    }

    return place+1;
}
int main (void)
{
    init();
    optimize();
    result();
}
