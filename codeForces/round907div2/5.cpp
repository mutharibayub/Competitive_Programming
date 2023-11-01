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

int gcd(int a, int b)
{
    if(a<b)
        swap(a, b);
    if(!b)
        return a;
    return gcd(b, a%b);
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
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        
        multiset<int> onePatchCount;
        int len = 0;
        int sadness = 0;
        for(int i = 0; i <= n; i++)
        {
            if(i < n && arr[i] == 1)
            {
                len++;
            }
            else if(len)
            {
                int start = i - len;
                if(start == 0 || i == n)
                {
                    sadness += len;
                    len = 0;
                    continue;
                }
                onePatchCount.insert(len);
                sadness += len+1;
                len = 0;
            }
        }
        int bestFirst = 0;
        for(int i = 0; i < n; i++)
        {
            if(i < n - 1 && arr[i] != 1 && arr[i+1] != 1 && gcd(arr[i], arr[i+1]) == 1)
            {
                len++;
            }
            else if(len)
            {
                bestFirst += len/2;
                sadness += len;
                len = 0;
            }
        }   
        int sub = min(k, bestFirst);
        k -= sub;
        sadness -= 2*sub;
        if(k)
        {
            for(auto sz: onePatchCount)
            {
                if(k >= sz)
                {
                    sadness -= sz+1;
                    k -= sz;
                }
                else
                {
                    sadness -= k;
                    k = 0;
                    break;
                }
            }
            sadness -= k;
            k = 0;
        }
        cout << max(0, sadness) << '\n';
    }
    return 0;
}