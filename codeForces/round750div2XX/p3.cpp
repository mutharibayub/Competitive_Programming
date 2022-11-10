#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool checkPossible(const string& s, char deleted, int& count)
{
    int ptr1=0,ptr2=s.size()-1;
    while(ptr1<ptr2)
    {
        if(s[ptr1]!=s[ptr2])
        {
            if(s[ptr1]== deleted)
            {
                ptr1++;
                count++;
            }
            else if(s[ptr2]==deleted)
            {
                ptr2--;
                count++;
            }
            else
            {
                return false;
            }
        }
        else
        {
            ptr1++;
            ptr2--;
        }
    }
    return true;
}

void testCase()
{
    int n,count;
    cin>>n;
    string s;
    cin>>s;
    int ans=1e9+7;
    for(char c='a';c<='z';c++)
    {
        count=0;
        if(checkPossible(s,c,count))
        {
            ans=min(ans,count);
        }
    }
    if(ans==1e9+7)
    {
        cout<<"-1\n";
    }
    else
    {
        cout<<ans<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // int count=0;
    // cout<<checkPossible("ebebbbebbb",'e',count)<<"\n";
    // cout<<count<<"\n";
    // return 0;

    int n;
    cin>>n;
    while(n--)
    {
        testCase();
    }

    return 0;
}