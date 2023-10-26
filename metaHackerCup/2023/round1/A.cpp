#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <array>
#include <set>
#include <iomanip>
using namespace std;

template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int tttt;
    cin>>tttt;
    for(int ttt=1;ttt<=tttt;ttt++)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr.begin(), arr.end());
        double ans = double();
        if(arr.size() == 5)
        {
            double a1 = double(arr[arr.size()-1]+arr[arr.size()-3])/2 - double(arr[1]+arr[0])/2;
            double a2 = double(arr[arr.size()-1]+arr[arr.size()-2])/2 - double(arr[2]+arr[0])/2;
            ans = max(a1, a2);
        }
        else
            ans = double(arr[arr.size()-1]+arr[arr.size()-2])/2 - double(arr[1]+arr[0])/2;
        cout << "Case #" << ttt << ": " << ans << '\n';
    }

    return 0;
}
