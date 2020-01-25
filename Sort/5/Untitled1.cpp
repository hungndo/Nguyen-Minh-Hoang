#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
typedef struct
{
    string name;
    int score;
}
hocsinh;
hocsinh stu[150];
int n,index[300];
void init()
{
    cin>>n;
    for(int i=0;i<n;i++)
        {
            index[i]=i;
            cin>>stu[i].name>> stu[i].score;
        }
}
void swap(int *a,int *b)
{
    int tmp= *a;
    *a=*b;
    *b=tmp;
}
void adjust(int root,int endnode)
{
    int c;int key=stu[index[root]].score, tmp=index[root];
    while(root*2+1<=endnode)
    {
        c=root*2+1;
        if(stu[index[c]].score>stu[index[c+1]].score&&c<endnode)
        c++;
        if(stu[index[c]].score>key)
        break;
        index[root]=index[c];root=c;
    }
    index[root]=tmp;
}
void print()
{
    for(int i=0;i<n;i++)
        cout<<i+1<<"."<<stu[index[i]].name<<" "<<stu[index[i]].score<<endl;
}
void heapsort()
{
    for(int i=(n-1)/2;i>-1;i--)
        adjust(i,n-1);
    for(int i=n-1;i>0;i--)
    {
        swap(index[0],index[i]);
        adjust(0,i-1);
    }
}
int main(void)
{
    init();
    heapsort();
    print();
}
