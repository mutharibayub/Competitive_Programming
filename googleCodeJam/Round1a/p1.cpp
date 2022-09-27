#include <iostream>
#include <vector>
#include <string>
using namespace std;

void testCase(const int& tCount)
{
    string s;
    cin>>s;
    vector<bool> rep(s.size(),0);
    for(int i=s.size()-2;i>=0;i--)
    {
        if(s[i]<s[i+1])
        {
            rep[i]=true;
        }
        else if(s[i]>s[i+1])
        {
            rep[i]=false;
        }
        else
        {
            rep[i]=rep[i+1];
        }
    }
    string out;
    for(int i=0;s[i];i++)
    {
        out.push_back(s[i]);
        if(rep[i])
        {
            out.push_back(s[i]);
        }
    }
    cout<<"Case #"+to_string(tCount)+": "<<out<<endl;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        testCase(i+1);
    }
    return 0;
}