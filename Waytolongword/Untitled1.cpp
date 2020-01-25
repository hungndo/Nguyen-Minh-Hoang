#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main (void)
{
    int n;
    ifstream doc;
    doc.open("input.txt");
    doc>>n;
    string word[n];
    for(int i=0;i<n;i++)
    doc>>word[i];
    doc.close();
    /////////////////////
    for(int i=0;i<n;i++)
    {
        if(word[i].length()>=11)
        {
            cout<<word[i][0]<<word[i].length()-2<<word[i][word[i].length()-1]<<endl;
        }
        else
        {
        cout<<word[i]<<endl;
        }
    }
}
