#include<iostream>
#include<fstream>
using namespace std;
string X,Y;
char answer[300];
int number,key=-1;

void init()
{
    ifstream read;
    read.open("input.txt");
    read>>X>>Y;
    read.close();

}
void result()
{
    cout<<number<<endl;
}
int findMin(int a,int b,int c)
{
    key++;
    ////set default
    int tmp=b;
    ////
    if(a<b)
    {
        tmp=a;
    }
    if(tmp<c)
        return tmp;
    else
    {
        return c;
    }
}
int modifying(int indexX,int indexY)
{

    while(X[indexX]==Y[indexY]&&indexX>-1&&indexY>-1)
    {
        indexX--;indexY--;
    }
    if(indexX==-1)
        return indexY+1;
    else if(indexY==-1)
        return indexX+1;
    else if(indexX==-1&&indexX==-1)
        return 0;
    else
        return findMin(modifying(indexX-1,indexY),modifying(indexX-1,indexY-1),modifying(indexX,indexY-1))+1;

}
int main (void)
{
    init();
    number=modifying(X.length()-1,Y.length()-1);
    result();
}
