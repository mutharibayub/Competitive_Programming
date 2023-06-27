#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, k;
    cin>>n>>m>>k;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    
    ll mxCount=-1;
    ll mxVal=-1;
    sort(arr.begin(), arr.end());
    for(int i=0;i<n;i++)
    {
        int start=i, end=i;
        while(end+1<n&&arr[end+1]==arr[start])end++;
        int prev=start?arr[start-1]:-10, next=end+1<n?arr[end+1]:arr[end]+10;
        int curCount = end-start+1;
        if(curCount>=k)continue;
        ll rightEdge1, rightEdge2, leftEdge1, leftEdge2;
        if() 

    }

    return 0;
}