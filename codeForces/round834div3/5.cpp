#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

typedef long long ll;

int calc(vector<ll> &arr, int index, ll power, int green, int blue)
{
    int eaten=0;
    for(;index<arr.size();index++)
    {
        if(power>arr[index])
        {
            power+=arr[index]/2;
            eaten++;
        }
        else
        {
            int tmp=0;
            if(green)tmp = max(tmp, calc(arr, index, power*2, green-1, blue));
            if(blue)tmp = max(tmp, calc(arr, index, power*3, green, blue-1));
            eaten += tmp;
            break;
        }
    }
    return eaten;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll h;
        cin>>n>>h;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        int ans = calc(arr, 0, h, 2, 1);
        cout << ans << '\n';
    }


    return 0;
}