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
#include <limits>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(auto &ele: arr) {
            cin >> ele;
        }
        int maxSum = arr.front();
        int curSum = arr.front();
        for(int i = 1; i < n; i++) {
            if(abs(arr[i]%2) == abs(arr[i-1]%2) || curSum + arr[i] < arr[i]) {
                curSum = arr[i];
            } else {
                curSum += arr[i];
            }
            maxSum = max(maxSum, curSum);
        }
        cout << maxSum << '\n';
    }
    return 0;
}