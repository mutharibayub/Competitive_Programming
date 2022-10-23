#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<int> &arr, int64_t width, int k)
{
    int64_t covered = 0;
    int baskets = 0;
    for(int i=0;i<arr.size();i++)
    {
        if(covered<arr[i])
        {
            covered = arr[i]+width-1;
            baskets++;
            if(baskets>k)return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr.begin(), arr.end());
    int val = 1e9+7;
    int jump = 1e9+6;
    for(;jump;jump=jump>>1)
    {
        int a = 0;
        while(val-jump>0 && possible(arr, val-jump, k))val-=jump;
    }
    cout << val << '\n';

    return 0;
}