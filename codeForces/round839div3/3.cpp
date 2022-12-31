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
        int k,n;
        cin>>k>>n;
        vector<int> ans;
        int diff = 1;
        int val = 1;
        for(int i=0;i<k;i++)
        {
            ans.push_back(val);
            val+=diff;
            diff++;
            if(val>n)break;
        }
        while(ans.size()<k&&ans.back()<n)ans.push_back(ans.back()+1);
        if(ans.size()<k)
        {
            int rq = k-ans.size();
            vector<int> toAdd;
            for(int i=ans.size()-1;i>0&&toAdd.size()<rq;i--)
            {
                diff = ans[i]-ans[i-1]-1;
                for(int j=0;j<diff&&toAdd.size()<rq;j++)
                {
                    toAdd.push_back(ans[i]-1-j);
                }
            }
            for(int i=0;i<toAdd.size();i++)
            {
                ans.push_back(toAdd[i]);
            }
        }
        sort(ans.begin(), ans.end());
        for(int i=0;i<k;i++)
        {
            if(i)cout << ' ';
            cout << ans[i];
        }cout << '\n';
    }

    return 0;
}