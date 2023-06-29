#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <limits>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <array>

using namespace std;

int main() {

    int n,x,y;
    cin>>n>>x>>y;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    if(x>y)cout << n << '\n';
    else
    {
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            cnt += (arr[i]<=x);
        }
        cout << (cnt+1)/2 << '\n';
    }

    return 0;
}