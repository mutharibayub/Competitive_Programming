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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(), arr.end());
        map<int,int> cnt;
        int mxCount = 0;
        for(int i=0;i<2*k;i++)
        {
            mxCount = max(mxCount, ++cnt[arr[n-i-1]]);
        }
        int score = mxCount>2*k-mxCount?(2*mxCount-2*k)/2:0;
        for(int i=0;i+2*k<n;i++)
        {
            score += arr[i];
        }
        cout << score << '\n';
    }    

    return 0;
}