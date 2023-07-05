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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        if(arr.front()!=n&&arr.back()!=n)
        {
            cout << -1 << '\n';
            continue;
        }
        vector<int> left, right;
        int l=0, r=n-1;
        while(l<=r)
        {
            if(arr[l]<arr[r])
            {
                right.push_back(arr[r]);
                r--;
            }
            else
            {
                left.push_back(arr[l]);
                l++;
            }
        }
        reverse(left.begin(), left.end());
        for(int i=0;i<right.size();i++)
        {
            left.push_back(right[i]);
        }
        for(int i=0;i<left.size();i++)
        {
            if(i)cout << ' ';
            cout << left[i];
        }cout << '\n';
    }    

    return 0;
}