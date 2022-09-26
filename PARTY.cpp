#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(1)
    {
        int budget, n;
        cin >> budget >> n;
        if(!budget && !n)break;
        vector<array<int,2>> arr(n);
        for(int i=0;i<n;i++)
        {
            cin >> arr[i][0] >> arr[i][1];
        }
        unordered_map<int,int> dp;
        dp[0] = 0;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int> tmp = dp;
            for(auto it:tmp)
            {
                if(it.first+arr[i][0] <= budget)
                {
                    dp[it.first+arr[i][0]] = max(dp[it.first+arr[i][0]], it.second + arr[i][1]);
                }
            }
        }
        array<int,2> maxFun={-1,-1};
        for(auto it:dp)
        {
            if(it.second > maxFun[1] || (it.second==maxFun[1] && it.first<maxFun[0]))
            {
                maxFun[0] = it.first;
                maxFun[1] = it.second;
            }
        }
        cout << maxFun[0] << ' ' << maxFun[1] << '\n';
    }
    return 0;
}