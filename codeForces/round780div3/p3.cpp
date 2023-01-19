#include <iostream>
#include <vector>
using namespace std;

void testCase()
{
    string in;
    int tCount=0,curCount=0;
    bool needPair[26];
    for(int i=0;i<26;i++)needPair[i]=0;
    
    cin>>in;
    for(int i=0;in[i];i++)
    {
        if(needPair[in[i]-'a'])
        {
            for(int i=0;i<26;i++)
            {
                needPair[i]=0;
            }
            tCount+=curCount-1;
            curCount=0;
        }
        else
        {
            curCount++;
            needPair[in[i]-'a']=1;
        }
    }
    tCount+=curCount;
    cout<<tCount<<"\n";
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        testCase();
    }

    return 0;
}