#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>

using namespace std;

typedef long long ll;

string PI = "314159265358979323846264338327";

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(), arr.end());

        vector<pair<int, int>> cntArr;
        for(int i=0;i<n;i++)
        {
            if(cntArr.empty()||cntArr.back().first!=arr[i])
            {
                cntArr.push_back({arr[i], 1});
            }
            else
            {
                cntArr.back().second++;
            }
        }
        int ans = 0;
        for(int i=0;i<cntArr.size();i++)
        {
            if(cntArr[i].second==0)continue;
            ans++;
            cntArr[i].second--;
            int j=i+1;
            while(cntArr[j].second>0&&cntArr[j].first-1==cntArr[j-1].first)
            {
                cntArr[j++].second--;
            }
            if(cntArr[i].second)i--;
        }
        cout << ans << '\n';
    }    

    return 0;
}