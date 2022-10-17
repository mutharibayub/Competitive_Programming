#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];

        vector<pair<int,int>> mn,mx;
        mn.reserve(n), mx.reserve(n);
        ll count = 0;
        for(int i=0;i<arr.size();i++)
        {
            int c = 0;
            while(mn.size() && mn.back().first<=arr[i])
            {
                c+=mn.back().second;
                mn.pop_back();
            }
            mn.emplace_back(arr[i], c+1);
            c = 0;
            while(mx.size() && mx.back().first>=arr[i])
            {
                c+=mx.back().second;
                mx.pop_back();
            }
            mx.emplace_back(arr[i], c+1);
            int a=mn.size()-1, b=mx.size()-1;
            int minC=mn[a].second,maxC=mx[b].second;
            while(a+1 && b+1)
            {
                int lessC = min(minC,maxC);
                if(mn[a].first>mx[b].first)
                {
                    count += (mn[a].first%mx[b].first)?0:lessC;
                }
                else
                {
                    count += (mx[b].first%mn[a].first)?0:lessC;
                }
                minC-=lessC;
                maxC-=lessC;
                if(!minC)
                {
                    a--;
                    if(a+1)minC = mn[a].second;
                }
                if(!maxC)
                {
                    b--;
                    if(b+1)maxC = mx[b].second;
                }
            }
        }
        cout << count << '\n';
    }

    return 0;
}