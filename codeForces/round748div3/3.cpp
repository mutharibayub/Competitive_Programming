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
        vector<int> arr(k);
        for(int i=0;i<k;i++)cin>>arr[i];
        sort(arr.begin(), arr.end());
        int ans=0;
        int sm=0;
        for(int i=k-1;i>=0;i--)
        {
            if(sm+(n-arr[i])>=n)break;
            ans++;
            sm+=(n-arr[i]);
        }
        cout << ans << '\n';
    }    
 
    return 0;
}