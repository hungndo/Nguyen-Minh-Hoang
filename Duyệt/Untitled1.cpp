#include<stdio.h>
#include<iostream>
using namespace std;
string a="ABCDEFGHIJKL";
void visit(int x)
{
    if(x<a.size())
    {cout<<a[x];
    visit(2*x+1);
    visit(2*x+2);}
}
int main(void)
{
    visit(0);
}
