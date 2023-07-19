#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

const int MOD = 1e9+7;

ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=o*n%MOD;
        e/=2;
        n=n*n%MOD;
    }return o;
}

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

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
        vector<array<int,2>> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i][0], arr[i][1]=i;
        minPQ<array<int, 2>> pq;
        for(int i=0;i<k;i++)pq.push({0, i});
        sort(arr.begin(), arr.end());
        vector<int> ans(n, -1);
        vector<int> colorCount(k, 0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(i&&arr[i][0]!=arr[i-1][0])cnt=0;
            if(cnt<k)
            {
                auto top = pq.top();
                pq.pop();
                top[0]++;
                ans[arr[i][1]]=top[1];
                pq.push(top);
                colorCount[top[1]]++;
            }
            cnt++;
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]!=-1 && colorCount[ans[i]]>pq.top()[0])
            {
                colorCount[ans[i]]--;
                ans[i]=-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << ans[i]+1;
        }cout << '\n';
    }    

    return 0;
}