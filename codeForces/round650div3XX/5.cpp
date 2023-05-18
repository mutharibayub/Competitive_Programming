#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        string s;
        cin>>n>>k>>s;
        int ans = 0;
        for(int i=n;i>=1;i--)
        {
            if(k%i==0)
            {
                ans = i;
                break;
            }
        }
        vector<int> cnts(26, 0);
        for(int i=0;i<n;i++)
        {
            cnts[s[i]-'a']++;
        }
        vector<int> divs;
        for(int i=1;i*i<=k;i++)
        {
            if(k%i==0)
            {
                divs.push_back(i);
                if(i*i!=k)divs.push_back(k/i);
            }
        }
        sort(divs.begin(), divs.end());
        for(int i=n;i>=1;i--)
        {
            int setSize=0;
            for(int j=0;j<26;j++)
            {
                setSize += cnts[j]/i;
            }
            if(setSize)setSize = *prev(upper_bound(divs.begin(), divs.end(), setSize));
            ans = max(ans, i*setSize);
        }
        cout << ans << '\n';
    }
    return 0;
}