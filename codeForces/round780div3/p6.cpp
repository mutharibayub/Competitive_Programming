#include <iostream>
#include <vector>
using namespace std;

void testCase()
{
    int n,subsetCount=0;
    string s;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        int plusCount=0;
        int minusCount=0;
        int minusPair=0;
        bool lastMinus=false;
        for(int j=i;j<n;j++)
        {
            if(s[j]=='+')
            {
                plusCount++;
                lastMinus=false;
            }
            else if(s[j]=='-')
            {
                minusCount++;
                if(lastMinus)
                {
                    minusPair++;
                    lastMinus=false;
                }
                else
                {
                    lastMinus=true;
                }
            }
            // cout<<"MinusCount: "<<minusCount<<" _ plusCount: "<<plusCount<<" _ minusPair: "<<minusPair<<"\n";
            if(minusCount>=plusCount && (minusCount-plusCount)%3==0)
            {
                subsetCount++;
            }
        }
    }    
    cout<<subsetCount<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false); 
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