#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        vector<array<int,3>> occurrences;
        string s,p;
        cin>>s>>p;
        for(int i=0;s[i];i++)
        {
            for(int j=0;p[j] && s[i+j];j++)
            {
                if(s[i+j]!=p[j])
                {
                    break;
                }
                else if(j+1==p.size())
                {
                    occurrences.push_back({i,-1,0});
                }
            }
        }
        if(occurrences.size()==0)
        {
            cout << "0 1\n";
            continue;
        }
        for(int i=0;i<occurrences.size();i++)
        {
            int oc1Start = occurrences[i][0];
            int oc1End = oc1Start + p.size()-1;
            for(int j=0;j<occurrences.size();j++)
            {
                int oc2Start = occurrences[j][0];
                int oc2End = oc2Start + p.size()-1;
                if(!(oc1End<oc2Start || oc1Start>oc2End))
                {
                    if(occurrences[i][1]==-1)occurrences[i][1]=j;
                    occurrences[i][2]++;
                }
            }
        }
        int finalPoint = occurrences.back()[0]+1;
        int minSteps = occurrences.size()-1;
        vector<vector<int64_t>> dp(occurrences.size()+1, vector<int64_t>(s.size()+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=occurrences.size();i++) //occurence to be added to dp
        {
            bool done = false;
            for(int j=0;s[j];j++)
            {
                if(!dp[i-1][j])continue;
                int firstOccurrence;
                for(int k=0;k<occurrences.size();k++)
                {
                    if(occurrences[k][0]>=j)
                    {
                        firstOccurrence=k;
                        break;
                    }
                }
                for(int k=firstOccurrence;k<occurrences.size();k++)
                {
                    if(occurrences[k][1]<=firstOccurrence)
                    {
                        if(occurrences[k][0]+p.size()>=finalPoint)
                        {
                            done = true;
                        }
                        dp[i][occurrences[k][0]+p.size()] += dp[i-1][j];
                    }
                }
            }
            if(done)
            {
                minSteps=i;
                break;
            }
        }
        int64_t ans=0;
        for(int i=finalPoint;i<s.size()+1;i++)
        {
            ans = (ans+dp[minSteps][i])%int(1e9+7);
        }
        cout << minSteps << ' ' << ans << '\n';
    }

    return 0;
}