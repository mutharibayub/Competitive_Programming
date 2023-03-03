#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int wc;
    cin>>wc;
    vector<string> wds(wc);
    for(int i=0;i<wc;i++)cin>>wds[i];
    map<pair<int,int>,int> counts;
    for(int i=0;i<wc;i++)
    {
        int mask=0;
        vector<bool> in(26,false);
        for(int j=0;j<wds[i].size();j++)
        {
            mask^=(1<<(wds[i][j]-'a'));
            in[wds[i][j]-'a']=true;
        }
        for(int j=0;j<26;j++)
        {
            if(!in[j])counts[{mask,j}]++;
        }
    }
    ll ans = 0;
    for(int i=0;i<wc;i++)
    {
        int mask=0;
        vector<bool> in(26,false);
        for(int j=0;j<wds[i].size();j++)
        {
            mask^=(1<<(wds[i][j]-'a'));
            in[wds[i][j]-'a']=true;
        }
        int invMask=((1<<26)-1)^mask;
        for(int j=0;j<26;j++)
        {
            if(!in[j])
            {
                int tmpMask = invMask^(1<<j);
                ans+=counts[{tmpMask,j}];
            }
        }
    }   
    ans/=2;
    cout << ans << '\n';



    return 0;
}