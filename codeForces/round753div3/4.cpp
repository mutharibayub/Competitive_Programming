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
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        string color;
        cin>>color;
        vector<int> blues, reds;
        for(int i=0;i<n;i++)
        {
            if(color[i]=='R')reds.push_back(arr[i]);
            else blues.push_back(arr[i]);
        }
        sort(reds.begin(), reds.end());
        sort(blues.begin(), blues.end());
        bool ok = true;
        for(int i=0;i<n&&ok;i++)
        {
            if(i<blues.size())
            {
                if(blues[i]<i+1)ok=false;
            }
            else
            {
                if(reds[i-blues.size()]>i+1)ok=false;
            }
        }
        cout << (ok?"YES":"NO") << '\n';
    }    

    return 0;
}