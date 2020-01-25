#include<iostream>
using namespace std;
int A,B;
int factorial(int k)
{
   if(k==1)
        return 1;
   else
     return k*factorial(k-1);
}
int main(void)
{
    cin>>A>>B;
    if(A>B)
        cout<<factorial(B);
    else
        cout<<factorial(A);
}
