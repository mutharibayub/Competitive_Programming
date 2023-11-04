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
    // cin>>tttt;
    while(tttt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> in(n, 0);
        for(int i = 1; i < n ; i++) {
            cin >> arr[i];
            if (i) 
                arr[i] ^= arr[i-1];
            if(arr[i] < n)
                in[arr[i]]=1;
        }
        vector<int> options = {0};
        vector<int> count(31, 0), cur_count(31, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 30; j >= 0; j--) {
                count[j]+=(i>>j)&1;
                if(i>0)
                    cur_count[j]+=(arr[i]>>j)&1;
            }
        }
        for(int j = 30; j >= 0; j--) {
            if (cur_count[j] != count[j]) {
                assert(n - cur_count[j] == count[j]);
                for(int &num: options) {
                    num ^= (1<<j);
                }
            }
            else if (n - cur_count[j] == count[j]) {
                vector<int> tmp = options;
                for(int num: tmp) {
                    options.push_back(num^(1<<j));
                }
            }
        }
        bool found = false;
        for(int option: options) {
            found = true;
            vector<int> done(n, 0);
            arr[0] = option;
            done[option] = 1;
            for(int i = 1; i < n; i++) {
                int tmp = arr[i]^arr[0];
                if(tmp >= n || done[tmp]) {
                    found = false;
                    break;
                } 
                done[tmp] = true;
            }
            if(found) {
                arr[0] = option;
                break;
            }
        }
        cout << arr[0] << ' ';
        for(int i = 1; i < n; i++) {
            arr[i] ^= arr[0];
            cout << arr[i] << " \n"[i==n-1];
        }
    }
    return 0;
}