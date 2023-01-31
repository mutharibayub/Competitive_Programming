#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

bool compString(const string &s1, char ignore, const string &s2)
{
    int ptr1=0;
    for(int i=0;s2[i];i++)
    {
        while(ptr1<s1.size()&&s1[ptr1]==ignore)ptr1++;
        if(s1[ptr1]!=s2[i])return false;
        ptr1++;
    }
    while(ptr1<s1.size()&&s1[ptr1]==ignore)ptr1++;
    return ptr1==s1.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector<char> order;
        int cnts[26],oneCnt[26];
        for(int i=0;i<26;i++)cnts[i]=oneCnt[i]=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(!cnts[s[i]-'a']++)order.push_back(s[i]);
        }
        reverse(order.begin(),order.end());
        bool ok=true;
        int val=1;
        int baseCnt=0;
        string ans;
        for(auto chr:order)
        {
            oneCnt[chr-'a']=cnts[chr-'a']/val;
            ok=cnts[chr-'a']%val==0;
            if(!ok)break;
            val++;
            baseCnt+=oneCnt[chr-'a'];
        }
        if(ok)ans=s.substr(0,baseCnt);
        string lastString=ans;
        int start=baseCnt;
        for(int i=0;i+1<order.size()&&ok;i++)
        {
            baseCnt-=oneCnt[order[i]-'a'];
            int nextStart=start+baseCnt;
            string thisString="";
            if(nextStart>s.size()||i+2==order.size()&&nextStart!=s.size())ok=false;
            if(ok)
            {
                thisString=s.substr(start, nextStart-start);
                if(!compString(lastString, order[i], thisString))ok=false;
            }
            start=nextStart;
            lastString=thisString;
        }
        if(!ok)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << ans << ' ';
            for(int i=0;i<order.size();i++)
            {
                cout << order[i];
            }cout << '\n';
        }
    }

    return 0;
}